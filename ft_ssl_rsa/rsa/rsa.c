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

// typedef struct		s_rsa_data
// {
// 	unsigned char	*modulus;
// 	size_t			modulus_len;
// 	unsigned char	*public_exponent;
// 	size_t			public_exponent_len;
// 	unsigned char	*private_exponent;
// 	size_t			private_exponent_len;
// 	unsigned char	*prime1;
// 	size_t			prime1_len;
// 	unsigned char	*prime2;
// 	size_t			prime2_len;
// 	unsigned char	*exponent1;
// 	size_t			exponent1_len;
// 	unsigned char	*exponent2;
// 	size_t			exponent2_len;
// 	unsigned char	*coefficient;
// 	size_t			coefficient_len;
// }					t_rsa_data;

// typedef struct		s_rsa
// {
// 	char			*text;
// 	size_t			len;
// 	t_rsa_flag		flag;
// 	t_rsa_data		data;
// }					t_rsa;


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

int		ft_rsa_get_asn1_text(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "\n-----END RSA PRIVATE KEY-----";
	char		*start_key;
	char		*end_key;
	char		*rsa_key;

	start_key = rsa->text;
	if (ft_search_word(&start_key, &rsa->len, line1))
		return (1);
	start_key += 1;
	end_key = start_key;
	if (ft_search_word(&end_key, &rsa->len, line2))
		return (1);
	end_key -= 29;
	rsa->len = end_key - start_key + 1;
	rsa_key = (char *)ft_memdup(start_key, rsa->len);
	ft_strdel(&rsa->text);
	rsa->text = ft_b64_decode(rsa_key, &rsa->len);
	return (0);
}

// int		ft_rsa_flag_pubin();
// {
// 	if (pubin)
// 		public key;
// 	else
// 		if (ft_asn1_decode_private_key(&rsa.data, rsa.text, rsa.len))
	//	return (1);
	//return (0);
//}

void	ft_rsa(void *v_data)
{
	t_rsa	rsa;

	rsa.flag = *(t_rsa_flag *)v_data;
	if (ft_rsa_make_flag_in(&rsa.text, &rsa.len, rsa.flag.in))
		return ;
	if (ft_rsa_get_asn1_text(&rsa))
		return ;
	//ft_rsa_flag_pubin();
	ft_printf("writing RSA key\n");


	////check flag text;

	
	///check flag pubout;


	
	// if (ft_make_genrsa_data(&rsa))
	// 	return ;
	// ft_close_fd(rsa.flag.rand_fd);
	// ft_genrsa_make_asn1_text(&rsa);
	// ft_rsa_free_data(&rsa.data);
	//ft_rsa_make_flag_out(rsa.text, rsa.len, rsa.flag.out);
	ft_strdel(&rsa.text);
}
