/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitewise_encoder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 10:47:45 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/30 10:48:00 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_encoded_tetromino(unsigned short int tetromino)
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
	unsigned short int	tetr;
	
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

unsigned short int	*encode_tetrominos(char **tetrominos)
{
	int 		i;
	unsigned short int	tetr;
	unsigned short int	*encoded_tetrominos;

	encoded_tetrominos = (unsigned short int *)malloc(sizeof(unsigned short int) * get_number_of_tetrominos(tetrominos) + 1);
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
	encoded_tetrominos[i] = 0;
	return (encoded_tetrominos);
}

