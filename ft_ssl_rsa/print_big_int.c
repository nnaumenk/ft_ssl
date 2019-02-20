/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 16:53:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_big_int(char *name, unsigned char *big_int, size_t len)
{
	size_t	i;

	big_int += len;
	ft_printf("%s:\n    %.2hhx:", name, *--big_int);
	i = 0;
	while (++i < len - 1)
	{
		if (i % 15 == 0)
			ft_printf("\n    ");
		ft_printf("%.2hhx:", *--big_int);
	}
	if (i % 15 == 0)
		ft_printf("\n    ");
	ft_printf("%.2hhx\n", *--big_int);
}

void		ft_print_big_int(char *name, unsigned char *big_int, size_t len)
{
	size_t	number;

	if (len > 8)
		ft_big_int(name, big_int, len);
	else
	{
		number = 0;
		ft_memcpy(&number, big_int, len);
		ft_printf("%s: %lu (0x%lx)\n", name, number, number);
	}
}