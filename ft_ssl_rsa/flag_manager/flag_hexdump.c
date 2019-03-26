/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hexdump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/26 18:59:38 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_set_number(char *new, size_t *i)
{
	const	char	*base = "0123456789abcdef";
	static	size_t	number;

	new[(*i)++] = base[(number / 4096) % 16];
	new[(*i)++] = base[(number / 256) % 16];
	new[(*i)++] = base[(number / 16) % 16];
	new[(*i)++] = base[(number / 1) % 16];
	new[(*i)++] = ' ';
	new[(*i)++] = '-';
	new[(*i)++] = ' ';
	number += 16;
}

static void	ft_set_values(char *new, size_t *i, char *text, size_t len)
{
	const	char	*base = "0123456789abcdef";
	size_t			column_count;
	int				flag;

	flag = 0;
	column_count = 16;
	while (column_count--)
	{
		if (len-- == 0)
			flag = 1;
		if (flag == 0)
		{
			new[(*i)++] = base[((unsigned char)*text / 16) % 16];
			new[(*i)++] = base[((unsigned char)*text / 1) % 16];
			((column_count == 8) ? (new[(*i)++] = '-') : (new[(*i)++] = ' '));
			text++;
		}
		else
		{
			new[(*i)++] = ' ';
			new[(*i)++] = ' ';
			new[(*i)++] = ' ';
		}
	}
}

static void	ft_set_text(char *new, size_t *i, char *text, size_t len)
{
	size_t	value_count;
	int		flag;

	new[(*i)++] = ' ';
	new[(*i)++] = ' ';
	flag = 0;
	value_count = 16;
	while (value_count--)
	{
		if (len-- == 0)
			flag = 1;
		if (flag == 0)
		{
			if (*text >= 32 && *text <= 127)
				new[(*i)++] = *text;
			else
				new[(*i)++] = '.';
			text++;
		}
		else
			new[(*i)++] = ' ';
	}
	new[(*i)++] = '\n';
}

int			ft_rsa_make_flag_hexdump(t_rsa *rsa)
{
	size_t	row_count;
	char	*new;
	char	*ptr;
	size_t	i;

	if (rsa->flag.hexdump == 0)
		return (0);
	new = (char *)malloc(((rsa->len + 15) / 16) * 74);
	ptr = rsa->text;
	i = 0;
	row_count = (rsa->len + 15) / 16;
	while (row_count--)
	{
		ft_set_number(new, &i);
		ft_set_values(new, &i, rsa->text, rsa->len);
		ft_set_text(new, &i, rsa->text, rsa->len);
		rsa->len -= 16;
		rsa->text += 16;
	}
	ft_strdel(&ptr);
	rsa->text = new;
	rsa->len = i;
	return (0);
}

int			ft_rsa_check_flag_hexdump(
			int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->hexdump = 1;
	return (0);
}
