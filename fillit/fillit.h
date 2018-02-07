/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/07 10:05:47 by pstringe         ###   ########.fr       */
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
	char const		*value;
	struct	s_et	*prev;
	struct	s_et	*next;
}				t_et;

typedef struct	s_board
{
	int				size;
	struct s_et		*stack;
	char			**map;
}				t_board;
int				error(int code);
#endif
