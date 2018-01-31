/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/30 17:32:25 by pstringe         ###   ########.fr       */
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


t_board		*generate_board(int no_of_tets, t_et *tets, int exp)
{
	t_board	*board_struct;	
	int 	min_size;
	char	**board;
	int		i;
	int		j;

	min_size = calc_minsize(no_of_tets);
	board_struct = malloc(sizeof(t_board));
	board = malloc(sizeof(char*) * min_size + exp + 1);
	i = 0;
	while (i < min_size + exp)
	{
		j = 0;
		board[i] = malloc(min_size + exp + 1);
		while (j < min_size + exp)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	board[i] = NULL;
	board_struct->exp = exp;
	board_struct->size = min_size + exp;
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
	t_et	*tmp;
	
	tmp = malloc(sizeof(t_et));
	tmp = tets;
	while (tmp->placed)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	clear_board(t_board *board)
{
	int i;
	int j;

	i = -1;
	while(board->map[++i])
	{
		j = -1;
		while (board->map[++j])
		{
			if (board->map[i][j] == get_next_tet(board->stack)->label)
			{
				board->map[i][j] = '.';
			}
		}
	}
}

int			try_tet(t_board *board, int x, int y)
{
	int 	i;
	int 	j;
	t_et	*tet;

	tet = get_next_tet(board->stack);
	i = -1;
	while(++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if((tet->value)[access_first_dimension(4, i, j)] != '.' 
			&& (x + i >= board->size 
			|| y + j >= board->size))
			{
				return (0);
			}
		}
	}
	return (1);
}

t_board		*place_tet(t_board *board, int x, int y)
{
	int i;
	int j;
	t_et *tet;

	tet = get_next_tet(board->stack);
	i = 0;
	while (i < 4 && x + i <= board->size)
	{
		j = 0;
		while (j < 4 && y + j <= board->size)
		{
			if ((tet->value)[access_first_dimension(4, i, j)] != '.')
			{
				if (board->map[x + i][y + j] == '.')
				{
					board->map[x + i][y + j] = tet->value[access_first_dimension(4, i, j)];
				}
			}
			j++;	
		}
		i++;	
	}
	tet->placed = 1;
	return (board);
}

t_board		*place_the_next_motherfucking_tet(t_board *board)
{
	int 	x;
	int 	y;
	t_et	*tet;

	tet = get_next_tet(board->stack);
	while(!tet->placed)
	{
		y = -1;
		while (++y < board->size)
		{
			x = -1;
			while (++x < board->size)
			{
				if (try_tet(board, x, y))
				{
					place_tet(board, x, y);
					return (board);
				}
				else
				{
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}

t_board		*expand_board(t_board *board)
{
	t_et	*tmp;

	tmp = board->stack;
	while (tmp)
	{
		tmp->placed = 0;
		tmp = tmp->next;
	}
	
	board->exp++;
	board = generate_board(3, board->stack, board->exp);
	return (board);
}

t_board		*solve(t_board *board)
{	
	if (place_the_next_motherfucking_tet(board))
	{
		print_board(board->map);
	}
	else
	{
		board = expand_board(board);
		//board = solve(board);
		print_board(board->map);
	}
	return(board);
}

int		main(int argc, char **argv)
{
	t_board	*board;
	
	if(argc != 2)
	{
		return (error(-6));
	}
	board = read_and_validate(argv[1]);
	/*
	print_board(board->map);
	
	board = solve(board);
	print_board(board->map);
	*/
	return (0);
}
