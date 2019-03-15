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

int		ft_asn1_get_byte_number(size_t len)
{
	if (len <= 0xff)
		return (1);
	if (len <= 0xffff)
		return (2);
	if (len <= 0xffffff)
		return (3);
	if (len <= 0xffffffff)
		return (4);
	if (len <= 0xffffffffff)
		return (5);
	if (len <= 0xffffffffffff)
		return (6);
	if (len <= 0xffffffffffffff)
		return (7);
	return (8);
}
