/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:09:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:10:46 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void				skip_lines(char *line, int lines_to_skip)
{
	int		i;

	i = 0;
	while (i < lines_to_skip)
	{
		get_next_line(0, &line);
		i++;
	}
}

unsigned int		ft_await_closing(void)
{
	while (1)
	{
		if (getch() == -1)
			return (sleep(30));
	}
}

void				init_color_pairs(void)
{
	init_pair(1, COLOR_RED, COLOR_GREEN);
	init_pair(2, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(3, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(4, COLOR_BLUE, COLOR_YELLOW);
}
