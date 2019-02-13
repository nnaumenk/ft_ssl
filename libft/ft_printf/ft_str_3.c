/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:45:32 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/02 15:45:45 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cut_after(char *str, int *len)
{
	char	*new;
	int		i;

	if (ft_char_index(str, '.') == *len)
		return (str);
	i = *len;
	while (i--)
		if (str[i] != '0')
			break ;
	if (i == -1)
		i = 0;
	if (str[i] == '.')
		i--;
	*len = i + 1;
	new = ft_strnew(*len);
	new[i] = str[i];
	while (i--)
		new[i] = str[i];
	ft_strdel(&str);
	return (new);
}

char	*ft_set_precision_long_min(t_list *my)
{
	const char	*max = "-9223372036854775808";
	char		*str;
	char		*new;
	int			len;
	int			i;

	if (my->precision_field <= 19)
		return (ft_my_strdup_precision((char *)max, my));
	my->len = my->precision_field + 1;
	new = ft_strnew(my->len);
	i = 20;
	len = my->len;
	while (i-- > 1)
		new[--len] = max[i];
	while (len-- > 1)
		new[len] = '0';
	new[0] = '-';
	ft_strdel(&str);
	return (new);
}

char	*ft_join_char(char *str_full, int len, char c)
{
	char	*new;

	new = ft_strnew(len + 1);
	new[len] = c;
	while (--len >= 0)
		new[len] = str_full[len];
	ft_strdel(&str_full);
	return (new);
}

char	*ft_itoa_base_u(char *str_base, int *len,
unsigned long n, int base)
{
	char			*str;
	int				i;

	*len = ft_numcount_base_unsign(n, base);
	str = ft_my_strnew(*len);
	i = *len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	return (str);
}

char	*ft_str_rev(char *str, t_list *my)
{
	char	*new;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	my->len = ft_strlen(str);
	if (my->precision_field != -1)
		if (my->len > my->precision_field)
			my->len = my->precision_field;
	new = ft_my_strnew(my->len);
	i = -1;
	j = my->len;
	while (++i < my->len)
		new[i] = str[--j];
	return (new);
}
