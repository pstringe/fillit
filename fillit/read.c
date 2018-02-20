/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:30:30 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/19 16:32:49 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** counts a monomino's adjacent monominos
*/

static int			adj(char *str, int i)
{
	int		top;
	int		bottom;
	int		left;
	int		right;

	top = (str[i - 4]) ? i - 4 : 0;
	bottom = (str[i + 4]) ? i + 4 : 0;
	right = (i + 1) % 4 ? i + 1 : -1;
	left = (i % 4) ? i - 1 : -1;
	top = (str[top] == '#') ? 1 : 0;
	bottom = (str[bottom] == '#') ? 1 : 0;
	right = (right >= 0 && str[right] == '#') ? 1 : 0;
	left = (left >= 0 && str[left] == '#') ? 1 : 0;
	return (top + bottom + right + left);
}

/*
** validates an individual chunk
*/

static char			*validate(char **str)
{
	int		i;
	int		count;
	char	*tet;
	int		a;

	i = -1;
	tet = ft_strnew(17);
	while (str[++i])
	{
		tet = ft_strjoin(tet, str[i]);
		if (ft_strlen(tet) != (size_t)((i + 1) * 4) || (!str[i + 1] && i < 3))
			return (NULL);
	}
	a = 0;
	count = 0;
	i = -1;
	while (++i < TET)
	{
		if (str[i] && !(tet[i] == '.' || tet[i] == '#'))
			return (NULL);
		else if (tet[i] == '#')
		{
			a += adj(tet, i);
			count++;
		}
	}
	return (count == 4 && a >= 6) ? tet : NULL;
}

/*
** defines x and y boundries for tet
*/

t_et				*bind(t_et *tet)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	str = (tet->value);
	x = 0;
	y = 0;
	i = -1;
	while (++i < 16)
	{
		x = (str[i] == '#' && i % 4 > x) ? i % 4 : x;
		y = (str[i] == '#' && i / 4 > y) ? i / 4 : y;
	}
	tet->bound_x = x;
	tet->bound_y = y;
	return (tet);
}

/*
** creates a tet and pushes it onto the list
*/

static t_et			*make_tet(char *str)
{
	static int		order;
	t_et			*tet;

	tet = ft_memalloc(sizeof(t_et));
	tet->label = order + 65;
	tet->placed = 0;
	tet->value = str;
	order++;
	return (tet);
}

/*
** reads and validates the file one chunck at a time
*/

t_board				*read_and_validate(char *file)
{
	char	*tet;
	int		bytes;
	int		fd;
	t_list	*tets;
	char	buf[PIECE + 1];

	tets = NULL;
	fd = open(file, O_RDONLY);
	while ((bytes = read(fd, buf, PIECE)) >= PIECE - 1)
	{
		if (bytes == PIECE)
			buf[PIECE] = '\0';
		else if (bytes == PIECE - 1)
			buf[PIECE - 1] = '\0';
		if (!(tet = normalize(validate(ft_strsplit(buf, '\n')))))
			return ((t_board*)NULL);
		else
			ft_lstadd_tail(&tets, ft_lstnew(bind(make_tet(tet)), sizeof(t_et)));
	}
	return (tets && !(bytes < PIECE - 1 && bytes != 0)
			&& ft_strlen(buf) == PIECE - 1) ? root(tets, 0) : NULL;
}
