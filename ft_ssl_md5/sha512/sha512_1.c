/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 23:15:27 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:08:39 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "sha512.h"

char		*ft_sha512_make_alignment(char *text, size_t *len)
{
	char			*new;
	char			*pointer;
	size_t			old_len;
	size_t			new_len;
	size_t			null_len;

	old_len = *len;
	new_len = ((old_len + 16) / 128) * 128 + 112 + 16;
	new = (char *)malloc(new_len);
	ft_memcpy((void *)new, (void *)text, old_len);
	pointer = new + old_len;
	*pointer++ = 0x80;
	null_len = new_len - old_len - 16 - 1;
	ft_bzero((void *)pointer, null_len);
	pointer += null_len;
	ft_sha512_add_len(pointer, old_len);
	*len = new_len;
	return (new);
}

void		ft_sha512_add_len(char *text, size_t len)
{
	int		low_bits[8];
	int		high_bits[8];
	int		bits;

	len *= 8;
	bits = 8;
	while (bits--)
	{
		low_bits[bits] = len % 256;
		len /= 256;
	}
	bits = 8;
	while (bits--)
	{
		high_bits[bits] = len % 256;
		len /= 256;
	}
	bits = -1;
	while (++bits < 8)
		*text++ = high_bits[bits];
	bits = -1;
	while (++bits < 8)
		*text++ = low_bits[bits];
}

void		ft_sha512_start_values(uint64_t *hash)
{
	hash[0] = 0x6a09e667f3bcc908;
	hash[1] = 0xbb67ae8584caa73b;
	hash[2] = 0x3c6ef372fe94f82b;
	hash[3] = 0xa54ff53a5f1d36f1;
	hash[4] = 0x510e527fade682d1;
	hash[5] = 0x9b05688c2b3e6c1f;
	hash[6] = 0x1f83d9abfb41bd6b;
	hash[7] = 0x5be0cd19137e2179;
}
