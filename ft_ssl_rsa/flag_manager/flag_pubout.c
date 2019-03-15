/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pubout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:53:49 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_pubout(t_rsa *rsa)
{
	if (rsa->flag.pubin || rsa->flag.pubout)
	{
		ft_asn1_encode_public_key(&rsa->data, &rsa->text, &rsa->len);
		if (ft_pem_outform_public_key(&rsa->text, &rsa->len))
			return (1);
		return (0);
	}
	ft_asn1_encode_private_key(&rsa->data, &rsa->text, &rsa->len);
	if (ft_pem_outform_private_key(&rsa->text, &rsa->len))
		return (1);
	return (0);
}

int		ft_rsa_check_flag_pubout(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	USE(flag);
	flag->pubout = 1;
	return (0);
}
