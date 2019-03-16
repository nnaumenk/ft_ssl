/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/16 13:47:18 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static char	g_logarithm_2[] =
{
	-1,  0,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,
	 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
	 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
	 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
};

static void	ft_print_numbits(char *key, t_bigint *modulus)
{
	size_t			high_byte_number;
	size_t			numbits;

	if (modulus->value[modulus->size - 1])
		high_byte_number = modulus->size - 1;
	else
		high_byte_number = modulus->size - 2;
	numbits = high_byte_number * 8;
	numbits += g_logarithm_2[modulus->value[high_byte_number]] + 1;
	ft_printf("%s (%zu bit)\n", key, numbits);
}

int			ft_rsa_make_flag_text(t_rsa *rsa)
{
	if (rsa->flag.text)
	{
		if (rsa->flag.pubin)
		{
			ft_print_numbits("Public-Key:", &rsa->data.modulus);
			ft_bigint_print("Modulus:", &rsa->data.modulus);
			ft_bigint_print("Exponent:", &rsa->data.modulus);
		}
		else
		{
			ft_print_numbits("Private-Key:", &rsa->data.modulus);
			ft_bigint_print("modulus:", &rsa->data.modulus);
			ft_bigint_print("publicExponent:", &rsa->data.public_exponent);
			ft_bigint_print("privateExponent:", &rsa->data.private_exponent);
			ft_bigint_print("prime1:", &rsa->data.prime1);
			ft_bigint_print("prime2:", &rsa->data.prime2);
			ft_bigint_print("exponent1:", &rsa->data.exponent1);
			ft_bigint_print("exponent2:", &rsa->data.exponent2);
			ft_bigint_print("coefficient:", &rsa->data.coefficient);
		}
	}
	return (0);
}

int			ft_rsa_check_flag_text(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->text = 1;
	return (0);
}
