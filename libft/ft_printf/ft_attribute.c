/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:11:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/12 15:11:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_attr_check_2(char *str_attr)
{
	if (ft_strequ(str_attr, "white"))
		return (37);
	if (ft_strequ(str_attr, "black_b"))
		return (40);
	if (ft_strequ(str_attr, "red_b"))
		return (41);
	if (ft_strequ(str_attr, "green_b"))
		return (42);
	if (ft_strequ(str_attr, "yellow_b"))
		return (43);
	if (ft_strequ(str_attr, "blue_b"))
		return (44);
	if (ft_strequ(str_attr, "magenta_b"))
		return (45);
	if (ft_strequ(str_attr, "cyan_b"))
		return (46);
	if (ft_strequ(str_attr, "white_b"))
		return (47);
	return (-1);
}

int		ft_str_attr_check(char *str_attr)
{
	if (ft_strequ(str_attr, "eoc"))
		return (0);
	if (ft_strequ(str_attr, "bold"))
		return (1);
	if (ft_strequ(str_attr, "transparent"))
		return (2);
	if (ft_strequ(str_attr, "italic"))
		return (3);
	if (ft_strequ(str_attr, "underline"))
		return (4);
	if (ft_strequ(str_attr, "black"))
		return (30);
	if (ft_strequ(str_attr, "red"))
		return (31);
	if (ft_strequ(str_attr, "green"))
		return (32);
	if (ft_strequ(str_attr, "yellow"))
		return (33);
	if (ft_strequ(str_attr, "blue"))
		return (34);
	if (ft_strequ(str_attr, "magenta"))
		return (35);
	if (ft_strequ(str_attr, "cyan"))
		return (36);
	return (ft_str_attr_check_2(str_attr));
}

void	ft_add_attribute(t_list *my, int i, int attr_len)
{
	char	*str_attr;
	int		len;
	int		start;
	int		attrib;

	str_attr = ft_strnew(attr_len);
	len = -1;
	while (++len < attr_len)
		str_attr[len] = my->str_full[i - attr_len + len];
	attrib = ft_str_attr_check(str_attr);
	ft_strdel(&str_attr);
	if (attrib == -1)
		return ;
	start = i - attr_len - 1;
	my->str_full[start] = '\x1b';
	my->str_full[start + 1] = '[';
	my->str_full[start + 2] = attrib / 10 + '0';
	my->str_full[start + 3] = attrib % 10 + '0';
	my->str_full[start + 4] = 'm';
	start += 4;
	while (i < my->len_block)
		my->str_full[++start] = my->str_full[++i];
	my->len_block = start;
}

void	ft_attribute_search(t_list *my)
{
	int		i;
	int		attr_len;

	i = -1;
	attr_len = 0;
	while (++i < my->len_block)
	{
		if (my->str_full[i] == '{')
		{
			while (++i < my->len_block)
			{
				if (my->str_full[i] == '}')
				{
					if (attr_len >= 3)
					{
						ft_add_attribute(my, i, attr_len);
						i -= attr_len;
					}
					attr_len = 0;
					break ;
				}
				++attr_len;
			}
		}
	}
}
