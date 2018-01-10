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


int		solve(unsigned short int *tet_codes)
{
	t_tet		**tets;
	//t_board 	*board;
	
	tets = prepare_for_placement(tet_codes);
	while(*tets)
	{
		print_encoded_tetromino((*tets)->value);
		tets++;
	}
	//generate_board(tets, size);
	//print_board(board);
	return(1);
}

int		main(int argc, char **argv)
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
