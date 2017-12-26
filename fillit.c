/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/26 13:24:52 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	if(argc != 2)
	{
		return (0);
	}
	unvalidated_tetromino_set = read_tetromino_set(argv[1]);

	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		return(-1);
	}
	ft_putstr("It works!");
	return (0);
}
