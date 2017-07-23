#include "filler.h"

static	char		**ft_create_bid_arr(int height, int flag)
{
	char		**temp;
	char		*line;
	int			counter;

	counter = -1;
	temp = (char**)malloc(sizeof(char*) * height + 1);
	while (++counter < height)
	{
		get_next_line(g_bot->fd, &line);
		temp[counter] = ft_strdup(((flag) ? ft_strsplit(line, ' ')[1] : line));
	}
	temp[counter] = NULL;
	return (temp);
}

char				**ft_create_piece(void)
{
	char		*line;

	get_next_line(g_bot->fd, &line);
	g_bot->piece_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	g_bot->piece_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	return(ft_create_bid_arr(g_bot->piece_height, 0));
}

char				**ft_create_field(char *str)
{
	char		*line;

	g_bot->field_height = ft_atoi(ft_strsplit(str, ' ')[1]);
	g_bot->field_width = ft_atoi(ft_strsplit(str, ' ')[2]);
	get_next_line(g_bot->fd, &line);
	return (ft_create_bid_arr(g_bot->field_height, 1));
}