/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode_private_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	ft_asn1_set_value(t_bigint a, char tag, char **ptr)
{
	ft_asn1_set_size(a.size, tag, ptr);
	ft_memcpy(*ptr, a.value, a.size);
	ft_memrev(*ptr, a.size);
	(*ptr) += a.size;
}
