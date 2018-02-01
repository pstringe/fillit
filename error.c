/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:45:30 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/01 15:03:07 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int code)
{
	if (code == 1)
		ft_putendl("invalid no of arguments: 1");
	if (code == 2)
		ft_putendl("read error: 2");
}
