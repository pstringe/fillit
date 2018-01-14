
#include "fillit.h"

void		print_tet_set(t_ets *tetrs)
{
	int i;
	ft_putstr("head:\t");
	ft_putnbr(tetrs->head);
	ft_putendl("\n");
	ft_putstr("no_of_tets:\t");
	ft_putnbr(tetrs->no_of_tets);
	ft_putendl("\n");

	i = -1;
	while(tetrs->tets[++i])
	{
		print_encoded_tetromino(tetrs->tets[i]->value);
	}
}

t_tet	*initialize_spatial_tet(unsigned short int code, int order)
{
	t_tet	*tet;
	tet = malloc(sizeof(t_tet*));
	tet->order = order;
	tet->value = code;
	tet->origin = NULL;
	tet->second = NULL;
	tet->third	= NULL;
	tet->fourth = NULL;
	return (tet);
}

t_ets	*prepare_for_placement(unsigned short int *tet_codes)
{
	t_ets *tetrs;
	t_tet **spatial_tets;
	
	int	i;

	i = 0;
	while(tet_codes[i++])
	{
		
	}
	tetrs = malloc(sizeof(t_ets*));
	spatial_tets = malloc(sizeof(t_tet*) * i + 1);
	i = -1;
	while(tet_codes[++i])
	{
		*(spatial_tets + i) = initialize_spatial_tet(tet_codes[i], i);
	}	
	spatial_tets[i] = NULL;
	tetrs->head = 0;
	tetrs->no_of_tets = i;
	tetrs->tets = spatial_tets;
	return (tetrs);
}

