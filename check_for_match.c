/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:27:59 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 11:28:26 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (input_coordinates[i] - x != tlib_coordinates[i])
			return (0);
		if (input_coordinates[i + 1] - y != tlib_coordinates[i + 1])
			return (0);
		i += 2;
	}
	return (1);
}
