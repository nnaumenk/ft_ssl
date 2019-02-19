/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 03:49:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"



static void	ft_div(unsigned char *val1, unsigned char *val2, size_t n1, size_t n2)
{
	unsigned char	*offset;
	unsigned char	*buf;
	size_t			buf_len;

	offset = val1 + n1 - n2;
	buf_len = n2;
	buf = (unsigned char *)malloc(buf_len + 1);
	buf[buf_len] = 0;
	ft_memcpy(buf, offset, buf_len);
	// check if bigger
	// if no add 1 byte;

	while (ft_bigint_smaller(buf, val2, buf_len, n2))
	{
		ft_memsub(buf, val2, buf_len, n2);

		///add next byte
	}

}

void	ft_bigint_div(void *mem1, void *mem2, size_t n1, size_t n2)
{
	if (ft_bigint_smaller(mem1, mem2, n1, n2))
	{
		ft_bzero(mem2, n2);
		ft_memcpy(mem2, mem1, n1);
		ft_bzero(mem1, n1);
	}
}
