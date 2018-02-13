/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocwrd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:53:43 by ttran             #+#    #+#             */
/*   Updated: 2017/12/07 12:52:09 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mallocwrd(char *str, int spot, char c)
{
	int		count;
	int		i;
	char	*god;

	i = 0;
	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	i = 0;
	god = malloc(sizeof(char) * (count + 1));
	while (str[spot] != c && str[spot])
		god[i++] = str[spot++];
	god[i] = '\0';
	return (god);
}
