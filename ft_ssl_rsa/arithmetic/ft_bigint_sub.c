/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:29:21 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static void	ft_sub_8byte(void **mem1, void **mem2, size_t i, char *overflow)
{
	size_t			*val1;
	size_t			*val2;
	size_t			sum64;

	val1 = (size_t *)*mem1;
	val2 = (size_t *)*mem2;
	while (i--)
	{
		sum64 = *val1 - *val2 - *overflow;
		if (*val2 > *val1)
			*overflow = 1;
		else if (*val2 == *val1 && *overflow)
			*overflow = 1;
		else
			*overflow = 0;
		*val1 = sum64;
		val1++;
		val2++;
	}
	*mem1 = val1;
	*mem2 = val2;
}

static void	ft_sub_1byte(void **mem1, void **mem2, size_t i, char *overflow)
{
	unsigned char	*val1;
	unsigned char	*val2;
	unsigned char	sum8;
	
	val1 = (unsigned char *)*mem1;
	val2 = (unsigned char *)*mem2;
	while (i--)
	{
		sum8 = *val1 - *val2 - *overflow;
		if (*val2 > *val1)
			*overflow = 1;
		else if (*val2 == *val1 && *overflow)
			*overflow = 1;
		else
			*overflow = 0;
		*val1 = sum8;
		val1++;
		val2++;
	}
	*mem1 = val1;
	*mem2 = val2;
}

void		ft_bigint_sub(void **mem1, void **mem2, size_t *n1, size_t *n2)
{
	void			*val1;
	void			*val2;
	char			overflow;

	if (ft_bigint_smaller(*mem1, *mem2, *n1, *n2))
	{
		ft_bzero(*mem1, *n1);
		return ;
	}
	val1 = *mem1;
	val2 = *mem2;
	overflow = 0;
	ft_sub_8byte(&val1, &val2, *n2 / sizeof(size_t), &overflow);
	ft_sub_1byte(&val1, &val2, *n2 % sizeof(size_t), &overflow);
	if (overflow)
		ft_bigint_decrement(val1, *n1 - *n2);
	ft_bigint_normalize(*mem1, n1);
}
