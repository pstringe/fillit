/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:15:12 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/30 17:23:19 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

uint16_t	string2int(char *tetri)
{
	int			i;
	uint16_t	t;

	t = 0;
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			t = t | (1 << i); // 1 << i -> 0000...1...0
		}
		i++;
	}
	return (t);
}

uint16_t	string2int_alt(char *tetri)
{
	int			i;
	uint16_t	t;

	t = 0;
	i = -1;
	while (tetri[++i])
		t = (tetri[i] == '#') ? t | (1 << i) : t;
	return (t);
}

int		main()
{
	char	tetri[16] = "####............";
	char	tetri2[16] = "........####....";
					
	printf("The integer representation of tetri is: %hu\n", string2int(tetri));
	printf("The integer representation of tetri is: %hu\n", string2int(tetri2));
	printf("The integer representation of tetri is: %hu\n", string2int_alt(tetri));
	printf("The integer representation of tetri is: %hu\n", string2int_alt(tetri2));
	return (0);
}
