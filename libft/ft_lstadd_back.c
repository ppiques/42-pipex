/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:19:23 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/08 16:05:18 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem_last;

	if (alst == NULL)
		return ;
	elem_last = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (elem_last->next)
			elem_last = elem_last->next;
		elem_last->next = new;
	}
}
