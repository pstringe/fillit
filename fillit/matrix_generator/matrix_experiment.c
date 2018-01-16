/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_experiment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:04:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/16 10:11:36 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include

typedef struct	s_map
{
	int				size;
	struct	t_point	*orgqin;
	struct	s_map	**children = generate_children();
}				t_state;
