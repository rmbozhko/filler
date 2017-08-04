#include "filler.h"

static intmax_t		ft_abs(intmax_t x)
{
	return ((x < 0) ? (-x) : (x));
}

void				ft_print_answer(int fd)
{
	char		*x_str;
	char		*y_str;

	// if (bonus->my_pieces_counter > (bonus->opp_pieces_counter * ODDS)) 
	// {
	// 	x_str = "0";
	// 	y_str = "0";
	// }
	// else
	// {
		y_str = ft_itoa(g_bot->answer->y);
		x_str = ft_itoa(g_bot->answer->x);
	// }
	ft_putstr_fd(y_str, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(x_str, 1);
	ft_putstr_fd("\n", 1);
}

static int		check_row_range(int range_y, int y, int range_x, int x)
{
	int			temp;

	while (range_y < y)
	{
		temp = range_x;
		while (range_x < x)
		{
			if (g_bot->field[range_y][range_x] == g_bot->opp_sign)
				return (0);
			range_x++;
		}
		range_x = temp;
		range_y++;
	}
	return (1);
}

static int			ft_calc_square(void)
{
	int		max_distance;
	int		result;
	int		x;
	int		y;

	y = -1; // y = 1;
	max_distance = g_bot->field_width + g_bot->field_height;
	while (g_bot->field[++y])
	{
		x = -1; // x = 1;
		while (g_bot->field[y][++x])
		{
			if (g_bot->field[y][x] == g_bot->opp_sign /*&& HAS_DOT_AROUND*/) // if both x and y == 1, then uncomment line
			{
				result = (ft_abs(x - g_bot->answer_x)) + (ft_abs(y - g_bot->answer_y));
				max_distance = (result < max_distance) ? result : max_distance;
			}
		}
	}
	return (max_distance);
}

void		ft_determine_best_option(int fd)
{
	// t_option		*option;
	int				square;

	// option.half_width = (int)(g_bot->field_width / 2);
	// option.half_height = (int)(g_bot->field_height / 2);
	// option.part_field_y = option.half_height - (int)(FIELD_PART(option.half_height));
	// option.part_field_x = option.half_width - (int)(FIELD_PART(option.half_width));
	// if (check_row_range(option.part_field_y, option.half_height, option.half_width - (int)(FIELD_PART(option.half_width)),
	// 	option.half_width + (int)(FIELD_PART(option.half_width)))
	// 	&& check_row_range(option.half_height,	option.half_height + (int)(FIELD_PART(option.half_height)), option.half_width - (int)(FIELD_PART(option.half_width)),
	// 	option.half_width + (int)(FIELD_PART(option.half_width))))
	// {
	// 	ft_putstr_fd("Going to the center\n", fd);
	// 	square = (ft_abs(option.half_width - g_bot->answer_x)) + (ft_abs(option.half_height - g_bot->answer_y));
	// }
	// else if (check_row_range(0, (int)(FIELD_PART(option.half_height),
	// g_bot->field_width - (int)(FIELD_PART(option.half_width)), g_bot->field_width)
	// {
	// 	ft_putstr_fd("Going to the top right corner\n", fd);
	// 	square = (ft_abs(g_bot->field_width - g_bot->answer_x)) + (ft_abs(0 - g_bot->answer_y));
	// }
	// else if (check_row_range(g_bot->field_height - (int)(FIELD_PART(option.half_height)),
	// g_bot->field_height, 0, (int)(FIELD_PART(option.half_width)))) // think about n + 2 formula, where n is gotten from FIELD_PART macro 
	// {
	// 	ft_putstr_fd("Going to the bottom left corner\n", fd);
	// 	square = (ft_abs(0 - g_bot->answer_x)) + (ft_abs(g_bot->field_height - g_bot->answer_y));
	// }
	// else
	// {
		// ft_putstr_fd("Taking best fi tting option\n", fd);
	square = ft_calc_square();
	// }
	ft_putstr_fd("\nCoords\n", fd);
	ft_putstr_fd(ft_itoa(g_bot->answer_y), fd);
	ft_putstr_fd(":", fd);
	ft_putstr_fd(ft_itoa(g_bot->answer_x), fd);
	ft_putstr_fd("\n", fd);
	if (square < g_bot->answer->square)
	{
		g_bot->answer->y = g_bot->answer_y;
		g_bot->answer->x = g_bot->answer_x;
		g_bot->answer->square = square;
	}
}

/*
static intmax_t		ft_abs(intmax_t x)
{
	return ((x < 0) ? (-x) : (x));
}

void				ft_print_answer(void)
{
	ft_putstr_fd(ft_itoa(g_bot->answer->y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(g_bot->answer->x), 1);
	ft_putstr_fd("\n", 1);
}

static int			ft_calc_square(void)
{
	int		max_distance;
	int		result;
	int		x;
	int		y;

	y = -1;
	max_distance = g_bot->field_width + g_bot->field_height;
	while (g_bot->field[++y])
	{
		x = -1;
		while (g_bot->field[y][++x])
		{
			if (g_bot->field[y][x] == g_bot->opp_sign)
			{
				result = (ft_abs(x - g_bot->answer_x)) + (ft_abs(y - g_bot->answer_y));
				max_distance = (result < max_distance) ? result : max_distance;
			}
		}
	}
	return (max_distance);
}

void		ft_determine_best_option(void)
{
	int				square;

	square = ft_calc_square();
	if (square < g_bot->answer->square)
	{
		g_bot->answer->y = g_bot->answer_y;
		g_bot->answer->x = g_bot->answer_x;
		g_bot->answer->square = square;
	}
}*/