/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:34:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/14 13:34:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa_precision2(char *new, char *str, t_list *my, int af)
{
	if (my->dot)
		new[my->i++] = '.';
	while (af-- > 1 && my->precision_field > 0)
	{
		--my->precision_field;
		new[my->i] = str[my->i];
		++my->i;
	}
	my->len = my->i;
	if (af > 0)
		if (str[my->i + 1 - my->dot] >= '5')
			new = ft_round_float(new, my);
	my->i = my->len;
	while (my->precision_field-- > 0)
		new[my->i++] = '0';
	my->len = my->i;
	ft_strdel(&str);
	return (new);
}

char	*ft_ftoa_precision(char *str, t_list *my)
{
	int		after_dot_len;
	int		before_dot_len;
	char	*new;

	my->dot = ft_float_dot(my);
	my->i = -1;
	while (++my->i < my->len)
		if (str[my->i] == '.')
			break ;
	before_dot_len = my->i;
	after_dot_len = my->len - before_dot_len;
	new = ft_strnew(before_dot_len + my->precision_field + my->dot);
	my->i = -1;
	while (++my->i < before_dot_len)
		new[my->i] = str[my->i];
	new = ft_ftoa_precision2(new, str, my, after_dot_len);
	return (new);
}

char	*ft_ftoa(double n, t_list *my)
{
	char	*str_ptr;
	char	*str;

	str_ptr = ft_float_binary((unsigned long*)(&n));
	str_ptr = ft_float_check(str_ptr, my);
	if (my->len)
		return (str_ptr);
	str = ft_float(str_ptr, my);
	str = ft_ftoa_precision(str, my);
	if (str_ptr[0] == '1')
		str = ft_float_add_minus(str, my);
	if (my->flag_hash)
		if (ft_char_index(str, '.') == my->len)
			str = ft_str_join_char_free(str, my->len++, '.');
	ft_strdel(&str_ptr);
	return (str);
}
