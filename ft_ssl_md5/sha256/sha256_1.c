/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:54:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:32:58 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "sha256.h"

void	ft_sha256_add_len(char *text, size_t len)
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
	bits = -1;
	while (++bits < 4)
		*text++ = high_bits[bits];
	bits = -1;
	while (++bits < 4)
		*text++ = low_bits[bits];
}

char	*ft_sha256_make_alignment(char *text, size_t *len)
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
	ft_sha256_add_len(pointer, old_len);
	*len = new_len;
	return (new);
}
