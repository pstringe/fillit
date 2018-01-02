/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 09:58:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/02 10:27:48 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlx.h"

int		main(int argc, char **argv)
{
	int i;
	int j;
	int row_no;
	int colno;
	int **problem_matrix;
	
	if (argc != 3)
	{
		ft_putendl("invalid no of args");
		exit();
	}

	row_no = ft_atoi(argv[1]);
	col_no = ft_atoi(argv[2]);

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
	display_problem_matrix("Before Fill", problem_matrix, row_no, col_no);
	problem_matrix = fill_problem_matrix(row_no, col_no);
	display_problem_matrix("After Fill", problem_matrix, row_no, col_no);
	/*create_toroidal_matrix(problem_matrix, row_no, col_no);*/
	return (0);
}
