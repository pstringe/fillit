/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int			is_valid(/*t_board board, unsigned short int *region*/)
{
	int valid = 1;
	/*
	t_tet *tet; 
	tet = board->tets->tets[board->head];
	valid = in_range(board, region[1], region[2]) && match(tet, region))
	*/
	return (valid);
}
void		link_to_board(/*int x, int y,*/ t_board *board)
{
	int		i;
	t_tet	*tet;

	tet = board->tets->tets[board->tets->head];
	i = -1;
	while(++i < 16)
	{
		if (tet->value & (1 << i))
		{
			board->origin->next->parent = tet;
			
			/*link(find_mon(access_second_dimenion(4, i)[0], access_second_dimenion(4, i)[1]))*/;
		}
	}
}
t_board		*place(t_board *board)
{
	int i;
	int j;

	i = -1;
	while(++i)
	{
		j = -1;
		while(++j)
		{
			if (is_valid(/*board, encode_region(i, j)*/))
			{
				link_to_board(/*i,j,*/ board);
			}
		}
	}
	return (board);
}

/*generates a blank board, based on a minimum size given the number of tets invloved, plus optional expansion for later calls*/
t_board		*generate_board(t_ets *tets, int expansion)
{
	//int i;
	t_board *board;
	board = board_alloc(tets, expansion);
	return(board);
}

/*expands board when possibilitie for last size have been exahsted*/
t_board		*expand_board(t_board *board)
{
	board = generate_board(board->tets, board->expansion + 1);
	return (board);
}

/*used to initiate expansion by determining wheather the curent state of the board can be completed to a solution*/
int			reject(t_board *board)
{
	int		spaces_left;
	spaces_left = board->tets->no_of_tets * 4 - board->tets->head * 4;
	return (spaces_left < board->tets->no_of_tets * 4);
}

/*used to determine of the current board is a solution to the problem*/
int			accept(t_board *board)
{
	return (board->tets->head == board->tets->no_of_tets);
}

/*generates the root of the space of possible solutions*/
t_board		*root(t_ets *tets)
{
	t_board *board;
	board = generate_board(tets, 0);
	return(board);
}

/*generates the next board by placing a new tetromino*/
t_board		*first(t_board *board)
{
	if (board->tets->head == board->tets->no_of_tets)
	{
		return (NULL);
	}
	else
	{
		return(place(board));
	}
}

/*generates a new board by translating the position of the tetromino currently in play*/
t_board		*next(t_board *board)
{
	if (board->breadth == board->range) 
	{
		return (NULL);
	}
	else
	{
		return (/*translate(board)*/ NULL);
	}
}

t_board		*solve(t_board *board)
{
	if (reject(board))
	{
		expand_board(board);
	}
	if (accept(board))
	{
		return (board);
	}
	board = first(board);
	return (board); //test return
	/*
	while (board)
	{
		solve(board);
		board = next(board);
	}
	*/
}


int			main(int argc, char **argv)
{
	unsigned short int	*tet_codes;
	t_ets				*tets;
	t_board				*board;
	if(!(tet_codes = read_and_validate_tets(argc, argv)))
	{
		ft_putendl("Your shit sucks!");
		return (-1);
	}
	tets = prepare_for_placement(tet_codes);
	print_tet_set(tets);
	board = root(tets);
	print_board(board, 1);
	print_board(solve(board), 1);

	/*
	while(!(solve(board)))
	{
		board = expand_board(board);
	};
	*/
	ft_putendl("It works");
	return (0);
}
