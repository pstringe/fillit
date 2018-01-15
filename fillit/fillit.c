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

/*
int			solve(t_board *board)
{
	if (not_possible_solution(board))
	{
		return (NULL);
	}
	if (is_solution(board))
	{
		return (board);
	}
	board = place_next_tet(board);
	while (baord != NULL)
	{
		solve(board);
		board = translate_last_tet(board);
	}
}
*/

int		*tet_to_board_space(int x, int y)
{
	int	*coords;

	coords = malloc(sizeof(int) * 2);
	coords[0] = x;
	coords[1] = y;
	return(coords);
}

void	ft_link(t_board *board, t_tet *tet)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_point	*tmp;

	tmp = board->origin->next;
	j = 16;
	i = -1;
	while (i < 4)
	{
		while (--j)
		x = access_second_dimension(4, j)[0];
		y = access_second_dimension(4, j)[1];
		x = (tet->value & 1 << j) ? tet_to_board_space(x, y)[0]: -1; 
		y = (tet->value & 1 << j) ? tet_to_board_space(x, y)[1]: -1;
		while (tmp)
		{
			if (tmp->x == x && tmp->y == y)
			{
				tmp->parent = tet;
				tmp->value = 1;
			}
			tmp = tmp->next;
		}
	}
}

void	combine(t_board *board, /*int breadth,*/ int depth)
{
	int		i;
	t_tet	*tmp;

	i = -1;
	while(++i < depth)
	{
		tmp = board->tets[i];
		ft_link(board, tmp);
	}
}

t_board		*generate_board(t_ets *tets, int expansion, int breadth, int depth)
{
	int i;
	t_board *board;
	board = board_alloc(tets, expansion);
	combine(board, breadth, depth);
	return(board);
}

int			main(int argc, char **argv)
{
	unsigned short int	*tet_codes;
	t_ets				*tets;
	t_board				*board;
	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	tets = prepare_for_placement(tet_codes);
	print_tet_set(tets);
	board = generate_board(tets, 0);
	print_board(board);
	/*
	while(!(solve(board)))
	{
		board = expand_board(board);
	};
	*/
	ft_putendl("It works");
	return (0);
}
