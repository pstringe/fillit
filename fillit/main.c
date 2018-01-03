/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 09:58:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/03 15:23:11 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlx.h"
int		**populate_problem_matrix(int **matrix)
{
	matrix[1][0] = 1; matrix[1][3] = 1;
	matrix[1][6] = 1; matrix[2][0] = 1;
	matrix[2][3] = 1; matrix[3][3] = 1;
	matrix[3][4] = 1; matrix[3][6] = 1;
	matrix[4][2] = 1; matrix[4][4] = 1;
	matrix[4][5] = 1; matrix[5][1] = 1;
	matrix[5][2] = 1; matrix[5][5] = 1;
	matrix[5][6] = 1; matrix[6][1] = 1;
	matrix[6][6] = 1; matrix[7][0] = 1;
	matrix[7][3] = 1;
	return(matrix);
}

int		display_matrix(int **matrix, int rn, int cn)
{
	int i;
	int j;

	i = 0;
	while (++i <= rn)
	{
		if(!(matrix + i))
		{
			return (-1);
		}
		j = -1;
		while (++j <= cn)
		{
			if (!((matrix + i) + j))
			{
				return (-1);
			}
			ft_putchar(matrix[i][j] + '0');
			if (j && j % cn == 0)
			{
				ft_putchar('\n');
			}
		}
	}
	return (0);
}

int		*allocate_row(int cn)
{
	int *row;
	
	row = (int *)malloc((cn + 1) * sizeof(int));
	return (row);
}

int 	**allocate_problem_matrix(int rn, int cn)
{
	int i;
	int **matrix;
	
	matrix = (int **)malloc((rn + 1) * sizeof(int*));
	i = -1;
	while(++i <= rn + 1)
	{
		*(matrix + i) = allocate_row(cn);
	}
	return(matrix);
}

int		main(void)
{
	int 		i;
	int 		j;
	int 		row_no;
	int 		col_no;
	int 		**problem_matrix;

	row_no = 7;
	col_no = 7;
	problem_matrix = allocate_problem_matrix(row_no, col_no);
	/*initialize problem matrix*/
	i = -1;
	while(++i <= row_no)
	{
		j = -1;
		while (++j < col_no)
		{
			if (i == 0)
			{
				problem_matrix[i][j] = 1;
			}
			else
			{
				problem_matrix[i][j] = 0;
			}
		}
	}

	display_matrix(problem_matrix, row_no, col_no);
	problem_matrix = populate_problem_matrix(problem_matrix);
	display_matrix(problem_matrix, row_no, col_no);
	/*create_toroidal_matrix(problem_matrix, row_no, col_no);*/
	return (0);
}
