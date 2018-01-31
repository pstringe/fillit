/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_tetrominos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:35:50 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/31 09:05:34 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char *get_tetromino(char *rows, int order)
{
	int		i;
	t_loc	*upper_bounds;
	t_loc	*lower_bounds;
	char 	**value;
	t_et	*tetromino;

	lower_bounds = new_loc(3, 3);
	upper_bounds = new_loc(0, 0);
	bounds(rows, lower_bounds, upper_bounds);
	value = ft_memalloc(sizeof(char *) * (upper_bounds->y - lower_bounds->y + 1));

	i = -1;
	while (++i < upper_bounds->y - lower_bounds->y + 1)
	{
		rows[i] = ft_strnew(upper_bounds->x, lower_bounds->x + 1);
		ft_strncpy(pos[i], rows + (lower_bounds->x) + (i + lower_bounds->y) * 5, upper_bounds->x - lower_bounds-x + 1);

	}
	tetromino = make_tet(rows, upper_bounds->x - lower_bounds->x, upper_bounds->y - lower_bounds->y + 1);
	ft_memdel((void **)&lower_bounds);
	ft_memdel((void **)&upper_bounds);
	return (tetromino);
}
/*
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
*/
t_et	*make_tet(char **tet_array, int x_diff, y_diff, char label)
{
	t_et *tet;

	tet = malloc(sizeof(t_et));
	tet->value = tet_array;
	tet->label = label;
	tet->x_diff = x_diff;
	tet->y_diff = y_diff;
	return (tet);
}
/*
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
*/
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
