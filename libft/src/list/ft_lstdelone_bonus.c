/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:07:29 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 22:08:25 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
/*
void del(void *content)
{
    free(content);
}

int main(void)
{
    int *num = malloc(sizeof(int));
    *num = 42;

    t_list *lst = ft_lstnew(num);

    ft_lstdelone(lst, del);

    return (0);
}*/
