/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:39:54 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 22:40:49 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 1 || index == 0)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
