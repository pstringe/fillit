/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetromino_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:57:48 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/26 11:03:52 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char *read_tetromino_set(char *file)
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

unsigned short int	*read_and_validate_tets(int argc, char **argv)
{
	char				*unvalidated_tetromino_set;
	char				*valid_tetromino_set;
	char				**tetrominos;
	unsigned short int	*encoded_tetrominos;
	
	if(argc != 2)
	{
		error(-6);
		encoded_tetrominos = 0;
	}
	unvalidated_tetromino_set = read_tetromino_set(argv[1]);
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		error(-5);
		encoded_tetrominos = 0;
	}
	tetrominos = get_individual_tetrominos(valid_tetromino_set);
	tetrominos = validate_tetrominos(tetrominos);
	if(!tetrominos)
	{
		error(-8);
		encoded_tetrominos = 0;
	}
	if(!(encoded_tetrominos = encode_tetrominos(tetrominos)))
	{
		error(-10);	
		encoded_tetrominos = 0;
	}
	return (encoded_tetrominos);
}

