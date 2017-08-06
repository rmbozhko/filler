/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 13:15:38 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 13:19:37 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "../get_next_line.h"
# include <ncurses.h>

# define GET_LINE_NUM(x) ft_atoi(ft_strsplit(line, ' ')[x])
# define CENTER_OUTPUT_Y (int)(LINES / 2) + y
# define CENTER_OUTPUT_X (int)(COLS / 2) - (int)(x / 2)
# define HALF(x) (int)(x / 2)

void				skip_lines(char *line, int lines_to_skip);
unsigned int		ft_await_closing(void);
void				init_color_pairs(void);
void				ft_handle_result(char *line, int y, int x);

#endif
