/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:02 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 15:58:55 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	backtrack_filler(int i, t_tetrimino **tetriminos, char **square, int size)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < size)
	{
		if (tetriminos[i]->y_max + row >= size)
			return (0);
		else if (tetriminos[i]->x_max + col >= size)
			col = size - 1;
		else if (put_tetrimino(tetriminos[i], square, row, col))
		{
			if (tetriminos[i + 1] == 0
			|| backtrack_filler(i + 1, tetriminos, square, size))
				return (1);
			remove_tetrimino(tetriminos[i], square, row, col);
		}
		if (++col >= size)
		{
			row++;
			col = 0;
		}
	}
	return (0);
}

int	solver(t_tetrimino **tetriminos, int size)
{
	char	**square;
	int		row;
	int		col;

	row = 0;
	if (!(square = malloc(sizeof(char *) * (size))))
		return (-1);
	while (row < size)
	{
		col = 0;
		if (!(square[row] = malloc(sizeof(char) * size)))
			return (-1);
		while (col < size)
			square[row][col++] = '.';
		square[row][col] = '\0';
		row++;
	}
	if (!backtrack_filler(0, tetriminos, square, size))
	{
		free(square);
		return (0);
	}
	print_square(square, size);
	return (1);
}


int	setup_solver(char *buff, int map_count)
{
	int				tlib[19][8];
	int				coordinates[map_count][8];
	t_tetrimino		**tetriminos;
	int				size;
	int				check;

	size = get_size(map_count);
	if (!get_coordinates(buff, map_count, coordinates))
		return (-1);
	build_tetrimino_library(tlib);
	if (!(tetriminos = assign_tetriminos(map_count, coordinates, tlib)))
		return (-1);
	while ((check = solver(tetriminos, size)) == 0)
		size++;
	return (check);
}

int	main(int ac, char **argv)
{
	int			fd;
	int			map_count;
	int			ret;
	char		buff[BUFF_SIZE];

	if (ac == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			exit(EXIT_SUCCESS);
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if ((map_count = check_format(buff)) == -1 || map_count > 26)
		{
			ft_putstr("error");
			exit(EXIT_SUCCESS);
		}
		close(fd);
		if (setup_solver(buff, map_count) == -1)
		{
			ft_putstr("error");
			exit(EXIT_SUCCESS);
		}
	}
	else
		ft_putstr("usage: fillit map_file\n");
	exit(EXIT_SUCCESS);
}
