/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 16:29:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int		ft_search_word(char **text, size_t *len, const char *line)
{
	size_t		i;

	i = 0;
	while (*len)
	{
		if (**text == line[i])
		{
			++i;
			if (line[i] == 0)
				return (0);
		}
		else
			i = 0;
		(*len)--;
		(*text)++;
	}
	return (1);
}

static int		ft_rsa_get_asn1_text(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "\n-----END RSA PRIVATE KEY-----";
	char		*start_key;
	char		*end_key;

	start_key = rsa->text;
	if (ft_search_word(&start_key, &rsa->len, line1))
		return (1);
	start_key += 1;
	end_key = start_key;
	if (ft_search_word(&end_key, &rsa->len, line2))
		return (1);
	end_key -= 29;
	rsa->len = end_key - start_key + 1;
	rsa_key = (char *)malloc(len);
	ft_memcpy(rsa_key, start_key, rsa->len);
	ft_strdel(&rsa->text);
	rsa->text = ft_b64_decode(rsa_key, &rsa->len);
	if (ft_asn1_decode(data, rsa_key, len))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	ft_strdel(&rsa->text);
	return (0);
}

