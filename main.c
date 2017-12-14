/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:02 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 11:36:35 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	backtrack_filler(int i, int **tetriminos, char **square, int row, int col, int size)
{
	if (col >= size)
	{
		row++;
		col = 0;
	}
	while (row < size)
	{
		if (put_tetrimino(tetriminos[i], square, row, col, i, size))
		{
			if (tetriminos[i + 1] == 0)
				return (1);
			else if (backtrack_filler(i + 1, tetriminos, square, row, col + 1, size))
				return (1);
			else
				remove_tetrimino(tetriminos[i], square, row, col);
		}
		col++;
		if (col >= size)
		{
			row++;
			col = 0;
		}
	}
	return (0);
}

int	solver(int **tetriminos, int size)
{
	char	**square;
	int		row;
	int		col;

	row = 0;
	square = malloc(sizeof(char *) * (size + 1));
	while (row < size)
	{
		col = 0;
		square[row] = malloc(sizeof(char) * size);
		while (col < size)
			square[row][col++] = '.';
		square[row][col] = '\0';
		row++;
	}
	square[row] = 0;
	if (!backtrack_filler(0, tetriminos, square, 0, 0, size))
	{
		free(square);
		return (0);
	}
	row = 0;
	while (row < size)
	{
		ft_putstr(square[row++]);
		ft_putchar('\n');
	}
	return (1);
}

int		setup_solver(char *buff, int map_count)
{
	int			tlib[19][8];
	int			coordinates[map_count][8];
	int			**tetriminos;
	int			size;

	size = 2;
	if (!get_coordinates(buff, map_count, coordinates))
		return (-1);
	build_tetrimino_library(tlib);
	if (!(tetriminos = assign_tetriminos(map_count, coordinates, tlib)))
		return (-1);
	while (!solver(tetriminos, size))
		size++;
	return (1);
}

int	main(int ac, char **argv)
{
	int			fd;
	int			map_count;
	int			ret;
	char		buff[BUFF_SIZE];

	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';	
		if ((map_count = check_format(buff)) == -1 || map_count > 26)
		{
			ft_putstr("error");
			return (1);
		}
		//control number 24 above!!!!!
		//close here
		//add errors for read, open, close etc
		if (setup_solver(buff, map_count) == -1)
			ft_putstr("ERROR");
	}
	else
		ft_putstr("change this message to usage error");
	return (0);
}
