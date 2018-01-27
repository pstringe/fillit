/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/26 21:20:45 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#define	TETRA_BYTES	20

typedef struct	s_et
{
	char			label;
	int				placed;
	char			*value;
	struct	s_et	*next;
}				t_et;

typedef struct	s_board
{
	int				size;
	struct s_et		*stack;
	char			**map;
}				t_board;

t_board		*generate_board(int no_of_tets, t_et *tets);
int		tet_no(char **tets);
t_board	*read_and_validate(char *file);
t_et	*make_tet(char *tet_array, int order);
t_et	*get_set(char **tetrominos);
char	*read_tetromino_set(char *file);
int		error(int code);
char	*validate_tetromino_set(char *unvalidated_tetromino_set);
char	**get_individual_tetrominos(char *valid_tetromino_set);
int		access_first_dimension(int rowlen, int y, int x);
int		*access_second_dimension(int rowlen, int i);
char	**validate_tetrominos(char **tetrominos);
char	**normalize_tetrominos(char **tetrominos);
#endif
