/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:38:40 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/06 21:15:14 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define	PIECE	21

/*
 *	counts a monomino's adjacent monominos
 */
int			adj(char *str, int i)
{
	int		top;
	int		bottom;
	int		left;
	int		right;

	top = (str[i - 4]) ? i - 4 : -1;
	bottom = (str[i + 4]) ? i + 4 : -1;
	right = (str[i + 1] && !(i % 4 || (i + 1) % 4)) ? i + 1: -1;
	left = (str[i - 1] && !(i % 4 || (i + 1) % 4)) ? i - 1: -1;

	return ((top == '#') + (bottom == '#') + (right == '#') + (left == '#'));
}

/*
 * validates an individual chunk
 */
int			validate(char **str)
{
	int		i;
	int		count;
	char	*tet;
	int		a;
	
	while(str)
	{
		tet = ft_strjoin(tet, *str);
		str++;
	}
	a = 0;
	count = 0;
	i = -1;
	while (++i < PIECE)
	{
		if (str[i] && !(tet[i] == '.' || tet[i] == '#'))
			return (0);
		else if ((tet[i] && (a += adj(tet, i))))
			return (0);
		else if (tet[i] == '#')
			count++;
	}
	return (count == 4 && (a == 6 || a == 8));
}

/*
 * creates a tet and pushes it onto the list
 */
void		push_tet(t_et **head, char *buf)
{
	static int		order;
	char			**rows;
	char const		*value;
	t_et			*tet;
	
	rows = ft_strsplit(buf, '\n');
	while (*rows)
	{
		value = ft_strjoin(value, *rows++);
	}
	//ft_doublefree(value);
	tet = (t_et*)malloc(sizeof(tet));
	tet->label = order + 65;
	tet->placed = 0;
	tet->value = value;
	tet->next = (*head);
	tet->prev = NULL;
	*head = tet; 
}

/*
 * reads and validates the file one chunck at a time
 */
t_board		*read_and_validate(char *file)
{
	int		fd;
	t_et	**head;
	char	buf[PIECE + 1];

	head = NULL;
	fd = open(file, O_RDONLY);
	while(read(fd, buf, PIECE) >= PIECE - 1 && validate(ft_strsplit(buf, '\n')))
	{
		push_tet(head, buf);
	}
	while((*head)->prev)
	{
		head = &((*head)->prev);
	}
	return(root(head, 0));
}

int			main(int argc, char **argv)
{
	t_board		*board;

	if(argc != 2)
		return (error(1));
	else if (!(board = read_and_validate(argv[1])))
		return (error(2));
	return (0);
}
