/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 00:04:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 00:04:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin_del(void *mem1, void *mem2, size_t n1, size_t n2)
{
	void	*new;
	size_t	len;

	len = n1 + n2;
	new = malloc(len);
	ft_memcpy(new, mem1, n1);
	ft_memcpy(new + n1, mem2, n2);
	ft_memdel(&mem1);
	return (new);
}