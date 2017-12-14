#include "fillit.h"

void build_array(int *tlib, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		tlib[i] = s[i] - '0';	
		i++;
	}
}

void	build_tetrimino_library(int tets[19][8])
{
	int	i;

	i = 0;
	build_array(tets[i++], "00010203");
	build_array(tets[i++], "00102030");
	build_array(tets[i++], "10200111");
	build_array(tets[i++], "00011112");
	build_array(tets[i++], "00101121");
	build_array(tets[i++], "10011102");
	build_array(tets[i++], "00100111");
	build_array(tets[i++], "10011121");
	build_array(tets[i++], "00011102");
	build_array(tets[i++], "00102011");
	build_array(tets[i++], "10011112");
	build_array(tets[i++], "00100102");
	build_array(tets[i++], "00102021");
	build_array(tets[i++], "10110212");
	build_array(tets[i++], "00011121");
	build_array(tets[i++], "00101112");
	build_array(tets[i++], "00102001");
	build_array(tets[i++], "00010212");
	build_array(tets[i++], "20011121");
}
