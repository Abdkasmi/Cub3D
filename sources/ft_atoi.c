/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:57:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/08 16:31:40 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_overflow(const char *str, int limit)
{
	unsigned long long	num;
	int					i;

	i = -1;
	num = 0;
	while (str[++i] && i < limit)
	{
		num = (num * 10) + (str[i] - 48);
		if (num >= INT_MAX)
			return (-1);
	}
	return (num);
}

int	ft_atoi(const char *str, int limit)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	while (str[++i] && i < limit)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	num = ft_overflow(str, limit);
	return (num);
}
