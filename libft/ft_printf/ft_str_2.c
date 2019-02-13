/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:26:12 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/19 17:26:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchardup(int len, char c)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	i = -1;
	while (++i < len)
		str[i] = c;
	return (str);
}

int		ft_strcount(char *str, int *spec)
{
	int			i;
	int			count;
	char const	*base = "0123456789abcdefABCDEF";

	count = 0;
	i = -1;
	while (str[++i])
		if (ft_strchr((char *)base, str[i]))
			++count;
	if (spec[4] == '#' && count > 0)
		count--;
	return (count);
}

char	*ft_my_strnew(int size)
{
	char	*s;

	s = (char *)malloc(size + 1);
	s[size] = '\0';
	return (s);
}

char	*ft_my_strdup(char *s, t_list *my)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	my->len = ft_strlen(s);
	str = ft_my_strnew(my->len);
	i = -1;
	while (++i < my->len)
		str[i] = s[i];
	return (str);
}

char	*ft_my_strdup_precision(char *s, t_list *my)
{
	char	*str;
	int		i;

	if (s == NULL)
		s = "(null)";
	my->len = ft_strlen(s);
	if (my->precision_field != -1)
		if (my->len > my->precision_field)
			my->len = my->precision_field;
	str = ft_my_strnew(my->len);
	i = -1;
	while (++i < my->len)
		str[i] = s[i];
	return (str);
}
