#include "fillit.h"
#include <stdio.h>

void build_array(int *tlib, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		tlib[i] = s[i] - '0';	
		i++;
	}
}

void	build_tetrimino_library(int tets[19][8])
{
	int	i;

	i = 0;
	build_array(tets[i++], "00010203");
	build_array(tets[i++], "00102030");
	build_array(tets[i++], "10200111");
	build_array(tets[i++], "00011112");
	build_array(tets[i++], "00101121");
	build_array(tets[i++], "10011102");
	build_array(tets[i++], "00100111");
	build_array(tets[i++], "10011121");
	build_array(tets[i++], "00011102");
	build_array(tets[i++], "00102011");
	build_array(tets[i++], "10011112");
	build_array(tets[i++], "00100102");
	build_array(tets[i++], "00102021");
	build_array(tets[i++], "10110212");
	build_array(tets[i++], "00011121");
	build_array(tets[i++], "00101112");
	build_array(tets[i++], "00102001");
	build_array(tets[i++], "00010212");
	build_array(tets[i++], "20011121");
}

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

int	check_for_match(int *input_coordinates, int *tlib_coordinates)
{
	int	i;
	int x;
	int y;

	x = input_coordinates[0] - tlib_coordinates[0];
	y = input_coordinates[1] - tlib_coordinates[1];
	i = 0;
	while (i < 8)
	{
		input_coordinates[i] -= x;
		input_coordinates[i + 1] -= y;
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		if (input_coordinates[i] != tlib_coordinates[i])
				return (0);
		i++;
	}
	return (1);
} 

int	**assign_tetriminos(int map_count, int coordinates[map_count][8], int tlib[19][8])
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
		y = row + tetrimino[i+1];
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
		y = row + tetrimino[i+1];
		square[y][x] = '.';
		i += 2;
	}
}

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
