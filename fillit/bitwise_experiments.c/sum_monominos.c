/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_monominos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 20:11:02 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/10 16:02:47 by pstringe         ###   ########.fr       */
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
	tet = 129;
	i	= 0;
	//10000001 tet
	//00000000
	//
	//10000000 this is the result we are comparing
	//
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
