/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:14:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:14:18 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bot		*g_bot;

int		main(void)
{
	char		*line;

	g_bot = (t_bot*)malloc(sizeof(t_bot*));
	g_bot->fd = 0;
	get_next_line(g_bot->fd, &line);
	g_bot->my_sign = (line[10] == '2') ? 'X' : 'O';
	g_bot->opp_sign = (g_bot->my_sign == 'X') ? 'O' : 'X';
	g_bot->start_x_val = 0;
	g_bot->answer = (t_answer*)malloc(sizeof(t_answer*));
	while (get_next_line(g_bot->fd, &line))
	{
		g_bot->field = ft_create_field(line);
		g_bot->piece = ft_create_piece();
		g_bot->answer->x = 0;
		g_bot->answer->y = 0;
		g_bot->answer->square = g_bot->field_height + g_bot->field_width;
		ft_try_piece(0, 0);
		ft_print_answer();
	}
	return (0);
}
