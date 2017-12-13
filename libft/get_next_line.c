/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:36:45 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/07 21:02:49 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		nl_lst_builder(t_list **list, char *str, int size)
{
		t_list	*tmp;
		int		i;

		i = -1;
		tmp = *list;
		while (str[++i])
			if (str[i] == '\n')
				break ;
		if (str[i] == '\0')
			i = NO_NL;
		if (tmp == NULL && i != NO_NL)
			*list = ft_lstnew((void *)str, (size_t)i);
		else if (tmp == NULL)
			*list = ft_lstnew((void *)str, (size_t)size);
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			if (i != NO_NL)
				tmp->next = ft_lstnew((void *)str, (size_t)i);
			else
				tmp->next = ft_lstnew((void *)str, (size_t)size);
		}
		return (i + 1);
}

char	*ft_lsttstr_del(t_list **list)
{
	t_list	*tmp;
	int	count;
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
		ft_strncat(dst, tmp->content, tmp->content_size);
		free(tmp->content);
		*list = (*list)->next;
		free(tmp);
	}
	dst[count] = '\0';
	return (dst);
}

int		read_into_gets(char **leftover, int fd, t_list **list, char **line)
{
	int			ret;
	char			buff[BUFF_SIZE + 1];
	int			new_line_index;
	int			count;
	
	count = 0;
	new_line_index = 0;
	while (new_line_index == 0 && (ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		count++;
		buff[ret] = '\0';
		new_line_index = nl_lst_builder(list, buff, ret);
	}
	if (ret == 0 && (count == 0))
		return (1);
	*leftover = ft_strsub(buff, new_line_index, ft_strlen(buff + 1));
	*line = ft_lsttstr_del(list);
	return (0);
}

int		check_leftover(char **leftover, char **line, t_list **list)
{
	char	*tmp;
	int	i;

	i = 0;
	if (**leftover == '\0')
		return (0);
	tmp = *leftover;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			*line = ft_strsub(*leftover, 0, i);
			tmp = ft_strsub(*leftover, i + 1, ft_strlen(*leftover));
			free(*leftover);
			*leftover = tmp;
			return (EMPTY_LINE);
		}
		i++;
	}
	*list = ft_lstnew((void *)*leftover, ft_strlen(*leftover) + 1);
	free(*leftover);
	return (GET_NEXT_LINE);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX];
	t_list		*list;
	int			check;	
	int			end;
	
	list = NULL;
	end = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (leftover[fd] == NULL || !(check = check_leftover(&leftover[fd], line, &list)))
		end = read_into_gets(&leftover[fd], fd, &list, line);
	else if (check == GET_NEXT_LINE)
		end = read_into_gets(&leftover[fd], fd, &list, line);
	if (end == 1)
		return (0);
	if (end == -1)
		return (-1);
	return (1);
}
