/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_remove_tet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:36:57 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 21:53:31 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_tetrimino(t_tetrimino *tetrimino, char **square, int row, int col)
{
	int	i;
	int x;
	int	y;

	i = 0;
	while (i < 8)
	{
		x = col + tetrimino->coordinates[i];
		y = row + tetrimino->coordinates[i + 1];
		if (square[y][x] != '.')
			return (0);
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		x = col + tetrimino->coordinates[i];
		y = row + tetrimino->coordinates[i + 1];
		square[y][x] = tetrimino->order + 'A';
		i += 2;
	}
	return (1);
}

void	remove_tetrimino(t_tetrimino *tetrimino,
char **square, int row, int col)
{
	int	i;
	int x;
	int	y;

	i = 0;
	while (i < 8)
	{
		x = col + tetrimino->coordinates[i];
		y = row + tetrimino->coordinates[i + 1];
		square[y][x] = '.';
		i += 2;
	}
}
