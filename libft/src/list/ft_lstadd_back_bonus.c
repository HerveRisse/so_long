/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:52:50 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/02 21:53:29 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
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

    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);
    ft_lstadd_back(&lst, node3);

    t_list *tmp = lst;

    while (tmp)
    {
        printf(" %d ", *(int *)(tmp->content));
        tmp = tmp->next;
    }

    while (lst)
    {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }

    return (0);
}*/
