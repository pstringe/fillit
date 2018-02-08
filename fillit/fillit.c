/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/07 16:48:39 by pstringe         ###   ########.fr       */
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
void		push_tet(t_et **head, char *tet)
{
	static int		order;
	t_et			*tet;
	
	tet = malloc(sizeof(t_et));
	tet->label = order + 65;
	tet->placed = 0;
	tet->value = value;
	tet->next = (*head);
	tet->prev = NULL;
	*head = tet; 
}
/*
 * calculates cieling of sqrt
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


int			calc_minsize(int n)
{
	if(n != 1)
	{
		return (ft_sqrt(0, n * 4));
	}
	return (2);
}

 */
/*
 * generates a board based on the number of tets and the expansion
t_board		root(t_et **head, int exp)
{
	t_board	*board;	
	int 	min_size;
	char	**map;
	int		i;
	int		j;

	min_size = calc_minsize(no_of_tets);
	board = malloc(sizeof(t_board));
	map = malloc(sizeof(char*) * min_size + 1);
	i = -1;
	while (++i < min_size)
	{
		j = -1;
		map[i] = malloc(min_size + 1);
		while (++j < min_size)
		{
			map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	map[i] = NULL;
	board->size = min_size;
	board->stack = tets;
	board->map = board;
	return(board);
}

 */
/*
 * reads and validates the file one chunck at a time
 */
void/*t_board		*/read_and_validate(char *file)
{
	char	*tet;
	int		bytes;
	int		fd;
	t_et	**head;
	char	buf[PIECE + 1];


	head = NULL;
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
			//return(NULL);
		}
		else
		{
			ft_putendl(tet);		
			push_tet(head, tet);
		}
	}
	/*
	while((*head)->prev)
	{
		head = &((*head)->prev);
	}
	return(root(head, 0));
	*/
}


int			main(int argc, char **argv)
{
	//t_board		*board;

	if(argc != 2)
		return (error(1));
	//else if (!(board = read_and_validate(argv[1])))
	//	return (error(2));
	read_and_validate(argv[1]);
	return (0);
}
