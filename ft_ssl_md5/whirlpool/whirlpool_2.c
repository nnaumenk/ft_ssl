/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:20:49 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 18:32:24 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "whirlpool.h"

uint8_t g_wp_s_box[256] =
{
	0x18, 0x23, 0xC6, 0xE8, 0x87, 0xB8, 0x01, 0x4F,
	0x36, 0xA6, 0xD2, 0xF5, 0x79, 0x6F, 0x91, 0x52,
	0x60, 0xBC, 0x9B, 0x8E, 0xA3, 0x0C, 0x7B, 0x35,
	0x1D, 0xE0, 0xD7, 0xC2, 0x2E, 0x4B, 0xFE, 0x57,
	0x15, 0x77, 0x37, 0xE5, 0x9F, 0xF0, 0x4A, 0xDA,
	0x58, 0xC9, 0x29, 0x0A, 0xB1, 0xA0, 0x6B, 0x85,
	0xBD, 0x5D, 0x10, 0xF4, 0xCB, 0x3E, 0x05, 0x67,
	0xE4, 0x27, 0x41, 0x8B, 0xA7, 0x7D, 0x95, 0xD8,
	0xFB, 0xEE, 0x7C, 0x66, 0xDD, 0x17, 0x47, 0x9E,
	0xCA, 0x2D, 0xBF, 0x07, 0xAD, 0x5A, 0x83, 0x33,
	0x63, 0x02, 0xAA, 0x71, 0xC8, 0x19, 0x49, 0xD9,
	0xF2, 0xE3, 0x5B, 0x88, 0x9A, 0x26, 0x32, 0xB0,
	0xE9, 0x0F, 0xD5, 0x80, 0xBE, 0xCD, 0x34, 0x48,
	0xFF, 0x7A, 0x90, 0x5F, 0x20, 0x68, 0x1A, 0xAE,
	0xB4, 0x54, 0x93, 0x22, 0x64, 0xF1, 0x73, 0x12,
	0x40, 0x08, 0xC3, 0xEC, 0xDB, 0xA1, 0x8D, 0x3D,
	0x97, 0x00, 0xCF, 0x2B, 0x76, 0x82, 0xD6, 0x1B,
	0xB5, 0xAF, 0x6A, 0x50, 0x45, 0xF3, 0x30, 0xEF,
	0x3F, 0x55, 0xA2, 0xEA, 0x65, 0xBA, 0x2F, 0xC0,
	0xDE, 0x1C, 0xFD, 0x4D, 0x92, 0x75, 0x06, 0x8A,
	0xB2, 0xE6, 0x0E, 0x1F, 0x62, 0xD4, 0xA8, 0x96,
	0xF9, 0xC5, 0x25, 0x59, 0x84, 0x72, 0x39, 0x4C,
	0x5E, 0x78, 0x38, 0x8C, 0xD1, 0xA5, 0xE2, 0x61,
	0xB3, 0x21, 0x9C, 0x1E, 0x43, 0xC7, 0xFC, 0x04,
	0x51, 0x99, 0x6D, 0x0D, 0xFA, 0xDF, 0x7E, 0x24,
	0x3B, 0xAB, 0xCE, 0x11, 0x8F, 0x4E, 0xB7, 0xEB,
	0x3C, 0x81, 0x94, 0xF7, 0xB9, 0x13, 0x2C, 0xD3,
	0xE7, 0x6E, 0xC4, 0x03, 0x56, 0x44, 0x7F, 0xA9,
	0x2A, 0xBB, 0xC1, 0x53, 0xDC, 0x0B, 0x9D, 0x6C,
	0x31, 0x74, 0xF6, 0x46, 0xAC, 0x89, 0x14, 0xE1,
	0x16, 0x3A, 0x69, 0x09, 0x70, 0xB6, 0xD0, 0xED,
	0xCC, 0x42, 0x98, 0xA4, 0x28, 0x5C, 0xF8, 0x86,
};

void	ft_whirlpool_sub_bytes(uint8_t *matrix)
{
	int		i;

	i = 64;
	while (i--)
		matrix[i] = g_wp_s_box[matrix[i]];
}

void	ft_whirlpool_shift_columns(uint8_t *matrix)
{
	uint8_t		buf[64];
	int			i;
	int			j;
	int			mod;

	ft_memcpy((void *)buf, (void *)matrix, 64);
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
		{
			mod = (i - j) % 8;
			if (mod < 0)
				mod += 8;
			matrix[i * 8 + j] = buf[mod * 8 + j];
		}
	}
}

uint8_t	g_wp_c[64] =
{
	1, 1, 4, 1, 8, 5, 2, 9,
	9, 1, 1, 4, 1, 8, 5, 2,
	2, 9, 1, 1, 4, 1, 8, 5,
	5, 2, 9, 1, 1, 4, 1, 8,
	8, 5, 2, 9, 1, 1, 4, 1,
	1, 8, 5, 2, 9, 1, 1, 4,
	4, 1, 8, 5, 2, 9, 1, 1,
	1, 4, 1, 8, 5, 2, 9, 1,
};

uint8_t	ft_whirlpool_mul(uint8_t a, uint8_t b)
{
	int			counter;
	uint8_t		pointer;
	uint8_t		hi_bit_set;

	pointer = 0;
	counter = -1;
	while (++counter < 8)
	{
		if ((b & 1) == 1)
			pointer ^= a;
		hi_bit_set = (a & 0x80);
		a <<= 1;
		if (hi_bit_set == 0x80)
			a ^= 0x1d;
		b >>= 1;
	}
	return (pointer);
}

void	ft_whirlpool_mix_rows(uint8_t *matrix)
{
	uint8_t		buf[64];
	int			i;
	int			j;
	int			z;
	uint8_t		value;

	ft_memcpy((void *)buf, (void *)matrix, 64);
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
		{
			buf[i * 8 + j] = 0;
			z = -1;
			while (++z < 8)
			{
				value = ft_whirlpool_mul(matrix[i * 8 + z], g_wp_c[z * 8 + j]);
				buf[i * 8 + j] ^= value;
			}
		}
	}
	ft_memcpy((void *)matrix, (void *)buf, 64);
}
