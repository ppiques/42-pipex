/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:19:00 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 16:10:23 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem_new;

	elem_new = malloc(sizeof(t_list));
	if (!elem_new)
		return (NULL);
	elem_new->content = content;
	elem_new->next = NULL;
	return (elem_new);
}
