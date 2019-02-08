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

void		ft_memmul_by_2(void *s, size_t n)
{
	// uint64_t	*val64;
	// uint64_t	new_val;
	// uint64_t	carry_out;
	// int			size64;
	
	// carry_out = 0;
	// val64 = (uint64_t *)val8;
	// size64 = size / 8;
	// val64 += size64;
	// while (size64--)
	// {
	// 	val64--;
	// 	new_val = (*val64 >> 1) | (carry_out << 63);
	// 	carry_out = *val64 & 0x0000000000000001;
	// 	*val64 = new_val;
	// }
	USE(s);
	USE(n);
}
