/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:47:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/12 19:37:41 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_board *board)
{
	int i;

	i = -1;
	while((board->map)[++i])
	{
		ft_putendl((board->map)[i]);
	}
}

static void		print_pretty(char *str, char label)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (i % 4 == 0)
			ft_putchar('\n');
		if (str[i] != '.')
			ft_putchar(label);
		else
			ft_putchar(str[i]);
	}
	ft_putchar('\n');
}

void		print_value(t_list *tet, int p)
{
	t_et	*tmp;

	if (!tet)
		return ;
	tmp = ((t_et*)(tet->content));

	if (p == 0 && tmp->value)
		ft_putendl(tmp->value);
	else if (p == 1 && tmp->value)
		print_pretty(tmp->value, tmp->label);
}

void		print_tets(t_list **tets, int p)
{
	t_list	*tmp;
	
	tmp = *tets;
	while(tmp)
	{
		print_value(tmp, p);
		tmp = tmp->next;
	}
}
