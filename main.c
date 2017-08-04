/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:04:37 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/04 14:07:53 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int			fd;
	char		*line;
	int			o_fd;

	fd = open("/nfs/2016/r/rbozhko/Desktop/projects/filler/test/map.txt", O_RDONLY);
	o_fd = open("/nfs/2016/r/rbozhko/Desktop/projects/filler/test/filler.txt", O_WRONLY);
	while (get_next_line(fd, &line, o_fd) > 0)
	{
		printf("%s\n", line);
	}
	
	// get_next_line(fd, &line, o_fd);
	// printf("%s\n", line);	
	// get_next_line(fd, &line, o_fd);
	// printf("%s\n", line);
	// get_next_line(fd, &line, o_fd);
	// printf("%s\n", line);
	// get_next_line(fd, &line, o_fd);
	// printf("%s\n", line);
	return (0);
}
