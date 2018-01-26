/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:34:03 by ralee             #+#    #+#             */
/*   Updated: 2018/01/26 14:38:20 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_position		*position(int x, int y)
{
	t_position		*new_position;

	new_position = ft_memalloc(sizeof(t_position));
	new_position->x = x;
	new_position->y = y;
	return (new_position);
}