/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:00:26 by nnaumenk         ###   ########.fr       */
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
	if (ft_rsa_make_flag_in(&rsa))
		return ;
	if (ft_rsa_make_flag_inform(&rsa))
		return ;

	ft_normalize_input_rsa_values(&rsa);

	ft_rsa_make_flag_text(&rsa);
	ft_rsa_make_flag_modulus(&rsa);
	ft_rsa_make_flag_check(&rsa);

	ft_printf("writing RSA key\n");
	
	if (ft_rsa_make_flag_outform(&rsa))
		return ;
	ft_rsa_make_flag_out(&rsa);

	
}
