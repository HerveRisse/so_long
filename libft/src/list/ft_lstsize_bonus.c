/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:30:48 by hrisse            #+#    #+#             */
/*   Updated: 2024/12/04 11:41:13 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
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

    int size = ft_lstsize(lst);

    printf("taille : %d \n", size);

    while (lst)
    {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }

    return (0);
}*/
