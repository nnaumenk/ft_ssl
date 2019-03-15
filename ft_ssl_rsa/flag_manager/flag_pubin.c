/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pubin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:38:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_pubin(t_rsa *rsa)
{
	if (rsa->flag.pubin)
	{
		ft_printf("1\n");
		if (ft_asn1_get_public_text(&rsa->text, &rsa->len))
		{
			ft_print_fd(2, "ft_ssl: unable to load Public Key\n");
			return (1);
		}
		ft_printf("1\n");
		if (ft_asn1_decode_public_key(&rsa->data, rsa->text, rsa->len))
		{
			ft_print_fd(2, "ft_ssl: unable to load Public Key\n");
			return (1);
		}
		return (0);
	}
	printf("1\n");
	if (ft_asn1_get_private_text(&rsa->text, &rsa->len))
	{
		ft_print_fd(2, "ft_ssl: unable to load Private Key\n");
		return (1);
	}
	printf("1\n");
	if (ft_asn1_decode_private_key(&rsa->data, rsa->text, rsa->len))
	{
		ft_print_fd(2, "ft_ssl: unable to load Private Key\n");
		return (1);
	}
	return (0);
}

int		ft_rsa_check_flag_pubin(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	USE(flag);
	flag->pubin = 1;
	return (0);
}
