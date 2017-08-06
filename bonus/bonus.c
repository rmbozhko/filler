/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:05:54 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:08:23 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void		ft_print_field(char *line, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (line[i] == 'X' || line[i] == 'x')
			attron(COLOR_PAIR(1));
		else if (line[i] == 'O' || line[i] == 'o')
			attron(COLOR_PAIR(2));
		else
			attron(COLOR_PAIR(3));
		printw("%c", line[i++]);
	}
}

int			ft_handle_plateau(char *line, int y, int x)
{
	int		height;
	int		width;
	int		i;

	i = -1;
	height = GET_LINE_NUM(1);
	width = GET_LINE_NUM(2);
	get_next_line(0, &line);
	while (++i < height)
	{
		get_next_line(0, &line);
		move(CENTER_OUTPUT_Y - HALF(height), CENTER_OUTPUT_X - HALF(width));
		ft_print_field(ft_strsplit(line, ' ')[1], ft_strlen(line));
		y++;
	}
	return (HALF(height));
}

void		ft_handle_piece(char *line)
{
	int		height;
	int		i;

	i = 0;
	height = GET_LINE_NUM(1);
	while (i < height)
	{
		get_next_line(0, &line);
		i++;
	}
}

void		ft_handle_result(char *line, int y, int x)
{
	char	*temp;
	int		x_result;
	int		o_result;

	o_result = GET_LINE_NUM(3);
	get_next_line(0, &line);
	x_result = GET_LINE_NUM(3);
	if (o_result > x_result)
		temp = "\'O\' has won this round!";
	else if (x_result > o_result)
		temp = "\'X\' has won this round!";
	else
		temp =
	"It's draw. '\'O\' and \'X\' players have same amount of points.";
	attron(COLOR_PAIR(4));
	printw("\n");
	move(CENTER_OUTPUT_Y + 2, CENTER_OUTPUT_X - HALF(ft_strlen(temp)));
	printw("%s\n", temp);
	temp = NULL;
	temp = ft_strjoin("O:", ft_itoa(o_result));
	temp = ft_strjoin(temp, ft_strjoin(" --- X:", ft_itoa(x_result)));
	move(CENTER_OUTPUT_Y + 3, CENTER_OUTPUT_X - HALF(ft_strlen(temp)));
	printw("%s\n", temp);
	attroff(COLOR_PAIR(4));
}

int			main(void)
{
	char	*line;
	int		temp_y;

	initscr();
	noecho();
	start_color();
	init_color_pairs();
	line = NULL;
	skip_lines(line, 9);
	while (get_next_line(0, &line))
	{
		if (ft_strcmp("Plateau ", ft_strsub(line, 0, 8)) == 0)
			temp_y = ft_handle_plateau(line, 0, 10);
		else if (ft_strcmp("Piece ", ft_strsub(line, 0, 6)) == 0)
			ft_handle_piece(line);
		else if (ft_strcmp("== ", ft_strsub(line, 0, 3)) == 0)
			ft_handle_result(line, temp_y, 10);
		refresh();
	}
	ft_await_closing();
	endwin();
	return (0);
}
