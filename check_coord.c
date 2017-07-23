#include "filler.h"

static	void		ft_update_vars(int *i, int *j, int *y, int *x)
{
	(*i) = 0;
	(*j) += 1;
	(*y) += 1;
	(*x) = g_bot->start_x_val;
}

static void		ft_check_coord(int x, int y, int i, int j)
{
	(i >= g_bot->piece_width) ? ft_update_vars(&i, &j, &y, &x) : 0;
	if (j >= g_bot->piece_height || y >= g_bot->field_height)
		return ;
	if (g_bot->piece[j][i] == '*')
	{
		if (F_M_S || x + (g_bot->piece_width - i) > g_bot->field_width
			|| y + (g_bot->piece_height - j) > g_bot->field_height)
		{
			g_bot->sign_met += 10;
			return ;
		}
		else if (F_M_S)
		{
			if ((++g_bot->sign_met) > 1) 
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

static void		ft_try_piece(int x, int y)
{
	// g_bot->sign_met = 0;
	// if ((g_bot->field_height - y < g_bot->piece_height) || (y > g_bot->field_height))
	// 	return ;
	// g_bot->start_x_val = x;
	// g_bot->answer_x = x;
	// g_bot->answer_y = y;
	// ft_check_coord(x, y, 0, 0);
	// (g_bot->sign_met == 1) ? ft_determine_best_option() : 0;
	// (g_bot->field_width - x > g_bot->piece_width) ? ft_try_piece(++x, y) : ft_try_piece(0, ++y);
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
			ft_check_coord(x, y, 0, 0);
			(g_bot->sign_met == 1) ? ft_determine_best_option() : 0;
			if (g_bot->field_width - x >= g_bot->piece_width)
				x++;
			else
			{
				x = 0;
				y++;
				// break ;
			}
			// (g_bot->field_width - x >= g_bot->piece_width) (g_bot->field_width - x >= g_bot->piece_width) ? ft_try_piece(++x, y, g_bot, fd) : ft_try_piece(0, ++y, g_bot, fd);
		}
		y++;
	}
}

void		ft_check_piece(void)
{
	g_bot->answer->x = 0;
	g_bot->answer->y = 0;
	g_bot->answer->square = g_bot->field_height + g_bot->field_width;
	ft_try_piece(0, 0);
}
/*
static void		ft_try_piece(int x, int y, t_bot *g_bot, int fd)
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
			ft_check_coord(x, y, 0, 0, g_bot, fd);
			(g_bot->sign_met == 1) ? ft_determine_best_option(g_bot, fd) : 0;
			if (g_bot->field_width - x >= g_bot->piece_width)
				x++;
			else
			{
				x = 0;
				y++;
				// break ;
			}
			// (g_bot->field_width - x >= g_bot->piece_width) (g_bot->field_width - x >= g_bot->piece_width) ? ft_try_piece(++x, y, g_bot, fd) : ft_try_piece(0, ++y, g_bot, fd);
		}
		y++;
	}
}

void		ft_check_piece(t_bot *g_bot, int fd)
{
	g_bot->answer->x = 0;
	g_bot->answer->y = 0;
	g_bot->answer->square = g_bot->field_height + g_bot->field_width;
	ft_try_piece(0, 0, g_bot, fd);
}

void		ft_check_coord(int x, int y, int i, int j, t_bot *g_bot, int fd)
{
	if (i >= g_bot->piece_width)
	{
		i = 0;
		j++;
		y++;
		x = g_bot->start_x_val;
	}
	if (j >= g_bot->piece_height || y >= g_bot->field_height)
		return ;
	if (g_bot->piece[j][i] == '*')
	{
		if (g_bot->field[y][x] == g_bot->opp_sign
			|| x + (g_bot->piece_width - i) > g_bot->field_width
			|| y + (g_bot->piece_height - j) > g_bot->field_height)
		{
			g_bot->sign_met = 10;
			return ;
		}
		else if (g_bot->field[y][x] == g_bot->my_sign)
		{
			g_bot->sign_met += 1;
			if (g_bot->sign_met > 1)
			{
				g_bot->sign_met += 10;
				return ;
			}
			return (ft_check_coord(++x, y, ++i, j, g_bot, fd));
		}
		else if (g_bot->field[y][x] == '.')
			return (ft_check_coord(++x, y, ++i, j, g_bot, fd));
	}
	else if (g_bot->piece[j][i] == '.' && (g_bot->field[y][x] == '.'
		|| g_bot->field[y][x] == g_bot->my_sign || g_bot->field[y][x] == g_bot->opp_sign))
		return (ft_check_coord(++x, y, ++i, j, g_bot, fd));
}
*/