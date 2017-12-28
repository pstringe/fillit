/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/28 11:30:33 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int			access_first_dimension(int row_len, int y, int x)
{
	return(row_len * y + x);
}		

static char *get_tetromino(char **rows, int order)
{
	int i;
	int j;
	int z;

	char *tetromino;
	
	if(!(tetromino = (char *)malloc(17)))
	{
		error(-7);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		while(j < 5)
		{	
			z = access_first_dimension(4, i, j);
			if (rows[i + (order * 4)][j] == '.')
			{
				tetromino[z] = rows[i + (order * 4)][j];
			}
			else if(rows[i + (order * 4)][j] == '#')
			{
				tetromino[z] = rows[i + (order * 4)][j] + (30 + order);
			}
			else if(z == 4)
			{
				tetromino[z] = '\0';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (tetromino);
}

int			get_number_of_tetrominos(char *tetromino_set)
{
	int tetrominos;
	tetrominos = ft_strlen(tetromino_set) / 21;
	return (tetrominos);
}

char		**get_individual_tetrominos(char *valid_tetromino_set)
{
	char	**tetromino_rows;
	char	**tetrominos;
	int		tetromino_count;
	int		row_count;
	int 	tetromino_allocation;

	tetromino_allocation = get_number_of_tetrominos(valid_tetromino_set);
	tetrominos = (char**)malloc(tetromino_allocation * sizeof(char **));
	tetromino_rows = ft_strsplit(valid_tetromino_set, '\n');	
	tetromino_count = 0;
	row_count = 0;
	while(tetromino_rows[row_count])
	{
		tetrominos[tetromino_count] = get_tetromino(tetromino_rows, tetromino_count);
		tetromino_count++;
		row_count += 4;
	}

	return (tetrominos);
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
	
	/*tetsting output of get_individual_tetrominos
	while(*tetrominos)
	{
		ft_putendl(*tetrominos);
		tetrominos++;
	}
	*/
	ft_putendl(*tetrominos);
	return (0);
}
