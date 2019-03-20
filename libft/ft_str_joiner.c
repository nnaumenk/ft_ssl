/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_joiner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:07:56 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 21:38:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const int n, va_list argptr, char **str, size_t *len)
{
	size_t	len_full;
	int		i;

	len_full = 0;
	i = -1;
	while (++i < n)
	{
		*str = va_arg(argptr, char *);
		*len = ft_strlen(*str);
		len_full += *len++;
	}
	return (len_full);
}

static char		*ft_join(const int n, size_t len_full, char **str, size_t *len)
{
	char	*str_full;
	char	*pointer;
	int		i;

	str_full = (char *)malloc(len_full);
	pointer = str_full;
	i = -1;
	while (++i < n)
	{
		ft_memcpy(pointer, *str++, *len);
		pointer += *len++;
	}
	return (str_full);
}

char			*ft_str_joiner(size_t *len, const int n, ...)
{
	va_list	argptr;
	char	*str_full;
	char	*str_pointers[10];
	size_t	len_pointers[10];

	if (n > 10)
		return (NULL);
	va_start(argptr, n);
	*len = ft_count(n, argptr, str_pointers, len_pointers);
	str_full = ft_join(n, *len, str_pointers, len_pointers);
	va_end(argptr);
	return (str_full);
}
