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
