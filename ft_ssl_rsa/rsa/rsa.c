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
