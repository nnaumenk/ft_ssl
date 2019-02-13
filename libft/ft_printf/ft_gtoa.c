/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/14 15:06:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_gtoa_flag_hash(char *str, t_list *my)
{
	char	*new;
	int		i;
	int		len;
	int		dot;

	i = ft_char_index(str, '.');
	if (i == my->len)
		dot = 1;
	else
		dot = 0;
	len = my->len + 2;
	new = ft_strnew(len);
	i = -1;
	while (++i < my->len)
		new[i] = str[i];
	if (dot)
		new[i++] = '.';
	--i;
	while (++i < len)
		new[i] = '0';
	my->len = len;
	ft_strdel(&str);
	return (new);
}

char	*ft_gtoa(double n, t_list *my)
{
	char	*str_ptr;
	char	*str;

	str_ptr = ft_float_binary((unsigned long*)(&n));
	str_ptr = ft_float_check(str_ptr, my);
	if (my->len)
		return (str_ptr);
	if (my->precision_field == -1)
		my->precision_field = 6;
	my->dot = 0;
	if (my->flag_hash)
		my->dot = 1;
	str = ft_float(str_ptr, my);
	str = ft_gtoa_precision(str, my);
	if (!my->flag_hash)
		str = ft_cut_after(str, &my->len);
	if (str_ptr[0] == '1')
		str = ft_float_add_minus(str, my);
	ft_strdel(&str_ptr);
	return (str);
}
