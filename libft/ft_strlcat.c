/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:38:29 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 16:05:38 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	k;

	i = 0;
	if (size != 0)
	{
		while (dst[i] && i < size)
			i++;
		a = 0;
		while (src[a] && a + i < size - 1)
		{
			dst[i + a] = src[a];
			a++;
		}
		if (a + i < size)
			dst[a + i] = '\0';
	}
	k = 0;
	while (src[k] != '\0')
		k++;
	return (k + i);
}
