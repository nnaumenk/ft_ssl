/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 00:04:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 00:04:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *str, char val)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (str[start] == val)
		++start;
	end = ft_strlen(str);
	if (start == end)
		return (ft_strnew(0));
	--end;
	while (str[end] == val)
		--end;
	len = end - start + 1;
	new = ft_malloc_str(len + 1);
	ft_memcpy((void *)new, (void *)&str[start], len);
	return (new);
}
