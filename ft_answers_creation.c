#include "filler.h"

// Can we use bresenheim somehow to calc the answer, which has min length to opp_sign?
#define HAS_DOT_AROUND (bot->field[y][x - 1] == '.' || bot->field[y][x + 1] == '.'
|| bot->field[y - 1][x] == '.' || bot->field[y + 1][x] == '.') // TAKE Care about seg faults x + 1 || y - 1 can cause.
#define ABS(x) (x < 0) ? -x : x // https://stackoverflow.com/questions/2025372/c-macro-question-x-vs-x
	
static int			ft_calc_square(t_bot *bot)
{
	int		max_distance;
	int		result;
	int		x;
	int		y;

	y = -1;
	max_distance = bot->field_width + bot->field_height;
	while (bot->field[++y])
	{
		x = -1;
		while (bot->field[y][++x])
		{
			if (bot->field[y][x] == bot->opp_sign && HAS_DOT_AROUND)
			{
				result = ABS(x - bot->answer_x) + ABS(y - bot->answer_y);
				max_distance = (result < max_distance) ? result : max_distance;
			}
		}
	}
	return (max_distance);
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
	temp = (t_answer*)malloc(sizeof(t_answer*));
	temp = bot->answer_list;
	// ft_putstr_fd("Answer-1: ", fd);
	// ft_putstr_fd(ft_itoa(bot->answer_y), fd);
	// ft_putstr_fd(ft_itoa(bot->answer_x), fd);
	// ft_putstr_fd("\n", fd);
	if (!bot->answer_list)
	{
		bot->answer_list = answer;
		// ft_putstr_fd("Answer-1: ", fd);
		// ft_putstr_fd(ft_itoa(answer->square), fd);
		// ft_putstr_fd("\n", fd);
	}
	else
	{
		while (temp)
		{
			if (!temp->next)
				break ;
			// ft_putstr_fd(ft_strjoin("string: ", ft_itoa(temp->square)), fd);
			temp = temp->next;
		}
		// ft_putstr_fd("Answer-2: ", fd);
		// ft_putstr_fd(ft_itoa(answer->square), fd);
		// ft_putstr_fd("\n", fd);
		temp->next = answer;
	}
}
