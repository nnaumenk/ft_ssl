/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pem_outform_public_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:18 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_pem_outform_public_key(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN PUBLIC KEY-----\n";
	const char	*line2 = "-----END PUBLIC KEY-----\n";
	char		*tmp;

	ft_asn1_encode_public_key(&rsa->data, &rsa->text, &rsa->len);
	rsa->text = ft_b64_encode(rsa->text, &rsa->len);
	tmp = ft_mem_joiner(&rsa->len, 3,
	(char *)line1, (size_t)27, rsa->text, rsa->len, (char *)line2, (size_t)25);
	ft_strdel(&rsa->text);
	rsa->text = tmp;
	return (0);
}
