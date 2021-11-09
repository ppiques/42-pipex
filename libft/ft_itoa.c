/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:37:22 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 16:20:29 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long n)
{
	if (n < 0)
		return (1 + nbrlen(-n));
	else if (n / 10 > 0)
		return (1 + nbrlen(n / 10));
	else
		return (1);
}

char	*ft_itoa_operation(int len, int nbr, char *str)
{
	while (len > (*str == '-' ? 1 : 0))
	{
		if (nbr >= 10)
		{
			*(str + --len) = nbr % 10 + '0';
			nbr = nbr / 10;
		}
		else
			*(str + --len) = '0' + nbr;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = nbrlen(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		*str = '-';
		nbr = nbr * -1;
	}
	else
		*str = '0';
	*(str + len) = '\0';
	str = ft_itoa_operation(len, nbr, str);
	return (str);
}
