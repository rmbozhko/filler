/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:15:09 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:15:12 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_update_vars(int *i, int *j, int *y, int *x)
{
	*i = 0;
	*j += 1;
	*y += 1;
	*x = g_bot->start_x_val;
}

static void		ft_check_coord(int x, int y, int i, int j)
{
	(i >= g_bot->piece_width) ? ft_update_vars(&i, &j, &y, &x) : 0;
	if (j >= g_bot->piece_height || y >= g_bot->field_height)
		return ;
	if (g_bot->piece[j][i] == '*')
	{
		if (F_O_S || x + (g_bot->piece_width - i) > g_bot->field_width
			|| y + (g_bot->piece_height - j) > g_bot->field_height)
		{
			g_bot->sign_met = 10;
			return ;
		}
		else if (F_M_S)
		{
			if (++(g_bot->sign_met) > 1)
			{
				g_bot->sign_met += 10;
				return ;
			}
			return (ft_check_coord(++x, y, ++i, j));
		}
		else if (F_DOT)
			return (ft_check_coord(++x, y, ++i, j));
	}
	else if (g_bot->piece[j][i] == '.' && (F_DOT || F_M_S || F_O_S))
		return (ft_check_coord(++x, y, ++i, j));
}

void			ft_try_piece(int x, int y)
{
	while (y < g_bot->field_height)
	{
		x = 0;
		while (x < g_bot->field_width)
		{
			g_bot->sign_met = 0;
			if (g_bot->field_height - y < g_bot->piece_height)
				break ;
			g_bot->start_x_val = x;
			g_bot->answer_x = x;
			g_bot->answer_y = y;
			ft_check_coord(x, y, 0, 0);
			(g_bot->sign_met == 1) ? ft_determine_best_option() : 0;
			if (g_bot->field_width - x >= g_bot->piece_width)
				x++;
			else
			{
				x = 0;
				y++;
			}
		}
		y++;
	}
}
