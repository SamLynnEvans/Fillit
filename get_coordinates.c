/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:29:32 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 11:30:50 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
