/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode_public_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_asn1_check_size(char **ptr, char tag, size_t *len)
{
	size_t		size;

	if (*len < 1 || **ptr != tag)
		return (1);
	*len -= 1;
	*ptr += 1;
	if (ft_asn1_get_size(&size, ptr, len))
		return (1);
	if (size != *len)
		return (1);
	return (0);
}
