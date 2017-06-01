void		ft_check_piece(t_bot *bot)
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
				return (ft_try_piece(x, y, bot));
		}
	}
}

void		ft_try_piece(int x, int y, t_bot *bot)
{
	if (bot->field_height - y < bot->piece_height || y >= bot->field_height)
		return ;
	bot->start_x_val = x;
	bot->answer_x = x; // add following to the t_bot structure
	bot->answer_y = y; // add following to the t_bot structure
	ft_check_coord(x, y, 0, 0, bot);
	(bot->sign_met == 1) ? ft_create_solution(bot) : 0;
	(bot->field_width - x > bot->piece_width) ? ft_try_piece(++x, y, boy) : ft_try_piece(0, ++y, bot);
}