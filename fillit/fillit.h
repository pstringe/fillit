/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/16 19:16:24 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#define	PIECE	21
#define	TET		16

typedef struct	s_et
{
	char			label;
	char			*value;
	int				placed;
	int				bound_x;
	int				bound_y;
}				t_et;

typedef struct	s_board
{
	int				size;
	int				exp;
	struct s_list	**stack;
	char			**map;
}				t_board;

/*
 * reading and validation
 */
char			*normalize(char *tet);
t_board			*read_and_validate(char *str);

/*
 * algorithm
 */
t_board			*solve(t_board *board);
t_board			*root(t_list *tets, int exp);

/*
 * output and debugging
 */
int				error (int code);
void			print_value(t_list *tet, int p);
void			print_tets(t_list **tets, int p);
void			print_map(t_board *board);
#endif
