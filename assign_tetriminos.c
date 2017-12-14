/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:25:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 15:44:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino *build_tet_struct(int *tlib)
{
	t_tetrimino	*tetrimino;
	
	tetrimino = malloc(sizeof(t_tetrimino));
	tetrimino->coordinates = malloc(sizeof(int) * 8);
	ft_memcpy(tetrimino->coordinates, tlib, sizeof(int) * 8);
	return (tetrimino);
}

t_tetrimino	**assign_tetriminos(int map_count,
int coordinates[map_count][8], int tlib[19][8])
{
	t_tetrimino **tetriminos;
	int i;
	int j;

	tetriminos = malloc((sizeof(t_tetrimino *) * (map_count + 1)));
	i = 0;
	while (i < map_count)
	{
		j = 0;
		while (j < 19)
		{
			if (check_for_match(coordinates[i], tlib[j]))
			{
				tetriminos[i] = build_tet_struct(tlib[j]);
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
