/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:32:20 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 21:39:22 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **square, int size)
{
	int row;

	row = 0;
	while (row < size)
	{
		ft_putstr(square[row++]);
		ft_putchar('\n');
	}
}
