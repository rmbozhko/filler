#include "filler.h"

t_bot		*g_bot;

int		main(void)
{
	char		*line;

	g_bot = (t_bot*)malloc(sizeof(t_bot*));
	g_bot->fd = 0;
	get_next_line(g_bot->fd, &line);
	g_bot->my_sign = (ft_strsplit(line, ' ')[2][1] == '1') ? 'O' : 'X';
	g_bot->opp_sign = OPP_SIGN(g_bot->my_sign);
	g_bot->start_x_val = 0;
	g_bot->answer = (t_answer*)malloc(sizeof(t_answer*));
	while (get_next_line(g_bot->fd, &line) > 0)
	{
		g_bot->sign_met = 0;
		g_bot->field = ft_create_field(line);
		g_bot->piece = ft_create_piece();
		ft_check_piece();
		ft_print_answer();
	}
	return (0);
}

