// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   flag_text.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
// /*   Updated: 2019/02/05 16:36:41 by nnaumenk         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../ft_ssl.h"

// static int		ft_search_word(char **text, size_t *len, const char *line)
// {
// 	size_t		i;

// 	i = 0;
// 	while (*len)
// 	{
// 		if (**text == line[i])
// 		{
// 			++i;
// 			if (line[i] == 0)
// 				return (0);
// 		}
// 		else
// 			i = 0;
// 		(*len)--;
// 		(*text)++;
// 	}
// 	return (1);
// }

// static int		ft_get_data(t_rsa_data *data, char *text, size_t len)
// {
// 	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
// 	const char	*line2 = "\n-----END RSA PRIVATE KEY-----";
// 	char		*start_key;
// 	char		*end_key;
// 	char		*rsa_key;

// 	start_key = text;
// 	if (ft_search_word(&start_key, &len, line1))
// 		return (1);
// 	start_key += 1;
// 	end_key = start_key;
// 	if (ft_search_word(&end_key, &len, line2))
// 		return (1);
// 	end_key -= 29;
// 	len = end_key - start_key + 1;
// 	rsa_key = (char *)malloc(len);
// 	ft_memcpy(rsa_key, start_key, len);
// 	rsa_key = ft_b64_decode(rsa_key, &len);
// 	if (ft_asn1_decode(data, rsa_key, len))
// 	{
// 		ft_print("error in decode\n");
// 		ft_strdel(&rsa_key);
// 		return (1);
// 	}
// 	ft_strdel(&rsa_key);
// 	return (0);
// }

// static char	g_logarithm_2[] =
// {
// 	-1,  0,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
// 	 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
// 	 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
// 	 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
// 	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
// 	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
// 	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
// 	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// 	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
// };

// static void	ft_print_numbits(t_bigint modulus)
// {
// 	size_t	numbits;

// 	numbits =
// 	(modulus.size - 1) * 8 + g_logarithm_2[modulus.value[modulus.size - 1]] + 1;
// 	ft_printf("Private-Key: (%zu bit)\n", numbits);
// }

// static void	ft_print_data(t_rsa_data *data)
// {
// 	ft_print_numbits(data->modulus);
// 	ft_bigint_print("modulus", data->modulus);
// 	ft_bigint_print("publicExponent", data->public_exponent);
// 	ft_bigint_print("privateExponent", data->private_exponent);
// 	ft_bigint_print("prime1", data->prime1);
// 	ft_bigint_print("prime2", data->prime2);
// 	ft_bigint_print("exponent1", data->exponent1);
// 	ft_bigint_print("exponent2", data->exponent2);
// 	ft_bigint_print("coefficient", data->coefficient);
// }

int			ft_rsa_make_flag_text(t_rsa *data)
{

	USE(data);
	// if (data->flag.text)
	// {
	// 	if (ft_get_data(&data->data, data->text, data->len))
	// 	{
	// 		ft_print("error\n");
	// 		ft_strdel(&data->text);
	// 		return (1);
	// 	}
	// 	ft_strdel(&data->text);
	// 	ft_print_data(&data->data);
	// }
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
