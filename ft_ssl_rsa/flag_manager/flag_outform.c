/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_outform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:03:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	(*g_inform[])(t_rsa *) =
{
	ft_pem_outform_private_key,
	ft_der_outform_private_key,
	ft_pem_outform_public_key,
	ft_der_outform_public_key
};

int		ft_rsa_make_flag_outform(t_rsa *rsa)
{
	if (rsa->flag.noout)
	{
		ft_rsa_free_data(&rsa->data);
		return (1);
	}
	if ((g_inform[rsa->flag.pubout * 2 + rsa->flag.outform])(rsa))
	{
		ft_rsa_free_data(&rsa->data);
		return (1);
	}
	ft_rsa_free_data(&rsa->data);
	return (0);
}
int		ft_rsa_check_flag_outform(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing format argument for %s\n", av[*i - 1]);
		return (1);
	}
	if (ft_strequ(av[*i], "PEM") || ft_strequ(av[*i], "pem"))
		flag->inform = 0;
	if (ft_strequ(av[*i], "DER") || ft_strequ(av[*i], "der"))
		flag->inform = 1;
	else
		return (1);
	return (0);
}
