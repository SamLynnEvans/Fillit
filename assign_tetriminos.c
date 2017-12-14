/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:25:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 12:09:06 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**assign_tetriminos(int map_count,
int coordinates[map_count][8], int tlib[19][8])
{
	int **tetriminos;
	int i;
	int j;

	tetriminos = malloc((sizeof(int *) * (map_count + 1)));
	i = 0;
	while (i < map_count)
	{
		j = 0;
		while (j < 19)
		{
			if (check_for_match(coordinates[i], tlib[j]))
			{
				tetriminos[i] = malloc(sizeof(int) * 8);
				ft_memcpy(tetriminos[i], tlib[j], sizeof(int) * 8);
				break ;
			}
			j++;
		}
		if (j == 19)
			return (NULL);
		i++;
	}
	tetriminos[i] = 0;
	return (tetriminos);
}
