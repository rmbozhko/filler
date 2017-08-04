#include "filler.h"

static	char		**ft_create_bid_arr(int height, int flag, int fd)
{
	char		**temp;
	char		*line;
	int			counter;

	counter = -1;
	temp = (char**)malloc(sizeof(char*) * height + 1);
	while (++counter < height)
	{
		get_next_line(g_bot->fd, &line, fd);
		temp[counter] = (flag) ? ft_strsplit(line, ' ')[1] : ft_strdup(line);
	}
	temp[counter] = NULL;
	return (temp);
}

char				**ft_create_piece(int fd)
{
	char		*line;

	get_next_line(g_bot->fd, &line, fd);
	g_bot->piece_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	g_bot->piece_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	return(ft_create_bid_arr(g_bot->piece_height, 0, fd));
}

char				**ft_create_field(char *line, int fd)
{
	g_bot->field_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	g_bot->field_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	get_next_line(g_bot->fd, &line, fd);
	return (ft_create_bid_arr(g_bot->field_height, 1, fd));
}