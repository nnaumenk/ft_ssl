/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:07:56 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:33:38 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_8byte(size_t **a, size_t **b, size_t n)
{
	size_t	buf;

	while (n--)
	{
		buf = **a;
		**a = **b;
		**b = buf;
		(*a)++;
		(*b)++;
	}
}

static void	ft_swap_1byte(char **a, char **b, size_t n)
{
	char	buf;

	while (n--)
	{
		buf = **a;
		**a = **b;
		**b = buf;
		(*a)++;
		(*b)++;
	}
}

void		ft_memswap(void *a, void *b, size_t n)
{
	ft_swap_8byte(&a, &b, n / sizeof(size_t));
	ft_swap_1byte(&a, &b, n % sizeof(size_t));
}
