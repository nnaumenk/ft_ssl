/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:51:27 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/08 15:27:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUF_SIZE 4096

static void	ft_itoa_uns(char *str, size_t *len, size_t value, size_t base)
{
	const char	*str_base = "0123456789abcdef";
	size_t		value_len;
	size_t		len_buf;
	size_t		value_buf;

	value_buf = value;
	value_len = 1;
	while (value_buf > base - 1)
	{
		value_buf /= base;
		value_len++;
	}
	*len += value_len;
	len_buf = *len;
	while (value_len--)
	{
		str[--len_buf] = str_base[value % base];
		value /= base;
	}
}

static void	ft_itoa(char *str, size_t *len, ptrdiff_t value, int base)
{
	const char	*str_base = "0123456789abcdef";
	size_t		value_len;
	size_t		len_buf;
	ptrdiff_t	value_buf;

	if (value < 0)
	{
		value = -value;
		str[(*len)++] = '-';
	}
	value_buf = value;
	value_len = 1;
	while (value_buf > base - 1)
	{
		value_buf /= base;
		value_len++;
	}
	*len += value_len;
	len_buf = *len;
	while (value_len--)
	{
		str[--len_buf] = str_base[value % base];
		value /= base;
	}
}

static void	ft_other_sp(char percent, va_list ap, char **buf, size_t *full_len)
{
	size_t	len;

	len = 0;
	if (percent == 'd')
		ft_itoa(*buf, &len, va_arg(ap, int), 10);
	else if (percent == 'D')
		ft_itoa(*buf, &len, va_arg(ap, ptrdiff_t), 10);
	else if (percent == 'u')
		ft_itoa_uns(*buf, &len, va_arg(ap, unsigned), 10);
	else if (percent == 'U')
		ft_itoa_uns(*buf, &len, va_arg(ap, size_t), 10);
	else if (percent == 'x')
		ft_itoa_uns(*buf, &len, va_arg(ap, unsigned), 16);
	else if (percent == 'X')
		ft_itoa_uns(*buf, &len, va_arg(ap, size_t), 16);
	*full_len += len;
	*buf += len;
}

static void	ft_percent(char *format, va_list ap, char *buf, size_t *full_len)
{
	size_t	len;
	char	*percent;
	char	*str;

	while ((percent = ft_strchr(format, '%')))
	{
		len = percent - format;
		ft_memcpy(buf, format, len);
		*full_len += len;
		buf += len;
		if (*(++percent) == 's')
		{
			str = va_arg(ap, char *);
			len = ft_strlen(str);
			ft_memcpy(buf, str, len);
			*full_len += len;
			buf += len;
		}
		else
			ft_other_sp(*percent, ap, &buf, full_len);
		format = percent + 1;
	}
	len = ft_strlen(format);
	ft_memcpy(buf, format, len);
	*full_len += len;
}

int			ft_print(const char *format, ...)
{
	va_list	argptr;
	char	buf[BUF_SIZE];
	size_t	len;

	va_start(argptr, format);
	len = 0;
	ft_percent((char *)format, argptr, buf, &len);
	write(1, buf, len);
	va_end(argptr);
	return (len);
}
