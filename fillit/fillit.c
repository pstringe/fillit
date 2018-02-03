/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/03 11:17:41 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *	estimates the squar root of a number for use in board generation 
 */
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

/*
 * calculates the minimim size board given the number of tets
 */
int		calc_minsize(int n)
{
	if(n != 1)
	{
		return (int_sqrt(0, n * 4));
	}
	return (2);
}

/*
 * takes a set of tetromnios and generates the root, this function currently does not account for expansion, 
 * In the past I've used an extra integer input to expand the board, 
 * but I kept running into strange memory issues. 
 * I need to follow the proccess of board generation carefully on paper, then write the function,
 * then follow it in the debugger.
 */
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

/*
 * displays the boards map to standard in
 */
void	print_board(char **board)
{
	while (*board)
	{
		ft_putendl(*board);
		board++;
	}
}

/*
 * pops a tet from the stack 
 */
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

/*
 * was using this to execute a clearing condition when place_tet and try_tet were the same function
 * now I'm not using it since there are only placements after its been determined there is space.
 * this function  may still come in handy when the program backtracks.
 */
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

/*
 *	checks to see if there is available space for the current tet	 	
 */
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

/*
 * this function places a tet on the board at a specified index, it is only called if the try_tet function 
 * returns true, indicating there is space available
 */
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
				/*
				if (x + i == board->size || y + j == board->size)
				{
					ft_putendl("the clearing condition executed");
					clear_board(board);
					return (NULL);
				}
				*/
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

/*
**	this function attempt to place the next tet on the stack onto the boards map, by first seeing if there are **  any available spaces, and then, if space is available, places the tet.
*/
t_board		*place_the_next_tet(t_board *board)
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
					ft_putendl("Shit don't fit!");
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}

/*
** to become the main solving function that will expand the board if the sub_solver returns no solution,
** right now, I'm using in to test the functions I have so far.	
*/
t_board		*solve(t_board *board)
{	
	if (place_the_next_tet(board))
	{
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
	print_board(board->map);
	board = solve(board);
	print_board(board->map);
	return (0);
}
