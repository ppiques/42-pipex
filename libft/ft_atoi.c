/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:55:38 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 15:06:18 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	res;
	int		count;

	i = 0;
	res = 0;
	count = 1;
	while (nptr[i] && (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			count = count * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	res = res * count;
	return (res);
}
