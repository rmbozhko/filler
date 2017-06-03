#include "filler.h"

static void		ft_try_piece(int x, int y, t_bot *bot, int fd)
{
	bot->sign_met = 0;
	if (bot->field_height - y < bot->piece_height || y >= bot->field_height)
		return ;
	bot->start_x_val = x;
	bot->answer_x = x;
	bot->answer_y = y;
	ft_check_coord(x, y, 0, 0, bot, fd);
	// ft_putstr_fd("Bot->sign_met: ", fd);
	// ft_putstr_fd(ft_itoa(bot->sign_met), fd);
	// ft_putstr_fd("\n", fd);
	(bot->sign_met == 1) ? ft_create_solution(bot, fd) : 0;
	//ft_putstr_fd(ft_strjoin(ft_strjoin(ft_itoa(bot->answer_y), ft_itoa(bot->answer_x)), "\n"), fd) : 0;
	(bot->field_width - x > bot->piece_width) ? ft_try_piece(++x, y, bot, fd) : ft_try_piece(0, ++y, bot, fd);
}

void		ft_check_piece(t_bot *bot, int fd)
{
	int		x;
	int		y;

	y = -1;
	while (bot->field[++y])
	{
		x = -1;
		while (bot->field[y][++x])
		{
			if (bot->field[y][x] != bot->opp_sign)
				return (ft_try_piece(x, y, bot, fd));
		}
	}
}