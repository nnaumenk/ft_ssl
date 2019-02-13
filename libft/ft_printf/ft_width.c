/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:52:18 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/25 09:52:21 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_zero(char *str, t_list *my)
{
	char	*new;
	int		len;
	int		i;

	len = my->width_field;
	new = ft_my_strnew(len);
	i = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == '0' || str[0] == ' ')
	{
		new[++i] = str[0];
		if (str[1] == 'x' || str[2] == 'X')
			new[++i] = str[1];
	}
	while (my->len-- > i)
		new[--len] = str[my->len];
	while (len--)
		new[len] = '0';
	while (i--)
		new[i] = str[i];
	ft_strdel(&str);
	return (new);
}

char	*ft_width_space(char *str, t_list *my)
{
	char	*new;
	int		len;

	len = my->width_field;
	new = ft_my_strnew(len);
	while (my->len--)
		new[--len] = str[my->len];
	while (len--)
		new[len] = ' ';
	ft_strdel(&str);
	return (new);
}

char	*ft_width_minus_space(char *str, t_list *my)
{
	char	*new;
	int		i;

	new = ft_my_strnew(my->width_field);
	i = -1;
	while (++i < my->len)
		new[i] = str[i];
	i = my->len - 1;
	while (++i < my->width_field)
		new[i] = ' ';
	ft_strdel(&str);
	return (new);
}

char	*ft_field_width_main(char *str, t_list *my)
{
	char *new;

	if (my->precision_field != -1)
	{
		if (my->type_field == 'd' || my->type_field == 'i'
		|| my->type_field == 'o' || my->type_field == 'x'
		|| my->type_field == 'u' || my->type_field == 'U')
			my->flag_zero = -1;
	}
	if (my->flag_minus == '-')
		new = ft_width_minus_space(str, my);
	else
	{
		if (my->flag_zero == '0')
			new = ft_width_zero(str, my);
		else
			new = ft_width_space(str, my);
	}
	my->len = my->width_field;
	return (new);
}
