/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/14 19:08:50 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

void	ft_bigint_normalize(void **memptr, size_t *len)
{
	size_t			real_len;
	char			*ptr;
	unsigned char	*new;

	real_len = *len;
	ptr = (char *)(*memptr + *len);
	while (real_len)
	{
		ptr--;
		if (*ptr)
			break ;
		real_len--;
	}
	if (real_len == len)
		return ;
	new = (char *)malloc(real_len);
	ft_memcpy(new, *memptr, real_len);
	ft_memdel(memptr);
	*memptr = new;
	*len = real_len;
}