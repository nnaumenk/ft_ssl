/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:23:02 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/10/17 23:52:53 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t i;

	i = ft_strlen(src);
	if (i < len)
	{
		ft_memcpy(dst, src, i);
		ft_bzero(&dst[i], len - i);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
