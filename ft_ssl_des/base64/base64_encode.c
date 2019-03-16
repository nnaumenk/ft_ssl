/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:45:00 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/16 23:40:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "base64.h"

void	ft_b64_to_base(char *str, size_t len)
{
	const char	*base = BASE;
	size_t		i;

	i = -1;
	while (++i < len)
		str[i] = base[(unsigned char)str[i]];
}

char	*ft_b64_encode_append(char *new_str, size_t j, size_t new_len)
{
	if (new_len == 0)
		return (new_str);
	while (++j < new_len - 1)
		new_str[j] = 64;
	new_str[j] = 65;
	return (new_str);
}

char	*ft_b64_encode_algor(unsigned char *buf, size_t len, size_t new_len)
{
	char		*new_str;
	size_t		counter;
	size_t		i;
	size_t		j;

	new_str = ft_malloc_str(new_len);
	i = -1;
	j = -1;
	counter = -1;
	while (++i < len)
	{
		if (++counter % 16 == 0 && i)
			new_str[++j] = 65;
		new_str[++j] = buf[i] >> 2;
		new_str[++j] = (buf[i] & 0x03) << 4;
		if (++i == len)
			break ;
		new_str[j] += buf[i] >> 4;
		new_str[++j] = (buf[i] & 0x0f) << 2;
		if (++i == len)
			break ;
		new_str[j] += (buf[i] >> 6);
		new_str[++j] = buf[i] & 0x3f;
	}
	return (ft_b64_encode_append(new_str, j, new_len));
}

char	*ft_b64_encode(char *buf, size_t *len)
{
	size_t		new_len;
	char		*new_str;

	new_len = (((*len + 2) / 3) * 4);
	new_len = new_len + (new_len + 63) / 64;
	new_str = ft_b64_encode_algor((unsigned char *)buf, *len, new_len);
	ft_b64_to_base(new_str, new_len);
	*len = new_len;
	ft_strdel(&buf);
	return (new_str);
}
