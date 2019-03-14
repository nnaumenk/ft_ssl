/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/28 00:00:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	ft_asn1_make_text(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "-----END RSA PRIVATE KEY-----\n";
	char		*tmp;

	rsa->text = ft_b64_encode(rsa->text, &rsa->len);
	tmp = ft_mem_joiner(&rsa->len, 3,
	(char *)line1, (size_t)32, rsa->text, rsa->len, (char *)line2, (size_t)30);
	ft_strdel(&rsa->text);
	rsa->text = tmp;
}

void		ft_genrsa(void *v_data)
{
	t_rsa	rsa;

	rsa.flag = *(t_rsa_flag *)v_data;
	if (rsa.flag.numbits <= 30)
	{
		ft_printf("ft_ssl: key's size is too small\n");
		return ;
	}
	if (ft_rsa_make_flag_rand(&rsa.flag.rand_fd, rsa.flag.in))
		return ;
	if (ft_make_genrsa_data(&rsa))
		return ;
	ft_close_fd(rsa.flag.rand_fd);
	ft_asn1_encode_private_key(&rsa.data, &rsa.text, &rsa.len);
	ft_asn1_make_text(&rsa);
	ft_rsa_free_data(&rsa.data);
	ft_rsa_make_flag_out(rsa.text, rsa.len, rsa.flag.out);
	ft_strdel(&rsa.text);
}
