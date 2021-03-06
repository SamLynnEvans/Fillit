/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdebug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:52:43 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/06 16:57:11 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intdebug(int a, char *name)
{
	write(1, "\x1b[33m ***DEBUG*** ", 19);
	write(1, "\x1b[0m", 5);
	ft_putstr(name);
	write(1, " == ", 4);
	ft_putnbr(a);
	write(1, "\n", 1);
}
