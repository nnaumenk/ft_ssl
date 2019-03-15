/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:45:07 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:23:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "base64.h"

void	ft_b64_from_base(char *buf, size_t len)
{
	size_t		i;

	i = -1;
	while (++i < len)
	{
		if (buf[i] == '\n')
			buf[i] = 65;
		else if (buf[i] == '=')
			buf[i] = 64;
		else if (buf[i] == '/')
			buf[i] = 63;
		else if (buf[i] == '+')
			buf[i] = 62;
		else if (buf[i] >= '0' && buf[i] <= '9')
			buf[i] = buf[i] - '0' + 52;
		else if (buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] = buf[i] - 'a' + 26;
		else if (buf[i] >= 'A' && buf[i] <= 'Z')
			buf[i] = buf[i] - 'A';
	}
}

void	ft_b64_decode_line(char *str, char *line, size_t *len, size_t blocks)
{
	size_t		j;

	j = 0;
	while (blocks--)
	{
		str[j] = *line++ << 2;
		str[j++] += (*line >> 4) & 0x03;
		str[j] = *line++ << 4;
		if (*line == 64)
			break ;
		str[j++] += (*line >> 2) & 0x0f;
		str[j] = *line++ << 6;
		if (*line == 64)
			break ;
		str[j++] += *line++ & 0x3f;
	}
	*len += j;
}

void	*ft_memchr(void *mem, char elem, size_t num)
{
	unsigned char *str;

	str = mem;
	while (num--)
		if (*str++ == elem)
			return ((void *)(str - 1));
	return (NULL);
}

char	*ft_b64_decode_algor(char *buf, size_t *len)
{
	size_t		buf_len;
	size_t		line_len;
	char		*new_str;
	char		*pointer;
	char		*line_pointer;

	buf_len = *len;
	new_str = ft_strnew(*len / 4 * 3);
	pointer = new_str;
	*len = 0;
	while ((line_pointer = ft_memchr(buf, 65, buf_len)))
	{
		line_len = line_pointer - buf;
		if (line_len % 4)
			return (new_str);
		ft_b64_decode_line(pointer, buf, len, line_len / 4);
		pointer = new_str + *len;
		buf = line_pointer + 1;
		buf_len = buf_len - line_len - 1;
	}
	return (new_str);
}

char	*ft_b64_decode(char *buf, size_t *len)
{
	char		*new_str;

	ft_b64_from_base(buf, *len);
	new_str = ft_b64_decode_algor(buf, len);
	ft_strdel(&buf);
	return (new_str);
}
