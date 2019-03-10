/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:10:46 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 23:36:50 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_ascii_to_hex(char *hex, char *str, size_t len)
{
	char const		*base = "0123456789abcdef";
	char			*pointer;
	unsigned char	byte;

	pointer = hex;
	while (len--)
	{
		byte = (unsigned char)*str++;
		pointer[1] = base[byte % 16];
		byte /= 16;
		pointer[0] = base[byte % 16];
		pointer += 2;
	}
}

int		ft_hex_to_dec(uint8_t hex)
{
	int			dec;

	if (IS_NUMBER(hex))
		dec = (hex - '0');
	else if (IS_UP_HEX(hex))
		dec = (hex - 'A' + 10);
	else if (IS_DOWN_HEX(hex))
		dec = (hex - 'a' + 10);
	else
	{
		ft_print_fd(2, "no-hex digit\n");
		return (-1);
	}
	return (dec);
}

int		ft_hex_to_ascii(uint8_t *bytes, char *hex, size_t len)
{
	size_t	i;
	int		dec;

	i = -1;
	while (++i < len)
	{
		*bytes = 0;
		if (*hex == 0)
			break ;
		dec = ft_hex_to_dec(*hex++);
		if (dec == -1)
			return (1);
		*bytes = 16 * dec;
		if (*hex == 0)
			break ;
		dec = ft_hex_to_dec(*hex++);
		if (dec == -1)
			return (1);
		*bytes++ += dec;
	}
	while (++i < len)
		*++bytes = 0;
	return (0);
}
