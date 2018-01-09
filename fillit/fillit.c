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

typedef struct square_grid
{
	int		side;
	char	**array;
}				grid;
typedef struct	grid_location
{
	int	x;
	int	y;
}				point;
typedef			tetromino
{
	int			order;
	int			value;
}				tet;

int		main(int argc, char **argv)
{
	char				*unvalidated_tetromino_set;
	char				*valid_tetromino_set;
	char				**tetrominos;
	unsigned short int	*encoded_tetrominos;
	tet					**tets;

	if(argc != 2)
	{
		return (error(-6));
	}
	unvalidated_tetromino_set = read_tetromino_set(argv[1]);
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		return(error(-5));
	}
	tetrominos = get_individual_tetrominos(valid_tetromino_set);
	/*validate the tetrominos according to number of omminos and connections*/
	tetrominos = validate_tetrominos(tetrominos);
	if(!tetrominos)
	{
		return(error(-8));
	}
	if(!(encoded_tetrominos = encode_tetrominos(tetrominos)))
	{
		return(error(-10));
	}
	tets = prepare_for_placement(encoded_tetrominos);
	ft_putendl("It works");
	return (0);
}
