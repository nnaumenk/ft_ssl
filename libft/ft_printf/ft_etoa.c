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

char	*ft_etoa_precision_minus(char *str, t_list *my, int first_num_ind)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	len = my->len;
	my->dot = ft_float_dot(my);
	my->len = 1 + my->precision_field + my->dot;
	new = ft_strnew(my->len);
	i = first_num_ind;
	if (i == -1)
		i = 0;
	j = -1;
	new[++j] = str[i];
	if (my->dot)
		new[++j] = '.';
	while (++j < my->len && ++i < len)
		new[j] = str[i];
	--j;
	while (++j < my->len)
		new[j] = '0';
	if (str[i] >= '5')
		new = ft_round_float(new, my);
	return (new);
}

char	*ft_etoa_precision_plus(char *str, t_list *my, int dot_index)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	len = my->len;
	my->len = 1 + my->precision_field + my->dot;
	new = ft_strnew(my->len);
	new[0] = str[0];
	i = 1;
	if (my->dot)
		new[i++] = '.';
	j = 1;
	while (i < my->len && j < dot_index)
		new[i++] = str[j++];
	my->buf = 0;
	if (str[j] == '.')
		my->buf = 1;
	while (i < my->len && j + my->buf < len)
		new[i++] = str[my->buf + j++];
	while (i < my->len)
		new[i++] = '0';
	if (str[j + my->buf] >= '6' - my->buf)
		new = ft_round_float(new, my);
	return (new);
}

char	*ft_etoa_help(char *str, t_list *my)
{
	int		counter_index;
	char	*new;

	if (str[0] != '0')
	{
		counter_index = ft_char_index(str, '.');
		my->dot = ft_float_dot(my);
		new = ft_etoa_precision_plus(str, my, counter_index--);
		ft_strdel(&str);
	}
	else
	{
		counter_index = ft_nochar_index(str, '0', '.');
		new = ft_etoa_precision_minus(str, my, counter_index);
		if (counter_index == -1)
			counter_index = 0;
		else
			counter_index = -counter_index + 1;
		ft_strdel(&str);
	}
	new = ft_float_add_exponent(new, my, counter_index, my->type_field);
	return (new);
}

char	*ft_etoa(double n, t_list *my)
{
	char	*str_ptr;
	char	*str;

	str_ptr = ft_float_binary((unsigned long*)(&n));
	str_ptr = ft_float_check(str_ptr, my);
	if (my->len)
		return (str_ptr);
	str = ft_float(str_ptr, my);
	str = ft_etoa_help(str, my);
	if (str_ptr[0] == '1')
		str = ft_float_add_minus(str, my);
	ft_strdel(&str_ptr);
	return (str);
}
