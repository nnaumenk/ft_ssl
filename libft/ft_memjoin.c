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

char	*ft_memjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*str;
	size_t	len;

	len = len1 + len2;
	str = (char *)(malloc(len + 1));
	str[len] = '\0';
	ft_memcpy((void *)str, (void *)s1, len1);
	ft_memcpy((void *)&str[len1], (void *)s2, len2);
	ft_strdel(&s1);
	return (str);
}
