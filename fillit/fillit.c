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

typedef struct	s_grid_location
{
	int						x;
	int						y;
	int						value;
	int						parent;
	struct grid_location	*prev;
	struct grid_location	*next;
	struct grid_location	*up;
	struct grid_location	*down;
	struct grid_location	*right;
	struct grid_location	*left;
}				point;

typedef struct	s_tetromino
{
	int						order;
	int						value;
	struct grid_location	*origin;
	struct grid_location	*second;
	struct grid_location	*third;
	struct grid_location	*fourth;
}				t_tet;

typedef struct	s_board
{
	int						validity;
	int						size;
	unsigned short int		*tets;
	struct grid_location	*origin;
}				t_board;

t_tet	*initialize_spatial_tet(unsigned short int code, int order)
{
	t_tet	*tet;
	tet = malloc(sizeof(t_tet*));
	tet->order = order;
	tet->value = code;
	tet->origin = NULL;
	tet->second = NULL;
	tet->third	= NULL;
	tet->fourth = NULL;
	return (tet);
}

t_tet	**prepare_for_placement(unsigned short int *tet_codes)
{
	t_tet **spatial_tets;
	
	int	i;

	i = 0;
	while(tet_codes[i++])
	{
		
	}
	spatial_tets = malloc(sizeof(t_tet*) * i + 1);
	i = -1;
	while(tet_codes[++i])
	{
		*(spatial_tets + i) = initialize_spatial_tet(tet_codes[i], i);
	}
	spatial_tets[i] = NULL;
	return (spatial_tets);
}

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
