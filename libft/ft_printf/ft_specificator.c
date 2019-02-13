/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:05:24 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/23 19:05:36 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search_s4(char **form, t_list *my)
{
	if (**form == '*')
	{
		++(*form);
		if (**form >= '0' && **form <= '9')
		{
			my->buf = ft_atoi(form);
			if (**form == '$')
			{
				my->width_field = ft_flag_dolar(*my);
				++(*form);
			}
			else
			{
				my->width_field = my->buf;
				va_arg(my->ptr, int);
			}
		}
		else
			my->width_field = va_arg(my->ptr, int);
	}
	else
		my->type_field = *(*form)++;
}

void	ft_search_s3(char **form, t_list *my)
{
	if (**form == 'L')
		my->flag_float = *(*form)++;
	else if (**form == 'z' || **form == 't' || **form == 'l' || **form == 'j')
	{
		if (my->len_field < 2)
			my->len_field = 2;
		++(*form);
	}
	else if (**form == 'h' && *(*form + 1) == 'h')
	{
		if (my->len_field < 0)
			my->len_field = 0;
		*form += 2;
	}
	else if (**form == 'h')
	{
		if (my->len_field < 1)
			my->len_field = 1;
		++(*form);
	}
	else if (**form == '\'')
		my->flag_comma = *(*form)++;
	else
		ft_search_s4(form, my);
}

void	ft_search_s2_help(char **form, t_list *my)
{
	my->buf = ft_atoi(form);
	if (**form == '$')
	{
		my->precision_field = ft_flag_dolar(*my);
		++(*form);
	}
	else
	{
		my->width_field = my->buf;
		my->precision_field = va_arg(my->ptr, int);
	}
}

void	ft_search_s2(char **form, t_list *my)
{
	if (**form == '.')
	{
		my->precision_field = 0;
		++(*form);
		if (**form == '*')
		{
			++(*form);
			if (**form >= '0' && **form <= '9')
				ft_search_s2_help(form, my);
			else
				my->precision_field = va_arg(my->ptr, int);
		}
		else if (**form >= '0' && **form <= '9')
			my->precision_field = ft_atoi(form);
	}
	else
		ft_search_s3(form, my);
}

void	ft_search_s1(char **form, t_list *my)
{
	if (**form == '-')
		my->flag_minus = *(*form)++;
	else if (**form == '+')
		my->flag_plus = *(*form)++;
	else if (**form == ' ')
		my->flag_space = *(*form)++;
	else if (**form == '#')
		my->flag_hash = *(*form)++;
	else if (**form == '0')
		my->flag_zero = *(*form)++;
	else if (**form >= '0' && **form <= '9')
	{
		my->buf = ft_atoi(form);
		if (**form == '$')
		{
			my->argptr_counter = my->buf;
			++(*form);
		}
		else
			my->width_field = my->buf;
		my->buf = 0;
	}
	else
		ft_search_s2(form, my);
}
