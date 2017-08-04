/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbidstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:39:42 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/04 16:38:19 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putbidstr_fd(char **arr, int fd)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}
