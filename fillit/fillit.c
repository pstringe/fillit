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
int		main(int argc, char **argv)
{
	unsigned short int	*tet_codes;

	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	ft_putendl("It works");
	return (0);
}
