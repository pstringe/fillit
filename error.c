/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:18:20 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/28 12:04:27 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int code)
{
	if(code == -1)
		ft_putendl("file not read");
	else if (code == -2)
		ft_putendl("wrong number of characters");
	else if (code == -3)
		ft_putendl("invalid characters present in input");
	else if (code == -4)
		ft_putendl("wrong number of newlines present in input");
	else if (code == -5)
		ft_putendl("file is invalid");
	else if (code == -6)
		ft_putendl("Bad number of arguments:\nYou must enter one file name as an argument");
	else if (code == -7)
		ft_putendl("failed to allocate tetromino");
	else if (code == -8)
		ft_putendl("one or more supposed tetrominos do not fit the geometric definition of a tetromino");
	return (code);
}
