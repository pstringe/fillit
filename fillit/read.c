/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:38:21 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/15 18:47:10 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *	counts a monomino's adjacent monominos
 */
static int			adj(char *str, int i)
{
	int		top;
	int		bottom;
	int		left;
	int		right;

	//ft_putstr("mon");

	top = (str[i - 4]) ? i - 4 : 0;
	bottom = (str[i + 4]) ? i + 4 : 0;
	right = (i + 1) % 4 ? i + 1: -1;
	left = (i % 4) ? i - 1: -1;

	top = (str[top] == '#') ? 1: 0;
	bottom = (str[bottom] == '#') ? 1: 0;
	right = (right >= 0 && str[right] == '#') ? 1: 0;
	left = ( left >= 0 && str[left] == '#') ? 1: 0;

	/*
	ft_putchar('\n');
	ft_putnbr(top);
	ft_putchar('\n');
	ft_putnbr(bottom);
	ft_putchar('\n');
	ft_putnbr(left);
	ft_putchar('\n');
	ft_putnbr(right);
	ft_putchar('\n');
	*/
	return (top + bottom + right + left);
}

/*
 * validates an individual chunk
 */
static char		*validate(char **str)
{
	int		i;
	int		count;
	char	*tet;
	int		a;
		
	tet = malloc(17);
	tet[17] = '\0';
	while(*str)
	{
		tet = ft_strjoin(tet, *str);
		str++;
	}
	a = 0;
	count = 0;
	i = -1;
	while (++i < TET)
	{
		if (str[i] && !(tet[i] == '.' || tet[i] == '#'))
			return (0);
		else if (tet[i] == '#')
		{
			a += adj(tet, i);
			count++;
		}
	}
	return (count == 4 && (a == 6 || a == 8)) ? tet : NULL;
}

/*
 * defines x and y boundries for tet
 */
t_et		*bind(t_et *tet)
{
	char	*str;
	int		x;
	int		y;
	int 	i;
	
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
	return(tet);
}

/*
 * creates a tet and pushes it onto the list
 */
static t_et	*make_tet(char *str)
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
 * reads and validates the file one chunck at a time
 */
t_board		*read_and_validate(char *file)
{
	char	*tet;
	int		bytes;
	int		fd;
	t_list	*tets;
	char	buf[PIECE + 1];
	
	tets = NULL;
	fd = open(file, O_RDONLY);
	while((bytes = read(fd, buf, PIECE)) >= PIECE - 1)
	{
		if(bytes == PIECE)
			buf[PIECE] = '\0';
		else if(bytes == PIECE - 1)
			buf[PIECE - 1] = '\0';
		if (!(tet = normalize(validate(ft_strsplit(buf, '\n')))))
		{
			error(2);
			return((t_board*)NULL);
		}
		else
		{
			ft_lstadd_tail(&tets, ft_lstnew(bind(make_tet(tet)), sizeof(t_et)));
		}
	}
	return(root(tets, 0));
}
