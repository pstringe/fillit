/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:44:13 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/15 19:08:52 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * calculates cieling of sqrt
 */
static int		ft_sqrt(int y, int x)
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

/*
 * gets minimum size based on the number of tets
 */
static int			calc_minsize(t_list *tets)
{
	t_list	*tmp;
	int 	n;
	
	tmp = tets;
	n = -1;
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
	board->size = min_size + exp;
	board->stack = &tets;
	board->map = map;
	board->exp = exp;
	return(board);
}
