/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:55:00 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/03 10:55:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float_infinite_zero(char *str, t_list *my)
{
	my->s = "0000000000000000000000000000000000000000000000000000000001000000";
	if (ft_strequ(str, my->s))
		return (ft_my_strdup("0.0", my));
	my->s = "0000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strequ(str, my->s))
		return (ft_my_strdup("0", my));
	my->s = "1000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strequ(str, my->s))
		return (ft_my_strdup("0", my));
	return (str);
}

char	*ft_float_check(char *str, t_list *my)
{
	my->s = "1111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strequ(str, my->s))
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("-inf", my));
		return (ft_my_strdup("-INF", my));
	}
	my->s = "0111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strequ(str, my->s))
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("inf", my));
		return (ft_my_strdup("INF", my));
	}
	my->s = "0111111111111000000000000000000000000000000000000000000000000000";
	if (ft_strequ(str, my->s))
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("nan", my));
		return (ft_my_strdup("NAN", my));
	}
	return (str);
}
