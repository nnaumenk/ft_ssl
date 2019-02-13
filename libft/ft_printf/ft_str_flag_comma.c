/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_flag_comma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:40:51 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/05 11:40:53 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_comma_decimal(char *str, t_list *my)
{
	char	*new;
	int		len1;
	int		len2;
	int		buf;

	len1 = my->len;
	if (str[0] == '-')
		--len1;
	len2 = my->len + ((len1 - 1) / 3);
	my->len = len2;
	new = ft_my_strnew(my->len);
	buf = 0;
	if (str[0] == '-')
		++len1;
	while (len2)
	{
		new[--len2] = str[--len1];
		if (++buf % 3 == 0 && len1)
			if (str[len1 - 1] != '-')
				new[--len2] = ',';
	}
	return (new);
}

char	*ft_flag_comma_float(char *str, t_list *my)
{
	char	*new;
	int		len1;
	int		len2;
	int		buf;
	int		count;

	len1 = ft_char_index(str, '.');
	count = my->len - len1;
	if (str[0] == '-')
		--len1;
	len2 = my->len + ((len1 - 1) / 3);
	my->len = len2;
	new = ft_my_strnew(my->len);
	buf = 0;
	if (str[0] == '-')
		++len1;
	while (count--)
		new[--len2] = str[len1 + count];
	while (len2)
	{
		new[--len2] = str[--len1];
		if (++buf % 3 == 0 && len1 && str[len1 - 1] != '-')
			new[--len2] = ',';
	}
	return (new);
}

char	*ft_flag_comma_pointer(char *str, t_list *my)
{
	char	*new;
	int		len1;
	int		len2;
	int		buf;

	len1 = my->len;
	if (str[0] == '0')
		len1 -= 2;
	len2 = my->len + ((len1 - 1) / 3);
	my->len = len2;
	new = ft_my_strnew(my->len);
	buf = 0;
	if (str[0] == '0')
		len1 += 2;
	while (len2--)
	{
		new[len2] = str[--len1];
		if (len1 >= 1)
			if (str[len1 - 1] == 'x')
				buf = 0;
		if (++buf % 3 == 0 && len1)
			new[--len2] = ',';
	}
	return (new);
}

char	*ft_flag_comma(char *str, t_list *my)
{
	char	*new;

	if (my->type_field == 'p')
		new = ft_flag_comma_pointer(str, my);
	else if (ft_strchr("fFeEgG", my->type_field))
		new = ft_flag_comma_float(str, my);
	else if (ft_strchr("dDioOuU", my->type_field))
		new = ft_flag_comma_decimal(str, my);
	else
		return (str);
	ft_strdel(&str);
	return (new);
}
