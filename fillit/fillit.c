/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/08 17:35:15 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define	PIECE	21
#define	TET		16

/*
 *	counts a monomino's adjacent monominos
 */
int			adj(char *str, int i)
{
	int		top;
	int		bottom;
	int		left;
	int		right;

	top = (str[i - 4]) ? i - 4 : 0;
	bottom = (str[i + 4]) ? i + 4 : 0;
	right = (str[i + 1] && !(i % 4 || (i + 1) % 4)) ? i + 1: 0;
	left = (str[i - 1] && !(i % 4 || (i + 1) % 4)) ? i - 1: 0;

	return ((str[top] == '#') + (str[bottom] == '#') + 
			(str[right] == '#') + (str[left] == '#'));
}

/*
 * validates an individual chunk
 */
char		*validate(char **str)
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
 * creates a tet and pushes it onto the list
 */
t_et	*make_tet(char *str)
{
	static int		order;
	t_et			*tet;
	
	tet = ft_memalloc(sizeof(t_et));
	tet->label = order + 65;
	tet->placed = 0;
	tet->value = str;
	return (tet);
}

/*
 * calculates cieling of sqrt
 */
int		ft_sqrt(int y, int x)
{
	if ( y * y >= x)
	{
		return (y);
	}
	else
	{
		return (ft_sqrt(++y, x));
	}
}

int			calc_minsize(t_list *tets)
{
	t_list	*tmp;
	int 	n;
	
	tmp = tets;
	n = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		n++;
	} 
	if(n != 1)
	{
		return (ft_sqrt(0, n * 4));
	}
	return (2);
}

/*
 * generates a board based on the number of tets and the expansion
 */
t_board		*root(t_list *tets, int exp)
{
	t_board	*board;	
	int 	min_size;
	char	**map;
	int		i;
	int		j;

	min_size = calc_minsize(tets);
	board = ft_memalloc(sizeof(t_board));
	map = ft_memalloc(sizeof(char*) * min_size + exp + 1);
	i = -1;
	while (++i < min_size + exp)
	{
		j = -1;
		map[i] = ft_strnew(min_size + exp + 1);
		while (++j < min_size + exp)
		{
			map[i][j] = '.';
		}
	}
	map[i] = NULL;
	board->size = min_size;
	board->stack = tets;
	board->map = map;
	return(board);
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
	
	tets = ft_lstnew(NULL, sizeof(t_et*));
	fd = open(file, O_RDONLY);
	while((bytes = read(fd, buf, PIECE)) >= PIECE - 1)
	{
		if(bytes == PIECE)
			buf[PIECE] = '\0';
		else if(bytes == PIECE - 1)
			buf[PIECE - 1] = '\0';
		if (!(tet = validate(ft_strsplit(buf, '\n'))))
		{
			error(2);
			return((t_board*)NULL);
		}
		else
		{
			ft_putendl(tet);		
			ft_lstadd(&tets, ft_lstnew(make_tet(tet), sizeof(void *)));
		}
	}
	return(root(tets, 0));
}

void		print_map(t_board *board)
{
	int i;

	i = -1;
	while((board->map)[++i])
	{
		ft_putendl((board->map)[i]);
	}
}

int			main(int argc, char **argv)
{
	t_board		*board;

	if(argc != 2)
		return (error(1));
	//else if (!(board = read_and_validate(argv[1])))
	//	return (error(2));
	board = read_and_validate(argv[1]);
	print_map(board);
	return (0);
}
