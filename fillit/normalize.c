/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:08:24 by ralee             #+#    #+#             */
/*   Updated: 2018/02/08 18:33:22 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_move_up(char *tet)
{
	int		i;

	i = 0;
	while (tet[i] && i <= 3)
	{
		if (tet[i] != '.')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	can_move_left(char *tet)
{
	int		i;

	i = 0;
	while (tet[i] && i <= 15)
	{
		if (tet[i] != '.')
		{
			return (0);
		}
		i = i + 4;
	}
	return (1);
}

static void	move_top(char **tet)
{
	int		i;

	while (can_move_up(*tet))
	{
		i = 0;
		while (tet[i])
		{
			if (tet[i] != '.')
			{
				tet[i - 4] = tet[i];
				tet[i] = '.';
			}
			i++;
		}
	}
}

static void	move_left(char *tet)
{
	int		i;

	while (can_move_left(tet))
	{
		i = 0;
		while (tet[i])
		{
			if (tet[i] != '.')
			{
				tet[i - 1] = tet[i];
				tet[i] = '.';
			}
			i++;
		}
	}
}

char		*normalize(char *tet)
{
	move_left(&tet[i]);
	move_top(&tet[i]);
	return (tet);
}
