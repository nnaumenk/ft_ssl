/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:10:46 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 19:31:03 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_alg	g_algors_arr[] =
{
	{"md5", "MD5", ft_md5, ft_md5_flags},
	{"sha1", "SHA1", ft_sha1, ft_md5_flags},
	{"sha256", "SHA256", ft_sha256, ft_md5_flags},
	{"sha512", "SHA512", ft_sha512, ft_md5_flags},
	{"whirlpool", "WHIRLPOOL", ft_whirlpool, ft_md5_flags},
	{"base64", "BASE64", ft_base64, ft_b64_flags},
	{"des", "DES", ft_des_cbc, ft_des_flags},
	{"des-cbc", "DES-CBC", ft_des_cbc, ft_des_flags},
	{"des-ecb", "DES-ECB", ft_des_ecb, ft_des_flags},
	{"des-pcbc", "DES-PCBC", ft_des_pcbc, ft_des_flags},
	{"des-cfb", "DES-CFB", ft_des_cfb, ft_des_flags},
	{"des-ofb", "DES-OFB", ft_des_ofb, ft_des_flags},
	{"des3", "DES3", ft_des3_cbc, ft_des_flags},
	{"des3-cbc", "DES3-CBC", ft_des3_cbc, ft_des_flags},
	{"des3-ecb", "DES3-ECB", ft_des3_ecb, ft_des_flags},
	{"des3-pcbc", "DES3-PCBC", ft_des3_pcbc, ft_des_flags},
	{"des3-cfb", "DES3-CFB", ft_des3_cfb, ft_des_flags},
	{"des3-ofb", "DES3-OFB", ft_des3_ofb, ft_des_flags},
	{"rsa", "RSA", ft_rsa, ft_rsa_flags},
	{"genrsa", "GENRSA", ft_genrsa, ft_genrsa_flags},
	{"rsautl", "RSAUTL", ft_rsautl, ft_rsautl_flags},
	{0, 0, 0, 0}
};

int		ft_choose_first_param(t_alg *my, char *av)
{
	int			i;

	i = -1;
	while (g_algors_arr[++i].name_big)
	{
		*my = g_algors_arr[i];
		if (ft_strequ(av, g_algors_arr[i].name_big))
			return (1);
		if (ft_strequ(av, g_algors_arr[i].name_small))
			return (1);
	}
	ft_print("ft_ssl: '%s' is an invalid command.\n%s", av, ALL_CMD);
	return (0);
}

char	*ft_strtrim_comma(char *str)
{
	char	*new;
	size_t	len;
	char	first;
	char	last;

	len = ft_strlen(str);
	first = str[0];
	last = str[len - 1];
	if ((first == '\'' && last == '\'') || (first == '\"' && last == '\"'))
	{
		new = ft_malloc_str(len - 2);
		ft_memcpy((void *)new, (void *)&str[1], len - 2);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

void	ft_parse_from_console(t_alg *my)
{
	char	*line;
	char	**av;
	int		ac;

	while (1)
	{
		ft_print("ft_ssl> ");
		if (get_next_line(0, &line))
		{
			av = ft_strsplit(line, ' ');
			if (av[0])
			{
				ac = -1;
				while (av[++ac])
					av[ac] = ft_strtrim_comma(av[ac]);
				if (ft_choose_first_param(my, *av))
					(my->flag_pointer)(my, ac - 1, av + 1);
			}
			ft_free_matrix(&av);
			ft_strdel(&line);
			continue ;
		}
		break ;
	}
}

int		main(int ac, char **av)
{
	t_alg	my;

	unsigned char *val1;
	unsigned char *val2;
	unsigned char *res;

	val1 = malloc(4);
	ft_generate_urandom(val1, 1);
	val2 = malloc(2);
	ft_generate_urandom(val2, 1);
	ft_print_big_int("1", val1, 1);
	ft_print_big_int("2", val2, 1);
	res = ft_memmul(val1, val2, 1, 1);
	ft_print_big_int("3", res, 2);


	USE(ac);
	USE(av);
	if (ac == 1)
		ft_parse_from_console(&my);
	else if (ft_choose_first_param(&my, av[1]))
		(my.flag_pointer)(&my, ac - 2, av + 2);
	return (0);
}
