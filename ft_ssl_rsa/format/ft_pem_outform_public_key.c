/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_get_public_text.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:40:57 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_pem_outform_public_key(char **text, size_t *len)
{
	const char	*line1 = "-----BEGIN PUBLIC KEY-----\n";
	const char	*line2 = "-----END PUBLIC KEY-----\n";
	char		*tmp;

	*text = ft_b64_encode(*text, len);
	tmp = ft_mem_joiner(len, 3,
	(char *)line1, (size_t)27, *text, *len, (char *)line2, (size_t)25);
	ft_strdel(text);
	*text = tmp;
	return (0);
}
