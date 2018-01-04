#ifndef	DLX_H
# define DLX_H
#include "../libft/libft.h"
#include <stdlib.h>
int		**allocate_problem_matrix(int row_no, int col_no);
void	initialize_problem_matrix(int **matrix, int row_no, int col_no);
int		**populate_problem_matrix(int **matrix);
int		display_matrix(int **matrix, int row_no, int col_no);
#endif
