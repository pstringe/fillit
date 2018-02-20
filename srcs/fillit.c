/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/19 21:35:04 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_board		*board;

	if (argc != 2)
		return (error(1));
	if (!(board = read_and_validate(argv[1])))
		return (error(2));
	if (!(board = solve(board)))
		return (error(2));
	print_map(board);
	return (0);
}
