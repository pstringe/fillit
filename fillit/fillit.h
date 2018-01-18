/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/08 14:15:20 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#define	TETRA_BYTES	20
char	*read_tetromino_set(char *file);
int		error(int code);
char	*validate_tetromino_set(char *unvalidated_tetromino_set);
char	**get_individual_tetrominos(char *valid_tetromino_set);
int		access_first_dimension(int rowlen, int y, int x);
int		*access_second_dimension(int rowlen, int i);
char	**validate_tetrominos(char **tetrominos);
char	**normalize_tetrominos(char **tetrominos);
void	solver(char **tetrominos);
#endif
