/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/25 22:27:47 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
static	char *read_tetronimo_set(char *file)
{
	int		file_descriptor;
	int		bytes_read;
	char	file_buffer[TETRA_BYTES + 1];
	char 	*unvalidated_tetromino_set;
	char	*temporary_tetromino;
	
	unvalidated_tetromino_set = NULL;
	file_descriptor = open(file, O_RDONLY);
	if(!file_descriptor)
	{
		return(NULL);
	}

	bytes_read = TETRA_BYTES;
	while(bytes_read == TETRA_BYTES)
	{
		bytes_read = read(file_descriptor, file_buffer, TETRA_BYTES);
		file_buffer[bytes_read] = '\0';
		temporary_tetromino = (char *)malloc(sizeof(char) * ft_strlen(file_buffer) + 1);
		ft_memmove(unvalidated_tetromino_set, file_buffer, bytes_read);
		free(file_buffer);
		unvalidated_tetromino_set += bytes_read;	
	}
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
