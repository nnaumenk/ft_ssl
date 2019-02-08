/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:05:38 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 19:40:44 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "md5.h"

void		ft_md5_add_len(char *text, size_t len)
{
	int		low_bits[4];
	int		high_bits[4];
	int		bits;

	len *= 8;
	bits = 4;
	while (bits--)
	{
		low_bits[bits] = len % 256;
		len /= 256;
	}
	bits = 4;
	while (bits--)
	{
		high_bits[bits] = len % 256;
		len /= 256;
	}
	bits = 4;
	while (bits--)
		*text++ = low_bits[bits];
	bits = 4;
	while (bits--)
		*text++ = high_bits[bits];
}

char		*ft_md5_make_alignment(char *text, size_t *len)
{
	char			*new;
	char			*pointer;
	size_t			old_len;
	size_t			new_len;
	size_t			null_len;

	old_len = *len;
	new_len = ((old_len + 8) / 64) * 64 + 56 + 8;
	new = (char *)malloc(new_len);
	ft_memcpy((void *)new, (void *)text, old_len);
	pointer = new + old_len;
	*pointer++ = 0x80;
	null_len = new_len - old_len - 8 - 1;
	ft_bzero((void *)pointer, null_len);
	pointer += null_len;
	ft_md5_add_len(pointer, old_len);
	*len = new_len;
	return (new);
}

void		ft_md5_start_values(uint32_t *hash)
{
	hash[0] = 0x67452301;
	hash[1] = 0xEFCDAB89;
	hash[2] = 0x98BADCFE;
	hash[3] = 0x10325476;
}
