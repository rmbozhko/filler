#include "filler.h"

t_bot		*g_bot;

int		main(void)
{
	char		*line;
	int			fd;

	fd = open("/nfs/2016/r/rbozhko/Desktop/projects/filler/test/filler.txt", O_WRONLY);
	g_bot = (t_bot*)malloc(sizeof(t_bot*));
	g_bot->fd = 0;
	get_next_line(g_bot->fd, &line, fd);
	// g_bot->my_sign = (ft_strsplit(line, ' ')[2][1] == '1') ? 'O' : 'X';
	g_bot->my_sign = (line[10] == '2') ? 'X' : 'O';
	g_bot->opp_sign = (g_bot->my_sign == 'X') ? 'O' : 'X';
	g_bot->start_x_val = 0;
	g_bot->answer = (t_answer*)malloc(sizeof(t_answer*));
	while (get_next_line(g_bot->fd, &line, fd))
	{
		g_bot->field = ft_create_field(line, fd);
		g_bot->piece = ft_create_piece(fd);
		ft_check_piece(fd);
		ft_print_answer(fd);
	}
	return (0);
}

