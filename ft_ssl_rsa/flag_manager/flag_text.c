/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 16:36:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_search_word(char **text, size_t *len, const char *line)
{
	size_t		i;

	i = 0;
	while ((*len)--)
	{
		if (*(*text)++ == line[i])
		{
			if (line[++i] == 0)
				return (0);
		}
		else
			i = 0;
	}
	return (1);
}

static int	ft_get_data(t_rsa_data *data, char *text, size_t len)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "\n-----END RSA PRIVATE KEY-----";
	char		*start;
	char		*end;
	char		*rsa_key;

	start = text;
	if (ft_search_word(&start, &len, line1))
		return (1);
	end = start;
	if (ft_search_word(&end, &len, line2))
		return (1);
	len = end - start + 30;
	rsa_key = (char *)malloc(len);
	ft_memcpy(rsa_key, start, len);
	rsa_key = ft_b64_decode(rsa_key, &len);
	ft_print("1\n");
	if (ft_asn1_decode(data, rsa_key, len))
	{
		ft_print("error in decode\n");
		//ft_strdel(&rsa_key);
		return (1);
	}
	ft_print("3\n");
	ft_strdel(&rsa_key);
	return (0);
}

static void	ft_print_data(t_rsa_data *data)
{
	ft_print("Private-Key: (%d bit)\n", 2048);
	ft_print_big_int("modulus", data->modulus, data->modulus_len);
	ft_print_big_int("publicExponent", data->public_exponent,
	data->public_exponent_len);
	ft_print_big_int("privateExponent", data->private_exponent,
	data->private_exponent_len);
	ft_print_big_int("prime1", data->prime1, data->prime1_len);
	ft_print_big_int("prime2", data->prime2, data->prime2_len);
	ft_print_big_int("exponent1", data->exponent1, data->exponent1_len);
	ft_print_big_int("exponent2", data->exponent2, data->exponent2_len);
	ft_print_big_int("coefficient", data->coefficient, data->coefficient_len);
}

int			ft_rsa_make_flag_text(t_rsa *data)
{
	if (data->flag.text)
	{
		if (ft_get_data(&data->data, data->text, data->len))
		{
			ft_print("error\n");
			//ft_strdel(&text);
			return (1);
		}
		ft_strdel(&data->text);
		ft_print_data(&data->data);
	}
	return (0);
}

int			ft_rsa_check_flag_text(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->text = 1;
	return (0);
}