/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/27 16:52:42 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
char	**get_individual_tetrominos(char *valid_tetromino_set)
{
	char	**tetromino_rows;
	
	/*just to remove '\n', and make the string more workable*/
	tetromino_rows = ft_strsplit(valid_tetromino_set, '\n');
	/*testing the output of strsplit*/
	return (tetromino_rows);
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
	
	/*tetsting output of get_individual_tetrominos*/
	while(*tetrominos)
	{
		ft_putendl(*tetrominos);
		tetrominos++;
	}
	return (0);
}
