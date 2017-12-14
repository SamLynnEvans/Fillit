#include "fillit.h"

int	get_coordinates(char *buff, int map_count, int coordinates[map_count][8])
{	
	int	i;
	int	j;
	int	c;

	c = 0;
	i = -1;
	j = 0;
	while (buff[++i])
	{
		if (buff[i] == '#')
		{
			coordinates[j][c++] = i % 5;
			coordinates[j][c++] = i / 5;
		}
		if (i == 20)
		{
			ft_memmove(buff, &buff[21], ft_strlen(buff) + 1);
			if (c != 8)
				return (0);
			c = 0;
			j++;
			i = -1;
		}
	}
	return ((c == 8) ? 1 : 0);	
}
