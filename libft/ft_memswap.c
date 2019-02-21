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

static void	ft_swap_8byte(void **a, void **b, size_t n)
{
	size_t	*x;
	size_t	*y;
	size_t	buf;

	x = *a;
	y = *b;
	while (n--)
	{
		buf = *x;
		*x = *y;
		*y = buf;
		x++;
		y++;
	}
	*a = x;
	*b = y;
}

static void	ft_swap_1byte(void **a, void **b, size_t n)
{
	char	*x;
	char	*y;
	char	buf;

	x = *a;
	y = *b;
	while (n--)
	{
		buf = *x;
		*x = *y;
		*y = buf;
		x++;
		y++;
	}
	*a = x;
	*b = y;
}

void		ft_memswap(void *a, void *b, size_t n)
{
	ft_swap_8byte(&a, &b, n / sizeof(size_t));
	ft_swap_1byte(&a, &b, n % sizeof(size_t));
}
