/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:47:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/19 15:26:53 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_board *board)
{
	int i;

	i = -1;
	while (i <= board->size && (board->map)[++i])
	{
		ft_putendl((board->map)[i]);
	}
}

static void	print_pretty(char *str, char label)
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
	ft_putendl("\n");
}

void		print_tet(t_list *tet, int p)
{
	t_et	*tmp;

	if (!tet)
		return ;
	tmp = ((t_et*)(tet->content));
	if (p == 0 && tmp->value)
		ft_putendl(tmp->value);
	else if (p == 1 && tmp->value)
		print_pretty(tmp->value, tmp->label);
	else if (p == 2 && tmp)
	{
		ft_putstr("label:\t");
		ft_putchar(tmp->label);
		ft_putchar('\n');
		ft_putstr("bound_x:\t");
		ft_putnbr(tmp->bound_x);
		ft_putchar('\n');
		ft_putstr("bound_y:\t");
		ft_putnbr(tmp->bound_y);
		ft_putendl("\n");
	}
}

void		print_tets(t_list **tets, int p)
{
	t_list	*tmp;

	tmp = *tets;
	while (tmp)
	{
		print_tet(tmp, p);
		tmp = tmp->next;
	}
}
