/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_der_inform_private_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:25 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_der_inform_private_key(t_rsa *rsa)
{
	if (ft_asn1_decode_private_key(rsa))
	{
		ft_print_fd(2, "ft_ssl: unable to load Private Key\n");
		return (1);
	}
	ft_strdel(&rsa->text);
	return (0);
}
