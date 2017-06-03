#include "filler.h"

// Can we use bresenheim somehow to calc the answer, which has min length to opp_sign?
static int			ft_calc_square(t_bot *bot)
{
	int		counter;
	int		x;
	int		y;

	y = bot->answer_y - 1;
	counter = -1;
	while (bot->field[++y])
	{
		x = bot->answer_x;
		while (bot->field[y][++x])
		{
			++counter;
			if (bot->field[y][x] == bot->opp_sign)
				break ;	
		}
	}
	return (counter);
}

void		ft_create_solution(t_bot *bot, int fd)
{

	t_answer		*answer;
	t_answer		*temp;

	answer = (t_answer*)malloc(sizeof(t_answer*));
	answer->x = bot->answer_x;
	answer->y = bot->answer_y;
	answer->square = ft_calc_square(bot); 
	answer->next = NULL;
	temp = bot->answer_list;
	if (!bot->answer_list)
	{
		ft_putstr_fd("HERR\n", fd);
		bot->answer_list = answer;
		ft_putstr_fd("Answer-1: ", fd);
		ft_putstr_fd(ft_itoa(answer->square), fd);
		ft_putstr_fd("\n", fd);
	}
	else
	{
		ft_putstr_fd("FRAU\n", fd);
		ft_putstr_fd(ft_itoa(answer->square), fd);
		ft_putstr_fd("\n", fd);
		while (temp)
		{
			ft_putstr_fd("Ta-DA\n", fd);
			if (!temp->next)
				break ;
			ft_putstr_fd(ft_strjoin("string: ", ft_itoa(temp->square)), fd);
			temp = temp->next;
		}
		ft_putstr_fd("Answer-2: ", fd);
		ft_putstr_fd(ft_itoa(answer->square), fd);
		ft_putstr_fd("\n", fd);
		temp->next = answer;
	}
}