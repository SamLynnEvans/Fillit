/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:25:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 16:06:42 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino *build_tet_struct(int *tlib, int order, int map_count)
{
	t_tetrimino	*tetrimino;
	int	i;
	int	x;
	int	y;

	i = 2;
	tetrimino = malloc(sizeof(t_tetrimino));
	tetrimino->coordinates = malloc(sizeof(int) * 8);
	ft_memcpy(tetrimino->coordinates, tlib, sizeof(int) * 8);
	x = tlib[0];
	y = tlib[1];	
	while (i < 8)
	{
		x = ((tlib[i] > x) ? tlib[i] : x);
		y = ((tlib[i + 1] > y) ? tlib[i + 1] : y);
		i += 2;
	}
	tetrimino->y_max = y;
	tetrimino->x_max = x;
	tetrimino->order = order;
	tetrimino->last_piece = ((order + 1 == map_count) ? 1 : 0);
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
				tetriminos[i] = build_tet_struct(tlib[j], i, map_count);
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
