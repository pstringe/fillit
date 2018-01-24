/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/23 19:47:29 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int		int_sqrt(int y, int x)
{
	if ( y * y >= x)
	{
		return (y);
	}
	else
	{
		return (int_sqrt(++y, x));
	}
}
int		calc_minsize(int n)
{
	if(n != 1)
	{
		return (int_sqrt(0, n * 4));
	}
	return (2);
}
int		tet_no(char **tets)
{
	int n;

	n = 0;
	while (*(tets + n))
	{
		n++;
	}
	return (n);
}

t_board		*generate_board(int no_of_tets, t_et *tets)
{
	t_board	*board_struct;	
	int 	min_size;
	char	**board;
	int		i;
	int		j;

	min_size = calc_minsize(no_of_tets);
	board_struct = malloc(sizeof(t_board));
	board = malloc(sizeof(char*) * min_size + 1);
	i = 0;
	while (i < min_size)
	{
		j = 0;
		board[i] = malloc(min_size + 1);
		while (j < min_size)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	board[i] = NULL;
	board_struct->size = min_size;
	board_struct->stack = tets;
	board_struct->map = board;

	return(board_struct);
}

void	print_board(char **board)
{
	while (*board)
	{
		ft_putendl(*board);
		board++;
	}
}

t_et	*get_next_tet(t_et *tets)
{
	t_et	*tet = malloc(sizeof(t_et));
	t_et	*tmp;

	tmp = tets;
	while (tmp->placed)
	{
		tmp = tmp->next;
	}
	tet = tmp;
	return (tet);
}
/*
void	clear_board(t_board *board)
{
	int i;
	int j;
	while(board->map[i])
	{
		j = -1;
		while (board->map[j])
		{
			if(board->tets)
			board->map[i][j]
		}
	}
}
*/
t_board		*place_tet(t_board *board, int x, int y)
{
	int i;
	int j;
	t_et *tet;

	tet = get_next_tet(board->stack);
	i = 0;
	while (i < 4 && x + i < board->size)
	{
		j = 0;
		while (j < 4 && y + j < board->size)
		{
			if (!board->map[x + i][y + i])
			{
				//clear_board(board->map);
				return (NULL);
			}
			if (board->map[x + i][y + j] == '.')
			{
				board->map[x + i][y + j] = tet->value[access_first_dimension(4, i, j)];
				j++;
			}
		}
		i++;
	} 
	return (board);
}

int		main(int argc, char **argv)
{
	int 	no_of_tets;
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	char	**tetrominos;
	t_board	*board;
	t_et	*set;
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
	tetrominos = validate_tetrominos(tetrominos);
	normalize_tetrominos(tetrominos);
	no_of_tets = tet_no(tetrominos);
	set = get_set(tetrominos);
	board = generate_board(no_of_tets, set);
	print_board(board->map);
	board = place_tet(board, 0, 0);
	print_board(board->map);
	return (0);
}
