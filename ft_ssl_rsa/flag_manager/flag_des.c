/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_des.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:53:56 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_rsa_des_cbc_encryption(t_rsa *rsa, char *key, char *iv)
{
	char		vector[8];
	char		keys[16][48];
	char		*ptr;
	size_t		blocks;
		
	ft_des_encrypt_keys((uint8_t *)keys, (uint8_t *)key);
	ft_memcpy(vector, iv, 8);
	rsa->text = ft_des_add_padding(rsa->text, &rsa->len, 1);
	ptr = rsa->text;
	blocks = rsa->len / 8;
	while (blocks--)
	{
		ft_xor_mem(ptr, vector, 8);
		ft_des_algor((uint8_t *)ptr, (uint8_t *)keys);
		ft_memcpy(vector, ptr, 8);
		ptr += 8;
	}
}
	
int			ft_rsa_make_flag_des(t_rsa *rsa)
{
	char		*key;

	if (ft_rsa_make_flag_passout(rsa))
		return (1);
	key = ft_evp(rsa->flag.passout, (uint8_t *)rsa->flag.vector, 8);
	ft_rsa_des_cbc_encryption(rsa, key, rsa->flag.vector);
	ft_strdel(&key);
	return (0);
}

int			ft_rsa_check_flag_des(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->des = 1;
	return (0);
}

