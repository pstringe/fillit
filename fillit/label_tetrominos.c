/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_tetrominos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:35:50 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/31 07:29:02 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	tetrominos = (ft_strlen(tetromino_set) + 1) / 21;
	return (tetrominos);
}

char		**get_individual_tetrominos(char *valid_tetromino_set)
{
	char	**tetromino_rows;
	char	**tetrominos;
	int		tetromino_count;
	int		row_count;
	int 	tetromino_allocation;

	tetromino_allocation = get_number_of_tetrominos(valid_tetromino_set) + 1;
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
	tetrominos[tetromino_count] = NULL;

	return (tetrominos);
}

t_et	*make_tet(char *tet_array, int order)
{
	t_et *tet;
	tet = malloc(sizeof(tet));
	tet->value = tet_array;
	tet->label = order + 65;
	tet->placed = 0;
	tet->next = NULL;
	return (tet);
}

t_et	*get_set(char **tetrominos)
{	
	int	i;
	t_et *set;
	t_et *tmp;

	i = 0;
	set = make_tet(*tetrominos, 0);
	tmp = set;
	while (tetrominos[++i])
	{
		tmp->next = make_tet(tetrominos[i], i);
		tmp = tmp->next;
	}
	return(set);
}

void	bounds(char *str, t_loc *min, t_loc *max)
{
	int i;

	i = -1;
	while (i < 20)
	{
		if (str[++i] == '#') 
		{
			if (i / 5 < min->y)
			{
				min->y = i / 5;
			}
			if (i / 5 > max->y)
			{
				max->y = i / 5;
			}
			if (i / 5 < min->x)
			{
				max->x = i % 5;
			}
			if (i % 5 > max->x)
			{
				max->x = i % 5;
			}
		}
	}
}
