/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/26 10:17:45 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
static	char *read_tetronimo_set(char *file)
{
	int		file_size;
	int		file_descriptor;
	int		bytes_read;
	char	file_buffer[TETRA_BYTES + 1];
	char 	*unvalidated_tetromino_set;
	
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

int		main(int argc, char **argv)
{
	char *unvalidated_tetromino_set;

	if(argc != 2)
	{
		return (0);
	}
	unvalidated_tetromino_set = read_tetronimo_set(argv[1]);
/*
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		return(NULL);
	}
*/	
	ft_putstr(unvalidated_tetromino_set);
}
