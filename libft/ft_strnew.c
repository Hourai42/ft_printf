/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:30:17 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 13:02:12 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	else
	{
		while (i <= size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
}
