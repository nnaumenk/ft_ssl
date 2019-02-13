/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_decrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/10/11 20:14:40 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_des_make_left_shift(uint8_t *arr, uint8_t len)
{
	uint8_t buf;
	uint8_t i;

	buf = arr[0];
	i = -1;
	while (++i < len - 1)
		arr[i] = arr[i + 1];
	arr[i] = buf;
}

void	ft_des_make_right_shift(uint8_t *arr, uint8_t len)
{
	uint8_t buf;
	uint8_t i;

	buf = arr[len - 1];
	i = len;
	while (--i)
		arr[i] = arr[i - 1];
	arr[i] = buf;
}

void	ft_des_make_key56(uint8_t *key56, uint8_t *key64)
{
	const int	table[56] = {KEY56_TABLE};
	uint8_t		i;

	i = -1;
	while (++i < 56)
		key56[i] = key64[table[i] - 1];
}

void	ft_des_make_key48(uint8_t *key48, uint8_t *key56)
{
	const int	table[48] = {KEY48_TABLE};
	uint8_t		i;

	i = -1;
	while (++i < 48)
		key48[i] = key56[table[i] - 1];
}
