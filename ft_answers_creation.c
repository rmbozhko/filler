int			ft_calc_square(t_bot *bot)
{
	int		counter;
	int		x;
	int		y;

	y = bot->answer_y - 1;
	counter = -1;
	while (bot->field[++y])
	{
		x = bot->answer_x - 1;
		while (bot->field[y][++x])
		{
			++counter;
			if (bot->field[y][x] == bot->opp_sign)
				break ;	
		}
	}
	return (counter);
}

void		ft_create_solution(t_bot *bot)
{
	t_answer		*answer;
	t_answer		*temp;

	answer = (t_answer*)malloc(sizeof(t_answer*));
	answer->x = bot->answer_x;
	answer->y = bot->answer_y;
	answer->square = ft_calc_square(bot); // Can we use bresenheim somehow to calc the answer, which has min length to opp_sign?
	answer->next = NULL;
	if (bot->answer_list == NULL)
		bot->answer_list = answer;
	else
	{
		temp = bot->answer_list;
		while (temp)
		{
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		temp->next = answer;
	}
}