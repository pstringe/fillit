/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensional_access.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:44:13 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/29 17:06:28 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		access_first_dimension(int row_len, int y, int x)
{
	return(row_len * y + x);
}
int		*access_second_dimension(int row_len, int i)
{
	int x;
	int y;
	int *coord;
	
	coord = malloc(sizeof(int) * 2);
	y = i / row_len;
	x = i % row_len;
	coord[0] = x;
	coord[1] = y;
	return(coord);
}
