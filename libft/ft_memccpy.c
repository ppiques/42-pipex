/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:08:29 by ppiques           #+#    #+#             */
/*   Updated: 2020/12/02 19:38:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	while (n > 0)
	{
		s2[i] = s1[i];
		if ((unsigned char)s1[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
