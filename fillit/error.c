/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:41:34 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/06 21:13:26 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int code)
{
	if (code == 1)
		ft_putendl("bad no of args, must enter one file name");
	if (code == 2)
		ft_putendl("invalid input");
	return (code);
}
