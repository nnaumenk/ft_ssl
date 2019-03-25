/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsautl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 16:29:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_rsa_check_text_len(t_rsa *rsa)
{
	if (rsa->len == 0)
	{
		ft_print_fd(2, "ft_ssl: error reading input data\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	return (0);
}

void		ft_rsautl(void *v_data)
{
	t_rsa	rsa;

	rsa.flag = *(t_rsa_flag *)v_data;
	if (rsa.flag.decrypt && rsa.flag.pubin)
	{
		ft_print_fd(2, "ft_ssl: a private key is needed for this operation\n");
		return ;
	}
	if (ft_rsa_make_flag_inkey(&rsa))
		return ;
	if (ft_rsa_make_flag_in(&rsa))
		return ;
	if (ft_rsa_check_text_len(&rsa))
		return ;
	ft_denormalize_input_rsa_values(&rsa);
	if (ft_rsa_make_flag_decrypt(&rsa))
		return ;
	ft_rsa_make_flag_out(&rsa);
}
