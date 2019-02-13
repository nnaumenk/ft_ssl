/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:45:11 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:45:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_join_free(char *s1, char *s2, int len1, int len2)
{
	char	*str;
	int		len;

	len = len1 + len2;
	str = ft_strnew(len);
	while (len2--)
		str[--len] = s2[len2];
	while (len1--)
		str[--len] = s1[len1];
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}

char	*ft_str_join_char_free(char *s1, int len, char c)
{
	char	*str;

	str = ft_strnew(len + 1);
	str[len] = c;
	while (len--)
		str[len] = s1[len];
	ft_strdel(&s1);
	return (str);
}

void	ft_my_strcat(t_list *my, char *s1, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (my->len_block == BUFF_SIZE)
		{
			write(1, my->str_full, BUFF_SIZE);
			my->len_block = 0;
		}
		my->str_full[my->len_block] = s1[i];
		my->len_block++;
		my->len_full++;
	}
	ft_strdel(&s1);
}

void	ft_expand(char **form, t_list *my)
{
	int		i;

	i = -1;
	while ((*form)[++i])
	{
		if ((*form)[i] == '%')
			break ;
		if (my->len_block == BUFF_SIZE)
		{
			write(1, &(my->str_full), BUFF_SIZE);
			my->len_block = 0;
		}
		my->str_full[my->len_block] = (*form)[i];
		my->len_block++;
		my->len_full++;
	}
	*form += i;
}
