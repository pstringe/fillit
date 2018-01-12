
#include "fillit.h"

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

