/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:04:03 by ppiques           #+#    #+#             */
/*   Updated: 2020/11/18 15:22:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (s[i])
	{
		if (c == s[i])
			return (&str[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (&str[i]);
	return (NULL);
}
