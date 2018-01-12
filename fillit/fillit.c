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
/*
int		int_sqrt(int y, int x)
{
	if(y * y == x)
	{
		return (y);
	}
	else if ( y * y > x)
	{
		return (y - 1);
	}
	else
	{
		return (int_sqrt(++y, x));
	}
}

int		min_size_given(t_tet **tets)
{
	int no_of_tets;

	no_of_tets = 0;
	while (*tets)
	{
		tets++;
		no_of_tets++;
	}
	if(no_of_tets != 1)
	{
		return (int_sqrt(0, no_of_tets * 4));
	}
	return (2);
}

t_point		*push_point_tail(t_board *board, t_point *previous, int x_coord, int y_coord)
{
	t_point *new;

	new = malloc(sizeof(t_point));
	new->order = access_first_dimension(board->size, y_coord, x_coord);
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

t_board		*board_alloc(int size, t_tet **tets)
{
	int		x;
	int		y;
	t_point *tmp;
	t_board *board;

	board = malloc(sizeof(t_board*));
	board->validity = 1;
	board->size = size;
	board->tets = tets;
	board->origin = push_point_tail(board, NULL, 0, 0);
	tmp = board->origin;
	x = -1;
	while(++x < size)
	{
		y = -1;
		while(++y < size)
		{
			tmp = push_point_tail(board, tmp, x, y);
		}
	}
	return (board);
}

t_board		*generate_board(t_tet **tets, int size)
{
	t_board *board;
	board = board_alloc(size, tets);
	return(board);
}

void		print_board(t_board *board)
{
	int size;
	int i;
	t_point *tmp;

	size = board->size;
	i = -1;
	tmp = board->origin;
	while (tmp && ++i < (size * size))
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
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

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
void		print_tet_set(t_ets *tetrs)
{
	int i;
	ft_putstr("head:\t");
	ft_putnbr(tetrs->head);
	ft_putendl("\n");
	ft_putstr("no_of_tets:\t");
	ft_putnbr(tetrs->no_of_tets);
	ft_putendl("\n");

	i = -1;
	while(tetrs->tets[++i])
	{
		print_encoded_tetromino(tetrs->tets[i]->value);
	}
}

int			main(int argc, char **argv)
{
	unsigned short int	*tet_codes;
	//t_board				*board;
	t_ets				*tets;

	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	tets = prepare_for_placement(tet_codes);
	print_tet_set(tets);
	/*
	board = generate_board(tets);
	while(!(solve(board)))
	{
		board = expand_board(board);
	};
	*/
	ft_putendl("It works");
	return (0);
}
