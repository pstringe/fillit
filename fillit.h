/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/01 15:05:57 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>

typedef struct	s_board
{
	int		size;
	char	**map;
}				t_board;

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_ets
{
	char	**pos;
	int		x_bounds;
	int		y_bounds;
	char	label;
}				t_ets;

/*
 * used throughout the program to display error messages
 */
void	error(int code);
#endif
