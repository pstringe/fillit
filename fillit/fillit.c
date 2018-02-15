/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/14 19:30:08 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int		resolve(t_board *board)
{
	print_map(board);
	if(board->exp < 3)
	{
		return (0);
	}
	return (1);
}

t_board	*solve(t_board *board)
{
	t_list	*tmp;
	
	tmp = *(board->stack);
	while (!resolve(board))
	{
		board = root(tmp, board->exp + 1);
		ft_putendl("");
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

	return (0);
}
