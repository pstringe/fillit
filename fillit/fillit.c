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
	if(y * y >= x)
	{
		return (y);
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
	x = 0;
	while(++x < size)
	{
		y = -1;
		while(++y < (size * size))
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
		if (i % size == 0 && i != 0 && i != size)
		{
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('.');
		}
		tmp = tmp->next;
	}
}

int			solve(unsigned short int *tet_codes)
{
	t_tet		**tets;
	t_board 	*board;	

	tets = prepare_for_placement(tet_codes);
	board = generate_board(tets, min_size_given(tets));
	print_board(board);
	return(1);
}

int			main(int argc, char **argv)
{
	unsigned short int	*tet_codes;

	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	solve(tet_codes);
	ft_putendl("It works");
	return (0);
}
