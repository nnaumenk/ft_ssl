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

void	*ft_memdup(void *memptr, size_t n)
{
	void	*new;

	new = malloc(n);
	ft_memcpy(new, memptr, n);
	return (new);
}
