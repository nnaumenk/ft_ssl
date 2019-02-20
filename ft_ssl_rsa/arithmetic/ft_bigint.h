/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:12:53 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:28:35 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#ifndef FT_BIGINT_H
# define FT_BIGINT_H

void	ft_bigint_normalize(void *memptr, size_t *len);

int		ft_bigint_bigger(void *memptr1, void *memptr2, size_t n1, size_t n2);
int		ft_bigint_smaller(void *memptr1, void *memptr2, size_t n1, size_t n2);
int		ft_bigint_equal(void *memptr1, void *memptr2, size_t n1, size_t n2);

void	ft_bigint_increment(void *memptr, size_t n);
void	ft_bigint_decrement(void *memptr, size_t n);

void	ft_bigint_shl(void *memptr, size_t shift, size_t n);
void	ft_bigint_shr(void *memptr, size_t shift, size_t n);

void	ft_bigint_add(void *memptr1, void *memptr2, size_t n);
void	ft_bigint_sub(void *memptr1, void *memptr2, size_t n1, size_t n2);

void	ft_bigint_mul(void **memptr1, void **memptr2, size_t *n1, size_t *n2);
void	ft_bigint_div(void **memptr1, void **memptr2, size_t *n1, size_t *n2);

#endif
