/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:48:43 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/17 13:49:39 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
#define FILLER_H

# include "get_next_line.h"
# include <stdio.h>

# define OPP_SIGN(my_sign) ((my_sign == 'X') ? 'O' : 'X');

typedef	struct 	s_answer
{
	int						x;
	int						y;
	int						square;
	struct 	s_answer		*next;
}				t_answer;

typedef	struct s_bot
{
	int 			fd; // FOR DEBUGGING
	char			my_sign;
	int				field_height;
	int				field_width;
	int				piece_height;
	int				start_x_val;
	short	int		sign_met;
	int				answer_x;
	int				answer_y;
	int				piece_width;
	char			**field;
	char			**piece;
	// char			field[field_height][field_width];
	char			opp_sign;
	t_answer		*answer_list;
}				t_bot;

char				**ft_create_piece(t_bot *bot);
char				**ft_create_field(t_bot *bot, char *str);
void				ft_create_solution(t_bot *bot, int fd);
void				ft_check_piece(t_bot *bot, int fd);
void				ft_check_coord(int x, int y, int i, int j, t_bot *bot, int fd);
#endif
