/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:36:13 by nnaumenk         ###   ########.fr       */
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






void	ft_rsa(void *v_data)
{
	t_rsa	rsa;

	rsa.flag = *(t_rsa_flag *)v_data;
	if (ft_rsa_make_flag_in(&rsa.text, &rsa.len, rsa.flag.in))
		return ;
	if (ft_rsa_make_flag_pubin(&rsa))
		return ;
	ft_printf("writing RSA key\n");


	////check flag text;

	//if (flag->noout)
		///check flag pubout;


	
	// if (ft_make_genrsa_data(&rsa))
	// 	return ;
	// ft_close_fd(rsa.flag.rand_fd);
	// ft_genrsa_make_asn1_text(&rsa);
	// ft_rsa_free_data(&rsa.data);
	//ft_rsa_make_flag_out(rsa.text, rsa.len, rsa.flag.out);
	ft_strdel(&rsa.text);
}
