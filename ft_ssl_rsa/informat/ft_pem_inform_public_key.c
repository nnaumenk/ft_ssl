/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pem_inform_public_key.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:20 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_search_word(char **text, size_t *len, const char *line)
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

static int	ft_get_asn1_text(char **text, size_t *len)
{
	const char	*line1 = "-----BEGIN PUBLIC KEY-----\n";
	const char	*line2 = "\n-----END PUBLIC KEY-----";
	char		*start_key;
	char		*end_key;
	char		*rsa_key;

	start_key = *text;
	if (ft_search_word(&start_key, len, line1))
	{
		ft_strdel(text);
		return (1);
	}
	start_key += 1;
	end_key = start_key;
	if (ft_search_word(&end_key, len, line2))
	{
		ft_strdel(text);
		return (1);
	}
	end_key -= 24;
	*len = end_key - start_key + 1;
	rsa_key = (char *)ft_memdup(start_key, *len);
	ft_strdel(text);
	*text = rsa_key;
	return (0);
}

int			ft_pem_inform_public_key(t_rsa *rsa)
{
	if (ft_get_asn1_text(&rsa->text, &rsa->len))
	{
		ft_print_fd(2, "ft_ssl: unable to load Public Key\n");
		return (1);
	}
	rsa->text = ft_b64_decode(rsa->text, &rsa->len);
	if (ft_asn1_decode_public_key(rsa))
	{
		ft_print_fd(2, "ft_ssl: unable to load Public Key\n");
		return (1);
	}
	ft_strdel(&rsa->text);
	return (0);
}
