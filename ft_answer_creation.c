/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_answer_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:15:51 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:28:09 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static intmax_t		ft_abs(intmax_t x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void				ft_print_answer(void)
{
	ft_putstr_fd(ft_itoa(g_bot->answer->y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(g_bot->answer->x), 1);
	ft_putstr_fd("\n", 1);
}

static int			ft_calc_square(int y, int x)
{
	int		max_distance;
	int		res;

	max_distance = g_bot->field_width + g_bot->field_height;
	while (g_bot->field[++y])
	{
		x = -1;
		while (g_bot->field[y][++x])
		{
			if (g_bot->field[y][x] == g_bot->opp_sign)
			{
				res = ft_abs(x - g_bot->answer_x) + ft_abs(y - g_bot->answer_y);
				max_distance = (res < max_distance) ? res : max_distance;
			}
		}
	}
	return (max_distance);
}

void				ft_determine_best_option(void)
{
	int				square;

	square = ft_calc_square(-1, -1);
	if (square < g_bot->answer->square)
	{
		g_bot->answer->y = g_bot->answer_y;
		g_bot->answer->x = g_bot->answer_x;
		g_bot->answer->square = square;
	}
}
