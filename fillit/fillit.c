/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/30 19:04:40 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct	square_grid
{
	int		side;
	char	**array;
}				grid;

typedef struct	grid_location
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

typedef struct	tetromino
{
	int		order;
	int		value;
	struct grid_location *origin;
	struct grid_location *second;
	struct grid_location *third;
}				tet;
unsigned short int	*read_and_validate_tets(int argc, char **argv)
{
	char				*unvalidated_tetromino_set;
	char				*valid_tetromino_set;
	char				**tetrominos;
	unsigned short int	*encoded_tetrominos;
	
	if(argc != 2)
		error(-6);
		encoded_tetrominos = 0;
	unvalidated_tetromino_set = read_tetromino_set(argv[1]);
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
		error(-5);
		encoded_tetrominos = 0;
	tetrominos = get_individual_tetrominos(valid_tetromino_set);
	tetrominos = validate_tetrominos(tetrominos);
	if(!tetrominos)
		error(-8);
		encoded_tetrominos = 0;
	if(!(encoded_tetrominos = encode_tetrominos(tetrominos)))
		error(-10);	
		encoded_tetrominos = 0;
	return (encoded_tetrominos);
}
int		main(int argc, char **argv)
{
	unsigned short int	*tet_codes;

	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
	}
	ft_putendl("It works");
	return (0);
}
