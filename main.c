#include "filler.h"

int		main(int argc, char **argv)
{
	char		*line;
	t_bot		bot;
	int 		fd;

	fd = open("test.txt", O_WRONLY);
	bot.fd = fd;
	get_next_line(0, &line);
	bot.my_sign = (ft_strsplit(line, ' ')[2][1] == '1') ? 'O' : 'X';
	bot.opp_sign = OPP_SIGN(bot.my_sign);
	bot.start_x_val = 0;
	bot.answer_list = (t_answer*)malloc(sizeof(t_answer*));
	bot.answer_list = NULL;
	while (get_next_line(0, &line) > 0)
	{
		bot.field = ft_create_field(&bot, line);
		// ft_putstr_fd("\n", fd);
		bot.piece = ft_create_piece(&bot);
		ft_check_piece(&bot, fd);
		ft_get_best_position(&bot, fd);
	}
	return (0);
}