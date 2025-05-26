/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:09:15 by hrisse            #+#    #+#             */
/*   Updated: 2024/11/13 08:19:42 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
int	main(void)
{
	printf("%d \n",ft_isdigit(47));
	printf("%d \n",ft_isdigit('0'));
	printf("%d \n",ft_isdigit(58));
	printf("%d \n",ft_isdigit('9'));
	return (0);
}*/
