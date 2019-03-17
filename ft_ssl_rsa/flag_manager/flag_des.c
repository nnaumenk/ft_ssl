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

void	ft_salt_to_hex(char **salt)
{
	char const		*base = "0123456789ABCDEF";
	size_t			len;
	char			*new;
	unsigned char	*byte;
	char			*hex;

	byte = (unsigned char *)*salt;
	new = ft_strnew(18);
	new[17] = '\n';
	new[16] = '\n';
	hex = new;
	len = 8;
	while (len--)
	{
		hex[1] = base[(*byte) % 16];
		(*byte) /= 16;
		hex[0] = base[(*byte) % 16];
		hex += 2;
		byte++;
	}
	ft_strdel(salt);
	*salt = new;
}

void	ft_rsa_des_cbc_encryption(t_rsa *rsa, char *key, char *vector)
{
	char		keys[16][48];
	char		*ptr;
	size_t		blocks;
		
	ft_des_encrypt_keys((uint8_t *)keys, (uint8_t *)key);
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
	
int		ft_rsa_make_flag_des(t_rsa *rsa)
{
	const char	*info = "Proc-Type: 4,ENCRYPTED\nDEK-Info: DES-CBC,";
	char		*tmp;
	char		*salt;
	char		*key;
	char		*vector;

	if (ft_rsa_make_flag_passout(rsa))
		return (1);
	salt = (char *)malloc(8);
	//ft_generate_random(salt, 8);

	//*(size_t *)salt = 	0x394F58D3B06713BD;
	*(size_t *)salt = 	0xbd1367b0d3584f39;
	key = ft_evp(rsa->flag.passout, (uint8_t *)salt, 16);
	vector = key + 8;
	ft_rsa_des_cbc_encryption(rsa, key, vector);
	ft_strdel(&key);
	rsa->text = ft_b64_encode(rsa->text, &rsa->len);
	ft_salt_to_hex(&salt);
	tmp = ft_mem_joiner(&rsa->len, 3, (char *)info, (size_t)41,
	(char *)salt, ft_strlen(salt), rsa->text, rsa->len);
	ft_strdel(&salt);
	ft_strdel(&rsa->text);
	rsa->text = tmp;
	return (0);
}

int		ft_rsa_check_flag_des(int *i, int ac, char **av, t_rsa_flag *flag)
{
	USE(i);
	USE(ac);
	USE(av);
	flag->des = 1;
	return (0);
}
