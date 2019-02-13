/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:48:22 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/03 10:48:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_float_minus(long double *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

char	*ft_float_add_minus(char *str, t_list *my)
{
	char	*new;
	int		i;

	new = ft_strnew(++my->len);
	new[0] = '-';
	i = 0;
	while (++i < my->len)
		new[i] = str[i - 1];
	ft_strdel(&str);
	return (new);
}

char	*ft_float_binary(unsigned long *ptr)
{
	char	*str;
	int		len;

	len = 64;
	str = ft_strnew(len);
	while (len)
	{
		str[--len] = *ptr % 2 + '0';
		*ptr /= 2;
	}
	return (str);
}

int		ft_float_dot(t_list *my)
{
	if (my->precision_field == -1)
		my->precision_field = 6;
	if (my->precision_field)
		return (1);
	return (0);
}

char	*ft_float_add_exponent(char *str, t_list *my, int count, char type)
{
	int		len;
	int		i;
	char	*new;

	if (my->flag_hash)
		if (ft_char_index(str, '.') == -1)
			str = ft_str_join_char_free(str, my->len++, '.');
	if (count > 99 || count < -99)
		len = 3;
	else
		len = 2;
	new = ft_strnew(len + my->len + 2);
	i = -1;
	while (++i < my->len)
		new[i] = str[i];
	my->len += 2 + len;
	new[i++] = type;
	new[i++] = ft_minus(&count);
	while (len--)
	{
		new[i + len] = count % 10 + '0';
		count /= 10;
	}
	ft_strdel(&str);
	return (new);
}
