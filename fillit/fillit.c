/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/30 19:04:40 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		print_encoded_tetromino(uint16_t tetromino)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if (tetromino & (1 << i))
		{
			ft_putchar('#');
		}
		else
		{
			ft_putchar('.');
		}
		if(!((i + 1) % 4) && i != 0)
		{
			ft_putchar('\n');
		}
	}
}

static int	encode_tetromino(char *tetromino)
{
	int 		i;
	uint16_t	tetr;
	
	tetr = 0;
	i = -1;
	while (tetromino[++i])
	{
		tetr = (tetromino[i] != '.') ? tetr | (1 << i) : tetr;
	}
	return (tetr);
}

static int	get_number_of_tetrominos(char **tetrominos)
{
	int i;
	
	i = 0;
	while (tetrominos[i])
	{
		i++;
	}

	return(i);
}

uint16_t	*encode_tetrominos(char **tetrominos)
{
	int 		i;
	uint16_t	tetr;
	uint16_t	*encoded_tetrominos;

	encoded_tetrominos = (uint16_t *)malloc(sizeof(uint16_t) * get_number_of_tetrominos(tetrominos) + 1);
	tetr = 0;
	i = -1;
	while(tetrominos[++i])
	{
		tetr = encode_tetromino(tetrominos[i]);
		/*
		if(!(tetr = encode_tetromino(tetrominos[i])))
		{
			error(-11);
			return(NULL);
		}
		*/
		encoded_tetrominos[i] = tetr;
	}
	encoded_tetrominos[i] = (uint16_t)NULL;
	return (encoded_tetrominos);
}

int		main(int argc, char **argv)
{
	char 		*unvalidated_tetromino_set;
	char		*valid_tetromino_set;
	char		**tetrominos;
	uint16_t	*encoded_tetrominos;

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
	/*validate the tetrominos according to number of omminos and connections*/
	tetrominos = validate_tetrominos(tetrominos);
	if(!tetrominos)
	{
		return(error(-8));
	}
	if(!(encoded_tetrominos = encode_tetrominos(tetrominos)))
	{
		return(error(-10));
	}
	/*make sure the intgers were actually placed in the array*/
	int i;
	i = 0;
	while (i < 1)
	{
		print_encoded_tetromino(*encoded_tetrominos);
		encoded_tetrominos++;
		i++;
	}

	ft_putendl("It works");
	return (0);
}
