/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/29 18:50:37 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_valid_number_of_monominos(char *tetromino)
{
	if(!tetromino)
	{
		return (0);
	}
	return(1);
}

static int		is_neighbor(char *tetromino, int i)
{
	if (!(tetromino + i))
	{
		return (0);
	}
	if (i >= 0 && i < 16 && tetromino[i] != '.')
	{
		return (1);
	}
	return (0);
}
static int		get_number_of_neighbors(char *tetromino, int i)
{
	int *coords;
	int neighbors;
	int x;
	int y;
	int left;
	int right;
	int up;
	int down;

	coords = access_second_dimension(4, i);
	x = coords[0];
	y = coords[1];

	right = access_first_dimension(4, y, x - 1);
	left = access_first_dimension(4, y, x + 1);
	up = access_first_dimension(4, y - 1, x);
	down = access_first_dimension(4, y + 1, x);
	neighbors = 0;
	/*check surrounding indecies right*/
	if (is_neighbor(tetromino, right))
	{
		neighbors++;
	}
	if (is_neighbor(tetromino, left))
	{
		neighbors++;
	}
	if (is_neighbor(tetromino, up))
	{
		neighbors++;
	}
	if (is_neighbor(tetromino, down))
	{
		neighbors++;
	}
	return (neighbors);
}

static int		has_valid_number_of_connections(char *tetromino)
{
	int i;
	int neighbors;

	if(!tetromino)
	{
		return (0);
	}
	i = -1;
	neighbors = 0;
	while (tetromino[++i])
	{
		if(neighbors >= 6)
		{
			return (1);
		}
		else if (tetromino[i] != '.')
		{
			neighbors += get_number_of_neighbors(tetromino, i);
		}
	}
	if (neighbors >= 6)
	{
		return(1);
	}
	return (error(-9));
}

static int		is_valid_tetromino (char *tetromino)
{
	if(!tetromino)
	{
		return (0);
	}
	if(has_valid_number_of_monominos(tetromino) && has_valid_number_of_connections(tetromino) > 0)
	{
		return (1);
	}
	return (0);
}

char	**validate_tetrominos(char **tetrominos)
{
	int i;

	i = 0;
	/*here lies the issue*/
	while (*(tetrominos + i))
	/*********************/
	{
		if(!is_valid_tetromino(tetrominos[i]))
		{
			return(NULL);
		}
        i++;
	}
	return (tetrominos);
}

int		main(int argc, char **argv)
{
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	char	**tetrominos;

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
	ft_putendl("It works");	
	return (0);
}
