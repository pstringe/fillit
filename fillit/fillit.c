/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/15 18:59:06 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*place_tet(t_board *board, t_et *tet, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while ((board->map)[y + i])
	{
		j = 0;
		while ((board->map)[y + i][x + j])
		{
			if((tet->value)[(i * 4) + j] == '#')
			{
				board->map[i + y][j + x] = tet->label;
			}
			j++;
		}
		i++;	
	}
	return (board);
}

int			try_tet(t_board *board, t_et *tet, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while ((board->map)[y + i])
	{
		j = 0;
		while ((board->map)[y + i][x + j])
		{
			if ((board->map)[y + i][x + j] != '.' &&
				(tet->value)[(i * 3) + j] != '.')
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_board		*resolve(t_board *board, t_list *lst)
{
	int		x;
	int		y;
	t_et	tet;
	
	if (!lst)
	{
		return (board);
	}
	tet = (*(t_et*)(lst->content)); 
	y = -1;
	while (++y <=  board->size - 1 - tet.bound_y)
	{
		x = -1;
		while (++x <= board->size - 1 - tet.bound_x)
		{
			if (try_tet(board, &tet, x, y))
			{
				place_tet(board, &tet, x, y);
				print_map(board);
				return(resolve(board, lst->next));
			}
		}
	}
	return (NULL);
}

t_board		*solve(t_board *board)
{
	t_list *tets;

	tets = *(board->stack);
	while (!resolve(board, *(board->stack)))
	{
		board = root(tets, board->exp + 1);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_board		*board;

	if(argc != 2)
		return (error(1));
	if (!(board = read_and_validate(argv[1])))
		return (error(2));
	solve(board);
	print_map(board);
	return (0);
}
