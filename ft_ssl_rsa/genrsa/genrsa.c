/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:25:22 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_make_data(t_rsa *rsa)
{
	if (ft_make_primes(rsa))
		return (1);
	ft_make_public_exponent(&rsa->data.public_exponent, rsa->flag.exp_value_3);
	ft_find_prime_number(&rsa->data.prime1, &rsa->data.public_exponent);
	ft_find_prime_number(&rsa->data.prime2, &rsa->data.public_exponent);
	ft_bigint_mul(&rsa->data.modulus, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_private_exponent(&rsa->data.private_exponent,
	&rsa->data.public_exponent, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_exponent(&rsa->data.exponent1, &rsa->data.private_exponent,
	&rsa->data.prime1);
	ft_make_exponent(&rsa->data.exponent2, &rsa->data.private_exponent,
	&rsa->data.prime2);
	ft_mod_inverse(
	&rsa->data.coefficient, &rsa->data.prime2, &rsa->data.prime1);
	return (0);
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
	if (ft_make_data(&rsa))
		return ;
	ft_close_fd(rsa.flag.rand_fd);
	ft_normalize_input_rsa_values(&rsa);
	ft_pem_outform_private_key(&rsa);
	ft_rsa_free_data(&rsa.data);
	ft_rsa_make_flag_out(&rsa);
}
