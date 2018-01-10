
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

t_tet	**prepare_for_placement(unsigned short int *tet_codes)
{
	t_tet **spatial_tets;
	
	int	i;

	i = 0;
	while(tet_codes[i++])
	{
		
	}
	spatial_tets = malloc(sizeof(t_tet*) * i + 1);
	i = -1;
	while(tet_codes[++i])
	{
		*(spatial_tets + i) = initialize_spatial_tet(tet_codes[i], i);
	}
	spatial_tets[i] = NULL;
	return (spatial_tets);
}

