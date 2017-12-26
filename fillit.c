/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/25 18:37:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		file_descriptor;
	int		bytes_read;
	char	file_buffer[TETRA_BYTES + 1];
	char 	*tetronimo;

	tetronimo = NULL;
	if (argc != 2)
	{
		return(-1);
	}

	if(!(file_descriptor = open(argv[1], O_RDONLY)))
	{
		return(0);
	}
	bytes_read = read(file_descriptor, file_buffer, TETRA_BYTES);
	file_buffer[bytes_read + 1] = '\0';
	tetronimo = (char *)malloc(sizeof(char) * ft_strlen(file_buffer) + 1);
	ft_memmove(tetronimo, file_buffer, TETRA_BYTES + 1);
	ft_putstr(tetronimo);
}
