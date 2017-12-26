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
