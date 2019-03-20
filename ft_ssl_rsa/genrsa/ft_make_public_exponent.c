/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_genrsa_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:25:29 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	ft_make_public_exponent(t_bigint *exp, int exp_value_3)
{
	if (exp_value_3 == 0)
	{
		exp->value = (unsigned char *)malloc(3);
		exp->size = 3;
		*(unsigned int *)(exp->value) = 65537;
	}
	else
	{
		exp->value = (unsigned char *)malloc(1);
		exp->size = 1;
		*(unsigned char *)exp->value = 3;
	}
	ft_bigint_print("e is", exp);
}
