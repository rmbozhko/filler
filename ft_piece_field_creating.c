/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_field_creating.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:18:34 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:18:48 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	char		**ft_create_bid_arr(int height, int flag)
{
	char		**temp;
	char		*line;
	int			counter;

	counter = -1;
	temp = (char**)malloc(sizeof(char*) * height + 1);
	while (++counter < height)
	{
		get_next_line(g_bot->fd, &line);
		temp[counter] = (flag) ? ft_strsplit(line, ' ')[1] : ft_strdup(line);
	}
	temp[counter] = NULL;
	return (temp);
}

char				**ft_create_piece(void)
{
	char		*line;

	get_next_line(g_bot->fd, &line);
	g_bot->piece_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	g_bot->piece_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	return (ft_create_bid_arr(g_bot->piece_height, 0));
}

char				**ft_create_field(char *line)
{
	g_bot->field_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	g_bot->field_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	get_next_line(g_bot->fd, &line);
	return (ft_create_bid_arr(g_bot->field_height, 1));
}
