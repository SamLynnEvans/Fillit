#include "fillit.h"

int check_format(char *buff)
{
	int		i;
	int		offset;

	offset = -1;
	i = 0;
	while (buff[i])
	{
		if ((i + 1) % 21 == 0 && buff[i] != '\n')
			return (-1);
		else if ((i - offset) % 5 == 0 && buff[i] != '\n')
			return (-1);
		else if (buff[i] != '#' && buff[i] != '.' && (i + 1) % 21 != 0 && (i - offset) % 5 != 0)
			return (-1);
		if ((i + 1) % 21 == 0)
			offset++;
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (-1);
	return (offset + 2);
}
