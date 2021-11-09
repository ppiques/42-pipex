/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:08:18 by ppiques           #+#    #+#             */
/*   Updated: 2020/12/02 19:36:52 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sc;
	char	*dst;

	if (dest == src)
		return (dest);
	sc = (char *)src;
	dst = (char *)dest;
	if (dst > sc)
	{
		i = n;
		while (i-- > 0)
			dst[i] = sc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dest);
}
