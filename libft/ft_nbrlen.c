/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:47:49 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/18 10:50:39 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int nbr)
{
	int len;

	if (!nbr)
	{
		return (1);
	}
	len = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
