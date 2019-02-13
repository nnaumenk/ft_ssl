/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:00:07 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/26 15:00:08 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cut(char *str, int *len)
{
	char	*new;
	int		i;
	int		j;

	if ((str[0] == '0' && str[1] == '.') || str[0] != '0')
		return (str);
	i = 0;
	while (++i < *len)
		if (str[i] != '0')
			break ;
	if (str[i] == '\0')
		--i;
	*len = *len - i;
	new = ft_my_strnew(*len);
	j = -1;
	while (++j < *len)
		new[j] = str[i + j];
	ft_strdel(&str);
	return (new);
}

char	*ft_str_mul_two(char *s, int *len)
{
	int		i;
	char	*str;
	int		buf;

	i = *len;
	str = ft_my_strnew(++(*len));
	buf = 0;
	while (i--)
	{
		str[i + 1] = (((s[i] - '0') * 2) + buf) % 10 + '0';
		buf = (((s[i] - '0') * 2) + buf) / 10;
	}
	str[i + 1] = buf + '0';
	str = ft_cut(str, len);
	ft_strdel(&s);
	return (str);
}

char	*ft_pow_two(int pow, t_list *my)
{
	char *str;

	str = ft_my_strdup("1", my);
	if (pow > 0)
		while (pow-- > 0)
			str = ft_str_mul_two(str, &my->len);
	else if (pow < 0)
		while (pow++ < 0)
			str = ft_str_div_two(str, &my->len);
	return (str);
}

int		ft_dot(int *dot, char s_i, char *s)
{
	if (s_i == '.')
	{
		*dot = 0;
		*s = '.';
		return (1);
	}
	return (0);
}

char	*ft_str_div_two(char *s, int *len)
{
	char	*str;
	int		i;
	int		buf;
	int		dot;

	str = ft_strnew(*len + 2);
	i = -1;
	buf = 0;
	dot = 1;
	while (++i < *len)
	{
		if (ft_dot(&dot, s[i], &str[i]))
			continue ;
		str[i] = (buf + s[i] - '0') / 2 + '0';
		buf = ((buf + s[i] - '0') % 2) * 10;
	}
	if (dot && buf)
		str[i++] = '.';
	if (buf)
		str[i++] = buf / 2 + '0';
	*len = i;
	str = ft_cut(str, len);
	ft_strdel(&s);
	return (str);
}
