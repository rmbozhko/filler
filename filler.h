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
# include "libft/libft.h"

# define OPP_SIGN(my_sign) ((my_sign == 'X') ? 'O' : 'X');
// Can we use bresenheim somehow to calc the answer, which has min length to opp_sign?
#define HAS_DOT_AROUND (g_bot->field[y][x - 1] == '.' || g_bot->field[y][x + 1] == '.' \
|| g_bot->field[y - 1][x] == '.' || g_bot->field[y + 1][x] == '.') // TAKE Care about seg faults x + 1 || y - 1 can cause.
//#define ABS(x) (x < 0) ? (-x) : (x) // https://stackoverflow.com/questions/2025372/c-macro-question-x-vs-x
#define F_DOT g_bot->field[y][x] == '.'
#define F_M_S g_bot->field[y][x] == g_bot->my_sign
#define F_O_S g_bot->field[y][x] == g_bot->opp_sign

typedef	struct 	s_answer
{
	int						x;
	int						y;
	int						square;
}				t_answer;

typedef	struct s_bot
{
	int 			fd;
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

char				**ft_create_piece(void);
char				**ft_create_field(char *str);
void				ft_determine_best_option(void);
void				ft_check_piece(void);
void				ft_field_and_piece(void);
void				ft_print_answer(void);
#endif
