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
	if (ft_make_genrsa_data(&rsa))
		return ;
	ft_close_fd(rsa.flag.rand_fd);
	ft_normalize_input_rsa_values(&rsa);
	ft_pem_outform_private_key(&rsa);
	ft_rsa_free_data(&rsa.data);
	ft_rsa_make_flag_out(&rsa);
	ft_strdel(&rsa.text);
}
