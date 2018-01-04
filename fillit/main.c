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
typedef struct	Node
{
	struct Node		*left;
	struct Node 	*right;
	struct Node		*up;
	struct Node 	*down;
	int 			row;
	int 			col;
	int				nodeCount;

}				node;

node	*create_toroidal_matrix(problem_matrix, row_no, col_no)
{
	int 	flag;
	int 	i;
	int		j;
	int		a;
	int		b;
	node	*header;
	node	**torus;
	
	header = create_node();
	torus = create_head();
	i = -1;
	while (++i <= row_no)
	{
		j = -1;
		while (++j <= col_no)
		{
			if(problem_matrix[i][j])
			{
				if(i)
				{
					torus[0][j]->nodeCount += 1;
				}
				torus[i][j]->row = i;
				torus[i][j]->col = j;
				
				flag = 1;
				a = i;
				b = j;

				while(!problem_matrix[a][b] && b != j)
				{
					
				}
			}
		}
	}
	
}
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
	create_toroidal_matrix(problem_matrix, row_no, col_no);
	return (0);
}
