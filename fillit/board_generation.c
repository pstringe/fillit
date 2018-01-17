/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_generation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:57:51 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/17 10:37:22 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		int_sqrt(int y, int x)
{
	if ( y * y >= x)
	{
		return (y);
	}
	else
	{
		return (int_sqrt(++y, x));
	}
}

static int		min_size_given(int n)
{
	if(n != 1)
	{
		return (int_sqrt(0, n * 4));
	}
	return (2);
}

void		print_board(t_board *board, int mode)
{
	int size;
	int i;
	t_point *tmp;

	if(!board)
	{
		return ;
	}

	size = board->size;
	i = -1;
	tmp = board->origin;
	while (tmp && ++i <= (size * size))
	{
		if((tmp->x >= 0 && tmp->x <= size) && (tmp->y >= 0 && tmp->y <= size))
		{
			if (mode == 0)
			{
				ft_putchar('[');
				ft_putnbr(tmp->x);
				ft_putchar(',');
				ft_putchar(' ');
				ft_putnbr(tmp->y);
				ft_putchar(']');
			}
			if (mode == 1)
			{
				if (tmp->parent)
				{
					ft_putchar(tmp->parent->order + 65);
				}
				else
				{
					ft_putchar('.');
				}
			}
			if (i % size == 0 && i != 0 && i != size * size - 1)
			{
				ft_putchar('\n');
			}
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static t_point		*push_point_tail(t_board *board, t_point *previous, int x_coord, int y_coord)
{
	t_point *new;

	new = malloc(sizeof(t_point));
	new->order = access_first_dimension(board->size, x_coord, y_coord);
	new->x = x_coord;
	new->y = y_coord;
	new->prev = previous;
	new->next = NULL;
	if(previous)
	{
		previous->next = new;
	}
	return(new);
}


t_board		*board_alloc(t_ets *tets, int exp)
{
	t_board *board;
	t_point *tmp;

	int		x;
	int		y;

	board = malloc(sizeof(t_board*));
	board->origin = push_point_tail(board, NULL, 0, 0);
	board->tets = tets;
	board->expansion = exp;
	board->size = min_size_given(tets->no_of_tets) + exp;
	tmp = board->origin;

	y = -1;
	while (++y < board->size)
	{
		if (y == 0)
		{
			x = 0;
		}
		x = -1;
		while(++x < board->size)
		{
			tmp = push_point_tail(board, tmp, x, y);
		}
	}
	return (board);
}


