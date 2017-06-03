#include "filler.h"

static	char		**ft_create_bid_arr(int height, int width, t_bot *bot, int flag)
{
	char		**temp;
	char		*line;
	int			counter;

	counter = -1;
	temp = (char**)malloc(sizeof(char) * height + 1);
	while (++counter < height)
	{
		get_next_line(0, &line);
		temp[counter] = ft_strdup(((flag) ? ft_strsplit(line, ' ')[1] : line));
		// ft_putstr_fd(temp[counter], bot->fd);
		// ft_putstr_fd("\n", bot->fd);
	}
	temp[counter] = NULL;
	return (temp);
}

char				**ft_create_piece(t_bot *bot)
{
	char		*line;

	get_next_line(0, &line);
	bot->piece_height = ft_atoi(ft_strsplit(line, ' ')[1]);
	// ft_putstr_fd(ft_itoa(bot->piece_height), bot->fd);
	// ft_putstr_fd("\t", bot->fd);
	bot->piece_width = ft_atoi(ft_strsplit(line, ' ')[2]);
	// ft_putstr_fd(ft_itoa(bot->piece_width), bot->fd);
	// ft_putstr_fd("\n", bot->fd);
	return(ft_create_bid_arr(bot->piece_height, bot->piece_width, bot, 0));
}

char				**ft_create_field(t_bot *bot, char *str)
{
	char		*line;

	bot->field_height = ft_atoi(ft_strsplit(str, ' ')[1]);
	bot->field_width = ft_atoi(ft_strsplit(str, ' ')[2]);
	get_next_line(0, &line);
	return (ft_create_bid_arr(bot->field_height, bot->field_width, bot, 1));
}