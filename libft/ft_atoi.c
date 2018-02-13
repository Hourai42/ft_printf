/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:34:35 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 12:47:46 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	unsigned long long	num;
	int					negative;

	num = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num >= 9223372036854775807)
		return ((negative == -1) ? 0 : -1);
	return ((int)(num * negative));
}
