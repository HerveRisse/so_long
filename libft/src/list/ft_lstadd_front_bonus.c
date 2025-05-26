/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:44:28 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:46:57 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
    t_list *lst = NULL;

    int n1 = 10;
    int n2 = 20;
    int n3 = 5;

    t_list *node1 = ft_lstnew(&n1);
    t_list *node2 = ft_lstnew(&n2);
    t_list *node3 = ft_lstnew(&n3);

    ft_lstadd_front(&lst, node1);
    ft_lstadd_front(&lst, node2);
    ft_lstadd_front(&lst, node3);

    while (lst)
    {
        printf(" %d ", *(int *)(lst->content));
        lst = lst->next;
    }

    while (lst)
    {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }

    return (0);
}*/
