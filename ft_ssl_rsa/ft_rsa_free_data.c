/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa_free_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:25:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

void	ft_rsa_free_data(t_rsa_data *data)
{
	ft_bigint_del(&data->modulus);
	ft_bigint_del(&data->public_exponent);
	ft_bigint_del(&data->private_exponent);
	ft_bigint_del(&data->prime1);
	ft_bigint_del(&data->prime2);
	ft_bigint_del(&data->exponent1);
	ft_bigint_del(&data->exponent2);
	ft_bigint_del(&data->coefficient);
}
