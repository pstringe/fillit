/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:08:48 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/16 19:13:16 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * places a tet once it is determined that it can fit
 */
static t_board		*place_tet(t_board *board, t_et *tet, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while ((board->map)[y + i] && i < 4)
	{
		j = 0;
		while ((board->map)[y + i][x + j] && j < 4)
		{
			if((tet->value)[(i * 4) + j] == '#')
			{
				board->map[i + y][j + x] = tet->label;
			}
			j++;
		}
		i++;	
	}
	return (board);
}

/*
 * checks that a tet can fit in a position before it is placed to avoid segfaults
 */
static int			try_tet(t_board *board, t_et *tet, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while ((board->map)[y + i] && i < 4)
	{
		j = 0;
		while ((board->map)[y + i][x + j] && j < 4)
		{
			if ((board->map)[y + i][x + j] != '.' &&
				(tet->value)[(i * 4) + j] != '.')
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * clears the tet when it is determined that the current solution can't be completed
 */
static void	clear_tet(t_board *board, t_et tet)
{
	int i;
	int j;

	i = -1;
	while ((board->map)[++i])
	{
		j = -1;
		while((board->map[i][++j]))
		{
			if((board->map)[i][j] == (tet.label) - 1)
			{
				(board->map)[i][j] = '.';
			}
		}
	}
}

/*
 * trys to resolve a board given the tets
 */
static int		resolve(t_board *board, t_list *lst)
{
	int		x;
	int		y;
	t_et	tet;
	
	if (!lst)
	{
		return (1);
	}
	tet = (*(t_et*)(lst->content)); 
	y = -1;
	while (++y <=  board->size - 1 - tet.bound_y)
	{
		x = -1;
		while (++x <= board->size - 1 - tet.bound_x)
		{
			if (try_tet(board, &tet, x, y))
			{
				place_tet(board, &tet, x, y);
				print_map(board);
				if(resolve(board, lst->next))
					return(1);
			}
		}
	}
	clear_tet(board, tet);
	return (0);
}

/*
 * starts ssolving at the minimum size board
 */
t_board	*solve(t_board *board)
{
	t_list *tets;

	tets = *(board->stack);
	while (!resolve(board, *(board->stack)))
	{
		board = root(tets, board->exp + 1);
	}
	return (NULL);
}
