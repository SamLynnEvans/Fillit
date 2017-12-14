/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_remove_tet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:36:57 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 11:38:51 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	put_tetrimino(int *tetrimino, char **square, int row, int col, int alpha, int size)
{
	int	i;
	int x;
	int	y;

	i = 0;
	while (i < 8)
	{
		x = col + tetrimino[i];
		y = row + tetrimino[i + 1];
		if (y >= size || x >= size || square[y][x] != '.')
			return (0);
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		x = col + tetrimino[i];
		y = row + tetrimino[i + 1];
		square[y][x] = alpha + 'A';
		i += 2;
	}
	return (1);
}

void	remove_tetrimino(int *tetrimino, char **square, int row, int col)
{
	int	i;
	int x;
	int	y;

	i = 0;
	while (i < 8)
	{
		x = col + tetrimino[i];
		y = row + tetrimino[i + 1];
		square[y][x] = '.';
		i += 2;
	}
}
