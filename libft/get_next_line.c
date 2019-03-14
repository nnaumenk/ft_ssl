/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:43 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/10/09 01:07:35 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define GNL_SIZE 4096

static int		ft_line(char **str, size_t *len, char *pointer, char **line)
{
	size_t	line_len;
	char	*new;

	line_len = pointer - *str;
	(*line) = ft_strnew(line_len);
	ft_memcpy(*line, *str, line_len);
	line_len++;
	*len -= line_len;
	new = ft_strnew(*len);
	ft_memcpy(new, *str + line_len, *len);
	ft_strdel(str);
	*str = new;
	return (1);
}

static int		ft_last_line(char **str, size_t *len, char **line)
{
	if (*len)
	{
		(*line) = ft_strnew(*len);
		ft_memcpy(*line, *str, *len);
		*len = 0;
		ft_strdel(str);
		return (1);
	}
	ft_strdel(str);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*str;
	char			*pointer;
	char			buf[GNL_SIZE];
	static size_t	len;
	size_t			buf_len;

	if (fd < 0 || GNL_SIZE <= 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	else if ((pointer = ft_strchr(str, '\n')))
		return (ft_line(&str, &len, pointer, line));
	while ((buf_len = read(fd, buf, GNL_SIZE)))
	{
		str = ft_memjoin_del(str, buf, len, buf_len);
		len += buf_len;
		if ((pointer = ft_strchr(str, '\n')))
			return (ft_line(&str, &len, pointer, line));
	}
	return (ft_last_line(&str, &len, line));
}
