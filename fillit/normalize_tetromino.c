/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tetromino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:08:24 by ralee             #+#    #+#             */
/*   Updated: 2018/01/02 17:50:46 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_move_up(char *tetrominos)
{
	int		i;

	i = 0;
	while (tetrominos[i] && i <= 3)
	{
		if (tetrominos[i] != '.')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	can_move_left(char *tetrominos)
{
	int		i;

	i = 0;
	while (tetrominos[i] && i <= 15)
	{
		if (tetrominos[i] != '.')
		{
			return (0);
		}
		i = i + 4;
	}
	return (1);
}

static void	move_top(char **tetrominos)
{
	int		i;

	while (can_move_up(*tetrominos))
	{
		i = 0;
		while (tetrominos[0][i])
		{
			if (tetrominos[0][i] != '.')
			{
				tetrominos[0][i - 4] = tetrominos[0][i];
				tetrominos[0][i] = '.';
			}
			i++;
		}
	}
}

static void	move_left(char **tetrominos)
{
	int		i;

	while (can_move_left(*tetrominos))
	{
		i = 0;
		while (tetrominos[0][i])
		{
			if (tetrominos[0][i] != '.')
			{
				tetrominos[0][i - 1] = tetrominos[0][i];
				tetrominos[0][i] = '.';
			}
			i++;
		}
	}
}

char		**normalize_tetrominos(char **tetrominos)
{
	int i;

	i = 0;
	while (*(tetrominos + i))
	{
		move_left(&tetrominos[i]);
		move_top(&tetrominos[i]);
		i++;
	}
	return (tetrominos);
}
