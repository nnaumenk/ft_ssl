/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:04:00 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/03 13:04:02 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_atoa_add_prefix(char *str, t_list *my, int sign)
{
	char	*new;
	int		i;
	int		j;

	my->len += 2 + sign;
	new = ft_strnew(my->len);
	i = -1;
	if (sign)
		new[++i] = '-';
	new[++i] = '0';
	new[++i] = my->type_field + 23;
	j = -1;
	while (++i < my->len)
		new[i] = str[++j];
	ft_strdel(&str);
	return (new);
}

int		ft_atoa_help(long double *n, t_list *my)
{
	int symbol;

	if (*n == 0.0)
		my->buf = 0;
	else if (my->flag_float == 'L')
		my->buf = ft_atoa_pow(n, 16.0);
	else
		my->buf = ft_atoa_pow(n, 2.0);
	symbol = (int)*n;
	*n -= symbol;
	return (symbol);
}
