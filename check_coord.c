#include "filler.h"

void		ft_check_coord(int x, int y, int i, int j, t_bot *bot, int fd)
{
	if (i >= bot->piece_width)
	{
		i = 0;
		j++;
		y++;
		x = bot->start_x_val;
	}
	if (j >= bot->piece_height || y >= bot->field_height)
		return ;
	if (bot->piece[j][i] == '*')
	{
		if (bot->field[y][x] == bot->my_sign)
		{
			// ft_putstr_fd("\nHERE: ", fd);
			// ft_putstr_fd(ft_strjoin(ft_itoa(y), ft_itoa(x)), fd);
			// ft_putstr_fd("\n", fd);
			// ft_putstr_fd("\nBesides: ", fd);
			// ft_putstr_fd(ft_strjoin(ft_itoa(j), ft_itoa(i)), fd);
			// ft_putstr_fd("\n", fd);
			bot->sign_met += 1;
			if (bot->sign_met > 1)
				return ;
			ft_check_coord(++x, y, ++i, j, bot, fd);
		}
		else if (bot->field[y][x] == '.')
			ft_check_coord(++x, y, ++i, j, bot, fd);
		else if (bot->field[y][x] == bot->opp_sign)
		{
			bot->sign_met = 2;
			return ;
		}
	}
	else if (bot->piece[j][i] == '.' && (bot->field[y][x] == '.'
		|| bot->field[y][x] == bot->my_sign || bot->field[y][x] == bot->opp_sign))
		ft_check_coord(++x, y, ++i, j, bot, fd);
}
