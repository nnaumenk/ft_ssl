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

void	ft_rsa(void *v_data)
{
	t_rsa	data;

	data.flag = *(t_rsa_flag *)v_data;
	data.flag.fd_input = ft_make_input_fd(data.flag.in);
	data.flag.fd_output = ft_make_output_fd(data.flag.out);
	data.text = ft_read_from(data.flag.fd_input, &data.len);
	ft_rsa_make_flag_text(&data);
}
