/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/12 03:37:44 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#define	TETRA_BYTES	20
//char	*read_tetromino_set(char *file);

typedef struct		s_grid_location
{
	int						order;
	int						x;
	int						y;
	int						value;
	int						parent;
	struct s_grid_location	*prev;
	struct s_grid_location	*next;
	struct s_grid_location	*up;
	struct s_grid_location	*down;
	struct s_grid_location	*right;
	struct s_grid_location	*left;
}				t_point;

typedef struct		s_tetromino
{
	int						order;
	int						value;
	struct s_grid_location	*origin;
	struct s_grid_location	*second;
	struct s_grid_location	*third;
	struct s_grid_location	*fourth;
}					t_tet;

typedef struct		s_board
{
	int						validity;
	int						size;
	struct s_tetromino		**tets;
	struct s_grid_location	*origin;
}					t_board;

t_tet				**prepare_for_placement(unsigned short int *tet_codes);
t_tet				*initialize_spatial_tet(unsigned short int code, int order);
int					error(int code);
char				*validate_tetromino_set(char *unvalidated_tetromino_set);
char				**get_individual_tetrominos(char *valid_tetromino_set);
int					access_first_dimension(int rowlen, int y, int x);
int					*access_second_dimension(int rowlen, int i);
char				**validate_tetrominos(char **tetrominos);
unsigned short int	*encode_tetrominos(char **tetrominos);
unsigned short int	*read_and_validate_tets(int argc, char **argv);
void				print_encoded_tetromino(unsigned short int tetromino);
char				**normalize_tetrominos(char **tetrominos);
#endif
