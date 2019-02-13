/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:39:27 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:39:28 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_dolar(t_list my)
{
	while (my.buf-- > 1)
		va_arg(my.ptr, int);
	return (va_arg(my.ptr, int));
}

char	*ft_flag_hash_x(char *str, t_list *my)
{
	char	*new;
	int		len;

	len = my->len;
	new = ft_my_strnew(len + 2);
	new[0] = '0';
	new[1] = my->type_field;
	while (len--)
		new[2 + len] = str[len];
	ft_strdel(&str);
	my->len += 2;
	return (new);
}

char	*ft_flag_hash_o(char *str, t_list *my)
{
	char	*new;
	int		len;

	len = my->len;
	new = ft_my_strnew(len + 1);
	new[0] = '0';
	while (len--)
		new[1 + len] = str[len];
	ft_strdel(&str);
	my->len += 1;
	return (new);
}

char	*ft_flag_plus(char *str, t_list *my)
{
	char	*new;
	int		i;

	if (str[0] != '-')
	{
		if (ft_strchr("aAeEfFgGdiD", my->type_field))
		{
			++my->len;
			new = ft_my_strnew(my->len);
			new[0] = '+';
			i = 0;
			while (++i < my->len)
				new[i] = str[i - 1];
			ft_strdel(&str);
			return (new);
		}
	}
	return (str);
}

char	*ft_flag_space(char *str, t_list *my)
{
	char	*new;
	int		i;

	if (str[0] != '-')
	{
		if (ft_strchr("aAeEfFgGdiD", my->type_field))
		{
			++my->len;
			new = ft_my_strnew(my->len);
			new[0] = ' ';
			i = 0;
			while (++i < my->len)
				new[i] = str[i - 1];
			ft_strdel(&str);
			return (new);
		}
	}
	return (str);
}
