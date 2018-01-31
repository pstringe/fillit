/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetrominos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:00:45 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/30 17:31:41 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_valid_number_of_monominos(char *tetromino)
{
	int monominos;
	if(!tetromino)
	{
		return (0);
	}
	monominos = 0;
	while(*tetromino)
	{
		if(*tetromino != '.')
		{
			monominos++;
		}
		tetromino++;
	}
	if (monominos == 4)
	{
		return (1);
	}
	return (0);
}
/*
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
*/
/*
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

	left = access_first_dimension(4, y, x - 1);
	right = access_first_dimension(4, y, x + 1);
	up = access_first_dimension(4, y - 1, x);
	down = access_first_dimension(4, y + 1, x);
	neighbors = 0;
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
*/

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
		if (tetromino[i] != '.')
		{
			if ((i + 1) < 20 && tetromino[i + 1] != '.')
			{
				neighbors++;
			}
			if ((i - 1) >= 0 && tetromino[i + 1] != '.')
			{
				neighbors++;
			}
			if ((i + 5) < 20 && tetromino[i + 5] != '.')
			{
				neighbors++;
			}
			if ((i - 5) >= 0 && tetromino[i - 5] != '.')
			{
				neighbors++;
			}
		}
	}
	return	(neighbors == 6 || neighbors == 8);
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
	while (*(tetrominos + i))
	{
		if(!is_valid_tetromino(tetrominos[i]))
		{
			return(NULL);
		}
        i++;
	}
	return (tetrominos);
}
