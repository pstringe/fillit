/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/08 17:57:32 by pstringe         ###   ########.fr       */
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
	int				placed;
	char			*value;
}				t_et;

typedef struct	s_board
{
	int				size;
	struct s_list	*stack;
	char			**map;
}				t_board;

int				error (int code);
t_board			*read_and_validate(char *str);
t_board			*root(t_list *tets, int exp);
void			print_map(t_board *board);
#endif
