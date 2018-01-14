/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		int_sqrt(int y, int x)
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

int		min_size_given(int n)
{
	if(n != 1)
	{
		return (int_sqrt(0, n * 4));
	}
	return (2);
}
/*
int			solve(t_board *board)
{
	if (not_possible_solution(board))
	{
		return (NULL);
	}
	if (is_solution(board))
	{
		return (board);
	}
	board = place_next_tet(board);
	while (baord != NULL)
	{
		solve(board);
		board = translate_last_tet(board);
	}
}
*/
void		print_board(t_board *board)
{
	int size;
	int i;
	t_point *tmp;

	size = board->size;
	i = -1;
	tmp = board->origin;
	while (tmp && ++i <= (size * size))
	{
		if(tmp->x >= 0 && tmp->x <= size)
		{
			ft_putchar('[');
			ft_putnbr(tmp->x);
			ft_putchar(',');
			ft_putchar(' ');
			ft_putnbr(tmp->y);
			ft_putchar(']');

			if (i % size == 0 && i != 0 && i != size * size - 1)
			{
				ft_putchar('\n');
			}
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

t_point		*push_point_tail(t_board *board, t_point *previous, int x_coord, int y_coord)
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


t_board		*generate_board(t_ets *tets, int expansion)
{
	t_board *board;
	board = board_alloc(tets, expansion);
	return(board);
}

int			main(int argc, char **argv)
{
	unsigned short int	*tet_codes;
	t_ets				*tets;
	t_board				*board;
	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	tets = prepare_for_placement(tet_codes);
	print_tet_set(tets);
	board = generate_board(tets, 0);
	print_board(board);
	/*
	while(!(solve(board)))
	{
		board = expand_board(board);
	};
	*/
	ft_putendl("It works");
	return (0);
}
