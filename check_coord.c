#include "filler.h"

static	void		ft_update_vars(int *i, int *j, int *y, int *x)
{
	*i = 0;
	*j += 1;
	*y += 1;
	*x = g_bot->start_x_val;
}

static void		ft_check_coord(int x, int y, int i, int j, int fd)
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
			return (ft_check_coord(++x, y, ++i, j, fd));
		}
		else if (F_DOT)
			return (ft_check_coord(++x, y, ++i, j, fd));
	}
	else if (g_bot->piece[j][i] == '.' && (F_DOT || F_M_S || F_O_S))
		return (ft_check_coord(++x, y, ++i, j, fd));
}

static void		ft_try_piece(int x, int y, int fd)
{
	while (y < g_bot->field_height)
	{
		x = 0;
		while (x < g_bot->field_width)
		{
			g_bot->sign_met = 0;
			// if (g_bot->field_height - y < g_bot->piece_height || y >= g_bot->field_height) //(g_bot->field_height - y <= g_bot->piece_height || y >= g_bot->field_height)
			// 	return ;
			if (g_bot->field_height - y < g_bot->piece_height)
				break ;
			g_bot->start_x_val = x;
			g_bot->answer_x = x;
			g_bot->answer_y = y;
			ft_check_coord(x, y, 0, 0, fd);
			(g_bot->sign_met == 1) ? ft_determine_best_option(fd) : 0;
			if (g_bot->field_width - x >= g_bot->piece_width)
				x++;
			else
			{
				x = 0;
				y++;
				// break ;
			}
			// (g_bot->field_width - x >= g_bot->piece_width) (g_bot->field_width - x >= g_bot->piece_width) ? ft_try_piece(++x, y, bot, fd) : ft_try_piece(0, ++y, bot, fd);
		}
		y++;
	}
}

void		ft_check_piece(int fd)
{
	g_bot->answer->x = 0;
	g_bot->answer->y = 0;
	g_bot->answer->square = g_bot->field_height + g_bot->field_width;
	ft_try_piece(0, 0, fd);
}