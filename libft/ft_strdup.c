/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:16:27 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 01:12:32 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	new = ft_malloc_str(len);
	ft_memcpy((void *)new, (void *)str, len);
	return (new);
}
