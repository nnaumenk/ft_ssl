/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:34:38 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/18 12:38:11 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_atoa_to_hex_str(char *str, t_list *my)
{
	char	*buf;
	int		len;

	str = ft_join_char(str, my->len, my->type_field + 15);
	len = my->len + 1;
	my->precision_field = -1;
	buf = ft_itoa_base_int("0123456789", my, my->buf, 10);
	if (buf[0] != '-')
	{
		str = ft_join_char(str, len, '+');
		++len;
	}
	str = ft_str_join_free(str, buf, len, my->len);
	my->len += len;
	return (str);
}

int		ft_atoa_to_hex_counter(double num, int pr)
{
	int count;
	int	mantisa;

	if (pr >= 0)
		return (pr);
	count = 0;
	while (num)
	{
		++count;
		num *= 16.0;
		mantisa = (int)num;
		num -= mantisa;
	}
	return (count);
}

char	*ft_atoa_to_hex(double num, t_list *my, int symbol, char *base)
{
	char		*str;
	int			mantisa;
	int			i;

	my->len = ft_atoa_to_hex_counter(num, my->precision_field) + 1;
	if (my->len > 1)
		my->dot = 1;
	else
		my->dot = 0;
	my->len += my->dot;
	str = ft_strnew(my->len);
	i = -1;
	str[++i] = base[symbol];
	if (my->dot)
		str[++i] = '.';
	while (++i < my->len)
	{
		num *= 16.0;
		mantisa = (int)num;
		str[i] = base[mantisa];
		num -= mantisa;
	}
	if ((num * 16.0) >= 7.0 && my->precision_field >= 0)
		str[i - 1] = base[str[i - 1] + 1 - '0'];
	return (str);
}

int		ft_atoa_pow(long double *n, double m)
{
	int	pow;

	pow = 0;
	if (*n >= m - 1.0)
	{
		while (*n >= m)
		{
			++pow;
			*n /= 2.0;
		}
	}
	else
	{
		while (*n < m)
		{
			*n *= 2.0;
			--pow;
		}
		++pow;
		*n /= 2.0;
	}
	return (pow);
}

char	*ft_atoa(long double n, t_list *my)
{
	double		buf;
	char		*str_ptr;
	char		*str;
	int			symbol;
	int			sign;

	buf = n;
	str_ptr = ft_float_binary((unsigned long*)(&buf));
	str_ptr = ft_float_check(str_ptr, my);
	if (my->len)
		return (str_ptr);
	sign = ft_float_minus(&n);
	symbol = ft_atoa_help(&n, my);
	if (my->type_field == 'A')
		str = ft_atoa_to_hex(n, my, symbol, "0123456789ABCDEF");
	else
		str = ft_atoa_to_hex(n, my, symbol, "0123456789abcdef");
	str = ft_atoa_to_hex_str(str, my);
	str = ft_atoa_add_prefix(str, my, sign);
	return (str);
}
