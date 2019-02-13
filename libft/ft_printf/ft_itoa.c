/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:40:17 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:40:18 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_int(char *str_base, t_list *my, long n, int base)
{
	char	*str;

	if (n == 0 && my->precision_field == 0)
		return (ft_my_strdup_precision("", my));
	if ((unsigned long)n == 0x8000000000000000)
		return (ft_set_precision_long_min(my));
	my->len = ft_numcount_base_sign(n, base);
	my->buf = 0;
	if (n < 0)
	{
		my->buf = 1;
		n = -n;
	}
	if ((my->len - my->buf) < my->precision_field)
		my->len = my->precision_field + my->buf;
	my->i = my->len;
	str = ft_my_strnew(my->len);
	while (my->i-- > my->buf)
	{
		str[my->i] = str_base[n % base];
		n /= base;
	}
	if (my->buf)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_base_unint(char *str_base, t_list *my,
unsigned long n, int base)
{
	char			*str;
	int				i;

	if (n == 0 && my->precision_field == 0)
		return (ft_my_strdup_precision("", my));
	my->len = ft_numcount_base_unsign(n, base);
	if (my->len < my->precision_field)
		my->len = my->precision_field;
	str = ft_my_strnew(my->len);
	i = my->len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	return (str);
}

char	*ft_itoa_base_unint_x(char *str_base, t_list *my,
unsigned long n, int base)
{
	char			*str;
	int				i;
	unsigned long	num;

	num = n;
	if (n == 0 && my->precision_field == 0)
		return (ft_my_strdup_precision("", my));
	my->len = ft_numcount_base_unsign(n, base);
	if (my->len < my->precision_field)
		my->len = my->precision_field;
	str = ft_my_strnew(my->len);
	i = my->len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	if (my->flag_hash == '#' && num)
		str = ft_flag_hash_x(str, my);
	return (str);
}

char	*ft_itoa_base_unint_o(char *str_base, t_list *my,
unsigned long n, int base)
{
	char			*str;
	int				i;

	my->len = ft_numcount_base_unsign(n, base);
	if (my->len < my->precision_field)
		my->len = my->precision_field;
	if (my->precision_field == 0 && n == 0)
		my->len = my->precision_field;
	str = ft_my_strnew(my->len);
	i = my->len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	if (my->flag_hash == '#' && str[0] != '0')
		str = ft_flag_hash_o(str, my);
	return (str);
}

char	*ft_itoa_pointer(char *str_base, t_list *my,
unsigned long n, int base)
{
	char	*str;
	int		i;

	my->len = ft_numcount_base_unsign(n, base);
	if (my->precision_field > my->len)
		my->len = my->precision_field;
	if (my->precision_field == 0 && n == 0)
		my->len = 0;
	my->len += 2;
	str = ft_my_strnew(my->len);
	i = my->len;
	while (i-- > 2)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
