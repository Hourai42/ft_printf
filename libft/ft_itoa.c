/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:22:46 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 20:33:43 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		neg;

	neg = 1;
	count = ft_countplace(n);
	if (n < 0)
	{
		count++;
		neg *= -1;
	}
	if ((str = (malloc(sizeof(char) * (count + 1)))) == 0)
		return (NULL);
	str[count] = '\0';
	count--;
	while (count > 0)
	{
		str[count--] = ((n % 10) * neg) + '0';
		n /= 10;
	}
	if (neg == -1)
		str[count] = '-';
	else
		str[count] = n % 10 + '0';
	return (str);
}
