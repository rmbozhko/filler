/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:48:43 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/06 16:22:02 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"

# define F_DOT g_bot->field[y][x] == '.'
# define F_M_S g_bot->field[y][x] == g_bot->my_sign
# define F_O_S g_bot->field[y][x] == g_bot->opp_sign

typedef	struct	s_answer
{
	int						x;
	int						y;
	int						square;
}				t_answer;

typedef	struct	s_bot
{
	int				fd;
	char			my_sign;
	int				field_height;
	int				field_width;
	int				piece_height;
	int				piece_width;
	int				start_x_val;
	int				sign_met;
	int				answer_x;
	int				answer_y;
	char			**field;
	char			**piece;
	char			opp_sign;
	t_answer		*answer;
}				t_bot;

extern	t_bot		*g_bot;

char			**ft_create_piece(void);
char			**ft_create_field(char *str);
void			ft_determine_best_option(void);
void			ft_try_piece(int x, int y);
void			ft_field_and_piece(void);
void			ft_print_answer(void);
#endif
