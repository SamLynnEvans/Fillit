/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:59:23 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/07 15:43:25 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttstr_del(t_list **list)
{
	t_list	*tmp;
	int		count;
	char	*dst;

	count = 0;
	tmp = *list;
	while (tmp != NULL)
	{
		count += tmp->content_size;
		tmp = tmp->next;
	}
	dst = (char *)ft_memalloc(count + 1);
	while (*list != NULL)
	{
		tmp = *list;
		ft_strcat(dst, tmp->content);
		free(tmp->content);
		*list = (*list)->next;
		free(tmp);
	}
	dst[count] = '\0';
	return (dst);
}
