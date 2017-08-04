/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:58:24 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/22 15:58:27 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_node	*ft_create(int fd)
{
	t_node	*temp;

	temp = (t_node*)malloc(sizeof(t_node*));
	temp->fd = fd;
	temp->next = NULL;
	return (temp);
}

static int		ft_rtn_line(t_node *temp, char buff[], char **line)
{
	if (ft_strchr(temp->str, '\n'))
	{
		*line = ft_strsub(temp->str, 0, S_C_SUB);
		temp->str += S_C_SUB;
		return (1);
	}
	else if ((!(ft_strchr(temp->str, '\n'))) && ft_strlen(buff) == 0)
	{
		*line = ft_strdup(temp->str);
		ft_memset(temp->str, 0, ft_strlen(temp->str));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_node		*head = NULL;
	int					bytes;
	char				buff[BUFF_SIZE + 1];

	if (IF_FP || IF_SP)
		return (-1);
	!(head) ? head = ft_create(fd) : 0;
	ft_memset(head->str = (char*)malloc(BUFF_SIZE + 1), 0, BUFF_SIZE + 1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		(bytes < BUFF_SIZE) ? buff[bytes] = '\0' : 0;
		head->str = ft_strjoin(head->str, buff);
		(head->str[0] == '\n') ? head->str += 1 : 0;
		if (ft_strlen(head->str) > 0)
		{
			if ((ft_strchr(head->str, 10)) ||
				(!ft_strchr(head->str, 10) && ft_strlen(buff) == 0))
				if (ft_rtn_line(head, buff, line) == 1)
					return (1);
		}
		else if (bytes == 0)
			return (0);
	}
	return (0);
}
