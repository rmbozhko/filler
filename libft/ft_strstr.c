/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:22:15 by rbozhko           #+#    #+#             */
/*   Updated: 2017/05/20 14:22:18 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + c] == to_find[c])
		{
			c++;
			if (to_find[c] == '\0')
			{
				return (str + i);
			}
		}
		c = 0;
		i++;
	}
	return (NULL);
}
