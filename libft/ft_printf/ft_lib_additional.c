/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_additional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:44:22 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:44:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_numcount_base_sign(long n, int base)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

int			ft_numcount_base_unsign(unsigned long n, int base)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

int			ft_char_index(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (i);
}

int			ft_nochar_index(char *str, char c1, char c2)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] != c1 && str[i] != c2)
			return (i);
	return (-1);
}
