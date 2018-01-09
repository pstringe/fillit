/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:21:26 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/29 20:04:19 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#define	TETRA_BYTES	20
//char	*read_tetromino_set(char *file);
int		error(int code);
char	*validate_tetromino_set(char *unvalidated_tetromino_set);
char	**get_individual_tetrominos(char *valid_tetromino_set);
int		access_first_dimension(int rowlen, int y, int x);
int		*access_second_dimension(int rowlen, int i);
char	**validate_tetrominos(char **tetrominos);
unsigned short int *encode_tetrominos(char **tetrominos);
unsigned short int *read_and_validate_tets(int argc, char **argv);
void		print_encoded_tetromino(unsigned short int tetromino);
#endif
