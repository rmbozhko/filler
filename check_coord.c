#include "filler.h"

void		ft_get_best_position(t_bot *bot, int fd)
{
	t_answer		*temp;
	int				best_answer;

	temp = (t_answer*)malloc(sizeof(t_answer*));
	best_answer = bot->answer_list->square;
	temp = bot->answer_list->next;
	while (temp)
	{
		if (temp->square < best_answer)
		{
			best_answer = temp->square;
			bot->answer_x = temp->x;
			bot->answer_y = temp->y;
		}
		temp = temp->next;
	}
	// ft_putstr_fd("Final answer: ", fd);
	// ft_putstr_fd(ft_itoa(best_answer), fd);
	ft_putstr_fd(ft_itoa(bot->answer_y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(bot->answer_x), 1);
	ft_putstr_fd("\n", 1);
}

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
	//|| x + bot->piece_width > bot->field_width || x + bot->piece_height > bot->field_height) // Pieces strike out of the map.
		return ;
	if (bot->piece[j][i] == '*')
	{
		if (bot->field[y][x] == bot->my_sign)
		{
			ft_putstr_fd("\nHERE: ", fd);
			ft_putstr_fd(ft_strjoin(ft_itoa(y), ft_itoa(x)), fd);
			ft_putstr_fd("\n", fd);
			ft_putstr_fd("\nBesides: ", fd);
			ft_putstr_fd(ft_strjoin(ft_itoa(j), ft_itoa(i)), fd);
			ft_putstr_fd("\n", fd);
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
