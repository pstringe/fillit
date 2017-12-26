/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/26 13:15:16 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
static	int		is_valid_char(char c)
{
	if (c == '\n' || c == '#' || c == '.')
	{
		return (1);
	}
	return (0);
}

static 	int	is_valid_filesize(char *unvalidated_tetromino_set)
{
	int counter;
	int filesize;

	counter = -1;
	while(unvalidated_tetromino_set[++counter])
	{
		filesize = counter + 1;
	}
	if(filesize % 21 == 0 && filesize <= 26 * 21)
	{
		return (1);	
	}
	return (0); 
}

static int	is_valid_charset(char *unvalidated_tetromino_set)
{
	int i;

	i = -1;
	while(unvalidated_tetromino_set[++i])
	{
		if (!is_valid_char(*(unvalidated_tetromino_set + i)))
		{
			return(0);	
		}
	}
	return(1);
}

static int	is_valid_number_of_newlines(char *unvalidated_tetromino_set)
{
	int i;
	int	file_size;
	int number_of_newlines;

	file_size = ft_strlen(unvalidated_tetromino_set);
	number_of_newlines = 0;
	i = -1;
	while(unvalidated_tetromino_set[++i])
	{
		if (unvalidated_tetromino_set[i] == '\n')
		{
			number_of_newlines++;
		}
	}
	if(number_of_newlines % 5 == 0 && number_of_newlines / (file_size / 21) == 5)
	{
		return (1);
	}
	return (0);
}

char	*validate_tetromino_set(char *unvalidated_tetromino_set)
{
	if(!unvalidated_tetromino_set)
	{
		error(-1);
		return(NULL);
	}
	if(!(is_valid_filesize(unvalidated_tetromino_set)))
	{
		error(-2);
		return(NULL);
	}
	if(!is_valid_charset(unvalidated_tetromino_set))
	{
		error(-3);
		return(NULL);
	}
	if(!is_valid_number_of_newlines(unvalidated_tetromino_set))
	{
		error(-4);
		return(NULL);
	}
	return(unvalidated_tetromino_set);
}

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
