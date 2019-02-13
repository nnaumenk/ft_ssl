/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gtoa_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:10:51 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/04 18:10:53 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_gtoa_precision_3(char *str, t_list *my)
{
	char	*new;
	int		i;
	int		len;

	i = -1;
	while (str[++i])
		if (!(str[i] == '.' || str[i] == '0'))
			break ;
	len = i + my->precision_field;
	new = ft_strnew(len);
	i = -1;
	while (++i < len)
	{
		if (str[i] == '\0')
			break ;
		new[i] = str[i];
	}
	my->len = i;
	if (str[i] >= '5')
		new = ft_round_float(new, my);
	if (!my->flag_hash)
		new = ft_cut_after(new, &my->len);
	return (new);
}

char		*ft_gtoa_precision_2(char *str, t_list *my, int bef, int aft)
{
	char	*new;
	int		i;

	new = ft_strnew(my->precision_field + 1);
	i = -1;
	while (++i < bef)
		new[i] = str[i];
	--i;
	if (str[i + 1] == '.' && i + 1 != my->precision_field)
	{
		while (++i < my->precision_field + 1 && aft--)
			new[i] = str[i];
		--i;
	}
	else if (my->dot)
		new[++i] = '.';
	my->len = i + 1;
	if (str[i + 1] >= '5')
		new = ft_round_float(new, my);
	while (++i < my->precision_field + my->dot)
		new[i] = '0';
	my->len = i;
	if (!my->flag_hash)
		new = ft_cut_after(new, &my->len);
	return (new);
}

char		*ft_gtoa_precision_exponent(char *str, t_list *my)
{
	char	*new;
	int		before_dot;
	int		i;

	before_dot = ft_char_index(str, '.');
	if (my->precision_field == 1)
		my->dot = 0;
	else
		my->dot = 1;
	my->len = my->precision_field + my->dot;
	new = ft_strnew(my->len);
	new[0] = str[0];
	i = 0;
	if (my->dot)
		new[++i] = '.';
	while (++i < my->len)
		new[i] = str[i - 1];
	if (str[i - 1] >= '5')
		new = ft_round_float(new, my);
	new = ft_cut_after(new, &my->len);
	new = ft_float_add_exponent(new, my, before_dot - 1, my->type_field - 2);
	return (new);
}

char		*ft_gtoa_precision_exponent_2(char *str, t_list *my, int first_num)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	len = my->precision_field + my->dot;
	new = ft_strnew(len);
	i = first_num;
	if (i == -1)
		i = 0;
	j = 0;
	new[j++] = str[i];
	if (my->dot || my->precision_field > 1)
		new[j++] = '.';
	while (++i < my->len && j < len)
		new[j++] = str[i];
	--j;
	while (++j < len)
		new[j] = '0';
	my->len = j;
	if (str[i] >= '5')
		new = ft_round_float(new, my);
	new = ft_float_add_exponent(new, my, -first_num + 1, my->type_field - 2);
	return (new);
}

char		*ft_gtoa_precision(char *str, t_list *my)
{
	char	*new;
	int		before_dot;
	int		after_dot;
	int		no_char;

	no_char = ft_nochar_index(str, '.', '0');
	before_dot = ft_char_index(str, '.');
	after_dot = my->len - before_dot;
	if (my->precision_field)
		my->dot = 1;
	if (my->precision_field == 0)
		my->precision_field = 1;
	if (no_char >= 6)
		new = ft_gtoa_precision_exponent_2(str, my, no_char);
	else if (before_dot > my->precision_field)
		new = ft_gtoa_precision_exponent(str, my);
	else if (str[0] != '0')
		new = ft_gtoa_precision_2(str, my, before_dot, after_dot);
	else
		new = ft_gtoa_precision_3(str, my);
	ft_strdel(&str);
	return (new);
}
