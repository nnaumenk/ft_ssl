/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_by_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 03:49:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_memadd_8byte(void **memptr, size_t shl, unsigned char *overflow)
{
	size_t	overflow;
	size_t	*mem64;
	
	overflow = 0;
	mem64 = (size_t *)*memptr;
	while (n--)
	{
		*mem64 = (*mem64 << shl) | overflow;
		overflow = (*mem64 >> shl)
		mem64++;
	}
	(*memptr) = mem64;
}

static void	ft_memshl_1byte(void **memptr, size_t shl, size_t n)
{
	unsigned char	overflow;
	unsigned char	*mem8;
	
	overflow = 0;
	mem8 = (unsigned char *)*memptr;
	while (n--)
	{
		*mem8 = (*mem8 << shl) | overflow;
		overflow = (*mem8 >> shl)
		mem8++;
	}
	(*memptr) = mem64;
}

void		ft_memshl(void *memptr, size_t shl, size_t n)
{
	ft_memshl_8byte(&memptr, shl, n / sizeof(size_t));
	ft_memshl_1byte(&memptr, shl, n % sizeof(size_t));
}
