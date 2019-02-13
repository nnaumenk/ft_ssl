/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:15:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/29 16:15:44 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_precision_wstr(wchar_t *str, int len, t_list *my)
{
	int		i;
	char	*str_full;
	char	*buf;
	int		len_full;

	i = -1;
	str_full = ft_my_strnew(0);
	len_full = 0;
	while (++i < len)
	{
		buf = ft_wchardup(str[i], my);
		if (len_full + my->len > my->precision_field)
			break ;
		str_full = ft_str_join_free(str_full, buf, len_full, my->len);
		len_full += my->len;
	}
	my->len = len_full;
	return (str_full);
}

char	*ft_wstrdup_wstr(wchar_t *str, int len, t_list *my)
{
	int		i;
	char	*str_full;
	char	*buf;
	int		len_full;

	i = -1;
	str_full = ft_my_strnew(0);
	len_full = 0;
	while (++i < len)
	{
		buf = ft_wchardup(str[i], my);
		str_full = ft_str_join_free(str_full, buf, len_full, my->len);
		len_full += my->len;
	}
	my->len = len_full;
	return (str_full);
}

char	*ft_wstrdup(wchar_t *str, t_list *my)
{
	int		len;
	char	*new;

	if (str == NULL)
		str = L"(null)";
	len = 0;
	while (str[len])
		++len;
	if (my->precision_field == -1)
		new = ft_wstrdup_wstr(str, len, my);
	else
		new = ft_set_precision_wstr(str, len, my);
	return (new);
}

char	*ft_wchardup2(char *str, wchar_t c, t_list *my)
{
	if (c <= 0x10FFFF && MB_CUR_MAX > 3)
	{
		my->len = 4;
		str[0] = ((c >> 18) + 0xF0);
		str[1] = (((c >> 12) & 0x3F) + 0x80);
		str[2] = (((c >> 6) & 0x3F) + 0x80);
		str[3] = ((c & 0x3F) + 0x80);
	}
	else
	{
		my->len = 1;
		str[0] = c;
		my->unicode_check = 1;
	}
	return (str);
}

char	*ft_wchardup(wchar_t c, t_list *my)
{
	char *str;

	str = ft_my_strnew(MB_CUR_MAX);
	if (c <= 127)
	{
		my->len = 1;
		str[0] = c;
	}
	else if (c <= 0x7FF && MB_CUR_MAX > 1)
	{
		my->len = 2;
		str[0] = ((c >> 6) + 0xC0);
		str[1] = ((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF && MB_CUR_MAX > 2)
	{
		my->len = 3;
		str[0] = ((c >> 12) + 0xE0);
		str[1] = (((c >> 6) & 0x3F) + 0x80);
		str[2] = ((c & 0x3F) + 0x80);
	}
	else
		str = ft_wchardup2(str, c, my);
	return (str);
}
