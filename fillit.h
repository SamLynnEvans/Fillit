#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 1000

void	build_tetrimino_library(int tets[19][8]);
int		check_format(char *buff);
int	get_coordinates(char *buff, int map_count, int coordinates[map_count][8]);

#endif
