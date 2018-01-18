/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:07:51 by ralee             #+#    #+#             */
/*   Updated: 2018/01/17 13:57:30 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solver(char **tetrominos)
{
	int		index;
	int		min_size;

	index = 0;
	min_size = 0;
	while (tetrominos[index])
	{
		index++;
	}
	while ( min_size * min_size < index * 4)
		min_size++;
	ft_putnbr(min_size);
	ft_putnbr(index);
	// createboard(index);
}