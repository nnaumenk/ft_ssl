/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:33:10 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:33:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_next(t_list *my)
{
	if (my->argptr_counter == -1)
		return ;
	va_copy(my->ptr, my->argptr_offset);
	while (--my->argptr_counter > 0)
		va_arg(my->ptr, int);
}

char	*ft_expr_to_str2(t_list *my)
{
	if (my->type_field == 's' && my->len_field != 2)
		return (ft_my_strdup_precision(va_arg(my->ptr, char*), my));
	if (my->type_field == 'a' || my->type_field == 'A')
		return (ft_atoa(ft_mod_float(my), my));
	if (my->type_field == 'g' || my->type_field == 'G')
		return (ft_gtoa(ft_mod_float(my), my));
	if (my->type_field == 'e' || my->type_field == 'E')
		return (ft_etoa(ft_mod_float(my), my));
	if (my->type_field == 'f' || my->type_field == 'F')
		return (ft_ftoa(ft_mod_float(my), my));
	if (my->type_field == 'r')
		return (ft_notprintable(va_arg(my->ptr, char*), my));
	if (my->type_field == 'v')
		return (ft_str_rev(va_arg(my->ptr, char*), my));
	if (my->type_field == 'k')
		return (ft_date_iso(my));
	if (my->type_field == 'C' || (my->type_field == 'c' && my->len_field == 2))
		return (ft_wchardup(va_arg(my->ptr, wchar_t), my));
	if (my->type_field == 'S' || my->type_field == 's')
		return (ft_wstrdup(va_arg(my->ptr, wchar_t*), my));
	my->len = 1;
	if (my->type_field == 'c')
		return (ft_chardup(va_arg(my->ptr, int)));
	return (ft_chardup(my->type_field));
}

char	*ft_expr_to_str(t_list *my, char *b1, char *b2)
{
	ft_va_next(my);
	if (my->type_field == 'b')
		return (ft_itoa_base_unint(b1, my, ft_mod_unint(my), 2));
	if (my->type_field == 'd' || my->type_field == 'i')
		return (ft_itoa_base_int(b1, my, ft_mod_int(my), 10));
	if (my->type_field == 'D')
		return (ft_itoa_base_int(b1, my, va_arg(my->ptr, long), 10));
	if (my->type_field == 'x')
		return (ft_itoa_base_unint_x(b2, my, ft_mod_unint(my), 16));
	if (my->type_field == 'X')
		return (ft_itoa_base_unint_x(b1, my, ft_mod_unint(my), 16));
	if (my->type_field == 'p')
		return (ft_itoa_pointer(b2, my, va_arg(my->ptr, unsigned long), 16));
	if (my->type_field == 'o')
		return (ft_itoa_base_unint_o(b1, my, ft_mod_unint(my), 8));
	if (my->type_field == 'O')
		return (ft_itoa_base_unint_o(b1, my, va_arg(my->ptr, long), 8));
	if (my->type_field == 'u')
		return (ft_itoa_base_unint(b1, my, ft_mod_unint(my), 10));
	if (my->type_field == 'U')
		return (ft_itoa_base_unint(b1, my, va_arg(my->ptr, long), 10));
	if (my->type_field == 'T')
		return (ft_pow_two(va_arg(my->ptr, int), my));
	return (ft_expr_to_str2(my));
}

void	ft_expr_out(t_list *my)
{
	char *str;

	if (my->type_field == 0)
		return ;
	if (my->type_field == 'n')
	{
		ft_set_counter(my);
		return ;
	}
	str = ft_expr_to_str(my, "0123456789ABCDEF", "0123456789abcdef");
	if (my->unicode_check)
	{
		ft_my_strcat(my, str, my->len);
		return ;
	}
	if (my->flag_comma == '\'' && MB_CUR_MAX != 1)
		str = ft_flag_comma(str, my);
	if (my->flag_plus == '+')
		str = ft_flag_plus(str, my);
	else if (my->flag_space == ' ')
		str = ft_flag_space(str, my);
	if (my->width_field > my->len)
		str = ft_field_width_main(str, my);
	ft_my_strcat(my, str, my->len);
}

int		ft_printf(const char *format, ...)
{
	char		*form;
	t_list		my;

	va_start(my.ptr, format);
	va_copy(my.argptr_offset, my.ptr);
	my.len_block = 0;
	my.len_full = 0;
	form = (char*)format;
	while (1)
	{
		ft_reset_flags(&my);
		ft_expand(&form, &my);
		if (*form == '\0')
			break ;
		ft_specificator(&form, &my);
		ft_expr_out(&my);
	}
	ft_attribute_search(&my);
	write(1, my.str_full, my.len_block);
	va_end(my.ptr);
	if (my.unicode_check)
		return (-1);
	return (my.len_full);
}
