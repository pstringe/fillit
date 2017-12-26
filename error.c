/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:18:20 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/26 13:06:48 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int code)
{
	if(code == -1)
		ft_putstr("file not read");
	else if (code == -2)
		ft_putstr("wrong number of characters");
	else if (code == -3)
		ft_putstr("invalid characters");
	else if (code == -4)
		ft_putstr("wrong number of newlines");
	return (code);
}
