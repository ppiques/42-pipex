/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:28:44 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 15:21:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = nmemb * size;
	str = malloc(count);
	if (!str)
		return (NULL);
	while (count > 0)
	{
		str[i] = 0;
		i++;
		count--;
	}
	return ((void *)str);
}
