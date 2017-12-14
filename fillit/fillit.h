/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 22:13:34 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1000

typedef struct	s_tetrimino
{
	int *coordinates;
	int	y_max;
	int	x_max;
	int order;
}				t_tetrimino;

void			print_square(char **square, int size);
void			build_tetrimino_library(int tets[19][8]);
int				get_size(int map_count);
int				check_format(char *buff);
int				get_coordinates(char *buff, int map_count,
int coordinates[map_count][8]);
int				check_for_match(int *input_coordinates, int *tlib_coordinates);
t_tetrimino		**assign_tetriminos(int map_count,
int	coordinates[map_count][8], int tlib[19][8]);
int				put_tetrimino(t_tetrimino *tetrimino,
char **square, int row, int col);
void			remove_tetrimino(t_tetrimino *tetrimino,
char **square, int row, int col);

#endif
