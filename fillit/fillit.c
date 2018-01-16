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
int			solve(t_board *board)
{
	if (reject(board))
	{
		expand_board(board);
	}
	if (accept(board))
	{
		return (board);
	}
	board = first(board);
	while (baord)
	{
		solve(board);
		board = next(board);
	}
}
*/

t_board		*generate_board(t_ets *tets, int expansion)
{
	//int i;
	t_board *board;
	board = board_alloc(tets, expansion);
	return(board);
}

t_board		*root(t_ets *tets)
{
	t_board *board;
	board = generate_board(tets, 0);
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
	board = root(tets);
	print_board(board, 1);
	/*
	while(!(solve(board)))
	{
		board = expand_board(board);
	};
	*/
	ft_putendl("It works");
	return (0);
}
