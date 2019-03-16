/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_modulus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/16 13:37:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_make_flag_modulus(t_rsa *rsa)
{
	size_t			i;
	unsigned char	*byte;
	
	if (rsa->flag.modulus)
	{
		ft_printf("Modulus=");
		i = rsa->data.modulus.size;
		byte = rsa->data.modulus.value + i;
		while (i--)
			ft_printf("%.2hhX", *--byte);
		ft_printf("\n");
	}
	return (0);
}

int		ft_rsa_check_flag_modulus(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->modulus = 1;
	return (0);
}
