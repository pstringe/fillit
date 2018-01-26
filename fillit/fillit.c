/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/26 14:33:26 by ralee            ###   ########.fr       */
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

char 	**generate_board(int no_of_tets)
{
	int min_size = calc_minsize(no_of_tets);
	char **board;
	int i;
	int j;

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

	return(board);
}

void	print_board(char **board)
{
	while (*board)
	{
		ft_putendl(*board);
		board++;
	}
}

int		main(int argc, char **argv)
{
	// int 	no_of_tets;
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	char	**tetrominos;
	t_list	*list;
	t_board	*board;

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
	/*validate the tetrominos according to number of omminos and connections*/
	tetrominos = validate_tetrominos(tetrominos);
	// normalize_tetrominos moves all tetrominos to top left corner
	normalize_tetrominos(tetrominos);
	// no_of_tets = tet_no(tetrominos);
	map = solve(list);
	ft_putstr("Still works!");
	return (0);
}
