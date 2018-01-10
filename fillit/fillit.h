/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/02 16:16:59 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#define	TETRA_BYTES	20
//char	*read_tetromino_set(char *file);

typedef struct	s_grid_location
{
	int						x;
	int						y;
	int						value;
	int						parent;
	struct grid_location	*prev;
	struct grid_location	*next;
	struct grid_location	*up;
	struct grid_location	*down;
	struct grid_location	*right;
	struct grid_location	*left;
}				point;

typedef struct	s_tetromino
{
	int						order;
	int						value;
	struct grid_location	*origin;
	struct grid_location	*second;
	struct grid_location	*third;
	struct grid_location	*fourth;
}				t_tet;

typedef struct	s_board
{
	int						validity;
	int						size;
	unsigned short int		*tets;
	struct grid_location	*origin;
}				t_board;

t_tet	**prepare_for_placement(unsigned short int *tet_codes);
t_tet	*initialize_spatial_tet(unsigned short int code, int order);
int		error(int code);
char	*validate_tetromino_set(char *unvalidated_tetromino_set);
char	**get_individual_tetrominos(char *valid_tetromino_set);
int		access_first_dimension(int rowlen, int y, int x);
int		*access_second_dimension(int rowlen, int i);
char	**validate_tetrominos(char **tetrominos);
unsigned short int *encode_tetrominos(char **tetrominos);
unsigned short int *read_and_validate_tets(int argc, char **argv);
void		print_encoded_tetromino(unsigned short int tetromino);
char	**normalize_tetrominos(char **tetrominos);
#endif
