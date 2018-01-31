/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetromino_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:57:48 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/30 17:29:22 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *read_tetromino_set(char *file)
{
    int     file_size;
    int     file_descriptor;
    int     bytes_read;
    char    file_buffer[TETRA_BYTES + 1];
    char    *unvalidated_tetromino_set;

    unvalidated_tetromino_set = (char *)malloc(sizeof(char) * 21 * 26 + 1);
    file_descriptor = open(file, O_RDONLY);
    if(!file_descriptor)
    {
        return(NULL);
    }

    file_size = 0;
    bytes_read = TETRA_BYTES;
    while(bytes_read == TETRA_BYTES)
    {
        bytes_read = read(file_descriptor, file_buffer, TETRA_BYTES);
        file_size += bytes_read;
        file_buffer[bytes_read] = '\0';
        ft_memmove(unvalidated_tetromino_set, file_buffer, bytes_read);
        unvalidated_tetromino_set += bytes_read;
    }
    *unvalidated_tetromino_set = '\0';
    unvalidated_tetromino_set -= file_size;
    return (unvalidated_tetromino_set);
}

int		tet_no(char **tets)
{
	int n;

	n = 0;
	while (*(tets + n))
	{
		n++;
	}
	return (n);
}

t_board	*read_and_validate(char *file)
{
	int 	no_of_tets;
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	char	**tetrominos;
	t_et	*set;
	
	unvalidated_tetromino_set = read_tetromino_set(file);
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		return(NULL);
	}
	tetrominos = get_individual_tetrominos(valid_tetromino_set);
	tetrominos = validate_tetrominos(tetrominos);
	normalize_tetrominos(tetrominos);
	no_of_tets = tet_no(tetrominos);
	set = get_set(tetrominos);
	return (generate_board(no_of_tets, set, 0));
}
