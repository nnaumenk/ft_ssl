/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/27 18:44:55 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ft_ssl.h"

// size_t	ft_pow_mod_int(size_t num, size_t pow, size_t mod)
// {
// 	size_t	res;

// 	if (pow == 0)
// 		return (1);
// 	else if (pow % 2 == 0)
// 	{
// 		res = ft_pow_mod_int(num, pow / 2, mod);
// 		return ((res * res) % mod);
// 	}
// 	return (((num % mod) * ft_pow_mod_i(num, pow - 1, mod)) % mod);
// }
