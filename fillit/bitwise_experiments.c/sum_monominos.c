/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_monominos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 20:11:02 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/30 20:24:21 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	uint16_t	tet;
	int			i;
	int 		sum;

	sum = 0;
	tet = 15;
	i	= 0;
	while (i < 16)
	{
		if(tet & ( 1 << i))
		{
			sum++;
		}
		i++;
	}
	printf("sum:\t%d\n", sum);
	return (0);
}
