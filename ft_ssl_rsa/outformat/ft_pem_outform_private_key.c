/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pem_outform_private_key.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:19 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_pem_outform_private_key(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "-----END RSA PRIVATE KEY-----\n";
	char		*tmp;

	if (rsa->flag.des)
		return (ft_pem_des_outform_private_key(rsa));
	ft_asn1_encode_private_key(rsa);
	rsa->text = ft_b64_encode(rsa->text, &rsa->len);
	tmp = ft_mem_joiner(&rsa->len, 3,
	(char *)line1, (size_t)32, rsa->text, rsa->len, (char *)line2, (size_t)30);
	ft_strdel(&rsa->text);
	rsa->text = tmp;
	return (0);
}
