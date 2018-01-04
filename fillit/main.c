/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 09:58:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/03 16:59:15 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlx.h"

int		main(void)
{
	int 		row_no;
	int 		col_no;
	int 		**problem_matrix;

	row_no = 7;
	col_no = 7;
	problem_matrix = allocate_problem_matrix(row_no, col_no);
	initialize_problem_matrix(problem_matrix, row_no, col_no);
	display_matrix(problem_matrix, row_no, col_no);
	problem_matrix = populate_problem_matrix(problem_matrix);
	display_matrix(problem_matrix, row_no, col_no);
	/*create_toroidal_matrix(problem_matrix, row_no, col_no);*/
	return (0);
}
