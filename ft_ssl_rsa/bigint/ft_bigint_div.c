// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_bigint_div.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
// /*   Updated: 2019/02/20 20:52:04 by nnaumenk         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_bigint.h"

// static size_t	ft_get_start_number(
// 				unsigned char *val1, unsigned char *val2, size_t n1, size_t n2)
// {
// 	unsigned char	*start_number;
// 	size_t			len;

// 	len = n2;
// 	start_number = val1 + n1 - len;
// 	if (ft_bigint_smaller(start_number, val2, len, n2))
// 	{
// 		start_number--;
// 		len++;
// 		while (ft_bigint_smaller(start_number--, val2, len, n2))
// 			len++;
// 	}
// 	else if (ft_bigint_bigger(start_number, val2, len, n2))
// 	{
// 		start_number++;
// 		len--;
// 		while (ft_bigint_bigger(start_number++, val2, len, n2))
// 			len--;
// 		len++;
// 	}
// 	return (len);
// }

// static void		ft_div(
// 				unsigned char **val1, unsigned char **val2, size_t *n1, size_t *n2)
// {
// 	size_t			result_len;
// 	unsigned char	*result;
// 	unsigned char	value;
// 	unsigned char	*tmp_num;
// 	size_t			tmp_num_len;

// 	tmp_num_len = ft_get_start_number(*val1, *val2, *n1, *n2);
// 	tmp_num = *val1 + *n1 - tmp_num_len;
// 	result = (unsigned char *)malloc(*n1);
// 	result_len = 0;
// 	while (tmp_num >= *val1)
// 	{
// 		value = 0;
// 		while (ft_bigint_equbigger(tmp_num, *val2, tmp_num_len, *n2))
// 		{
// 			ft_bigint_sub((void **)&tmp_num, (void **)val2, &tmp_num_len, n2);
// 			++value;
// 		}
// 		result[result_len++] = value;
// 		tmp_num_len++;
// 		tmp_num--;
// 	}
// 	ft_memdel((void *)val2);
// 	*val2 = result;
// 	*n2 = result_len;
// }

// void			ft_bigint_div(void **mem1, void **mem2, size_t *n1, size_t *n2)
// {
// 	unsigned char	*val1;
// 	unsigned char	*val2;

// 	if (ft_bigint_smaller(*mem1, *mem2, *n1, *n2))
// 	{
// 		*n2 = *n1;
// 		ft_memswap(mem1, mem2, sizeof(*mem1));
// 		*n1 = 1;
// 		ft_bzero(*mem1, *n1);
// 		return ;
// 	}
// 	val1 = *mem1;
// 	val2 = *mem2;
// 	ft_div(&val1, &val2, n1, n2);
// 	*mem1 = val1;
// 	*mem2 = val2;
// 	ft_memrev(*mem2, *n2);
// 	ft_memswap(mem1, mem2, sizeof(*mem1));
// 	ft_memswap(n1, n2, sizeof(*n1));
// 	ft_bigint_normalize(*mem1, n1);
// 	ft_bigint_normalize(*mem2, n2);
// }
