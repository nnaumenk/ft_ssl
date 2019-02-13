/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:26:08 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/12 19:26:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_counter(t_list *my)
{
	if (my->len_field == -1)
		*va_arg(my->ptr, int*) = my->len_full;
	else if (my->len_field == 0)
		*va_arg(my->ptr, char*) = my->len_full;
	else if (my->len_field == 1)
		*va_arg(my->ptr, short*) = my->len_full;
	else
		*va_arg(my->ptr, long*) = my->len_full;
}

char	*ft_date_iso(t_list *my)
{
	const char	*base = "0123456789";
	char		*str;
	char		*buf;
	int			len;

	str = ft_itoa_base_unint((char *)base, my, va_arg(my->ptr, int), 10);
	str = ft_str_join_char_free(str, my->len, '-');
	len = my->len + 1;
	buf = ft_itoa_base_unint((char *)base, my, va_arg(my->ptr, int), 10);
	str = ft_str_join_free(str, buf, len, my->len);
	len += my->len;
	str = ft_str_join_char_free(str, my->len, '-');
	len = my->len + 1;
	buf = ft_itoa_base_unint((char *)base, my, va_arg(my->ptr, int), 10);
	str = ft_str_join_free(str, buf, len, my->len);
	len += my->len;
	return (str);
}

char	*ft_notprintable_str(char *str, int len, int i)
{
	char *new;

	new = ft_strnew(len);
	while (len)
	{
		if (str[i] >= 32 && str[i] < 127)
			new[--len] = str[i--];
		else
		{
			new[--len] = 0x40 + str[i--];
			if (new[len] == -65)
				new[len] = 0x40 - 1;
			new[--len] = '^';
		}
	}
	ft_strdel(&str);
	return (new);
}

char	*ft_notprintable(char *str, t_list *my)
{
	int i;
	int j;

	if (str == NULL)
		return (NULL);
	i = -1;
	j = 2;
	while (str[++i])
		if ((str[i] >= 0 && str[i] < 32) || str[i] == 127)
			++j;
	my->len = i + j;
	return (ft_notprintable_str(str, my->len, i));
}
