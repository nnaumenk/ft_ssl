/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:47:59 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:48:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specificator(char **form, t_list *my)
{
	++(*form);
	while (my->type_field == 0 && **form)
		ft_search_s1(form, my);
	if (my->precision_field < 0)
		my->precision_field = -1;
	if (my->width_field < 0)
	{
		my->flag_minus = '-';
		my->width_field = -my->width_field;
	}
}

char	*ft_chardup(char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}
