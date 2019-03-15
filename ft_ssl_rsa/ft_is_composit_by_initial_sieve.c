/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_sieve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:54:04 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"
     
int			ft_is_composit_by_initial_sieve(short *mod_array_2048)
{
	size_t		i;
	
	i = -1;
	while (++i < 2048)
	{
		if (mod_array_2048[i] == 0)
			return (1);
	}
	return (0);
}
