/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:49:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/03 10:49:04 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_round_float_2(char *str, t_list *my)
{
	int		len;
	char	*new;

	len = my->len;
	new = ft_strnew(++my->len);
	while (len--)
		new[len + 1] = str[len];
	new[0] = '1';
	ft_strdel(&str);
	return (new);
}

char	*ft_round_float(char *str, t_list *my)
{
	int		len;
	int		fl;

	if (my->len == 0)
		return (str);
	len = my->len;
	fl = 1;
	while (len-- && fl)
	{
		if (str[len] == '.')
			continue ;
		++str[len];
		if (str[len] == '9' + 1)
			str[len] = '0';
		else
			fl = 0;
	}
	if (fl)
		return (ft_round_float_2(str, my));
	return (str);
}
