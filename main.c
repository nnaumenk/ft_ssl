/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:10:46 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/27 18:22:57 by nnaumenk         ###   ########.fr       */
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


void	ft_check_mod_inverse(void)
{
	t_bigint a;
	t_bigint b;
	t_bigint rev;

	a.size = 4;
	b.size = 2;
	a.value = malloc(a.size);
	b.value = malloc(b.size);
	a.size = 4;
	b.size = 2;
	ft_generate_urandom(a.value, a.size);
	ft_generate_urandom(b.value, b.size);
	// *(size_t *)a.value = 3;
	// *(size_t *)b.value = 9167368;
	ft_bigint_print("1", &a);
	ft_bigint_print("2", &b);
	int ret = ft_mod_inverse(&rev, &a, &b);
	printf("ret = %d\n", ret);
	if (ret == 0)
	{
		
		ft_bigint_print("inverse", &rev);
		ft_bigint_print("1", &a);
		ft_bigint_print("2", &b);
	}
}


// 10 > 3

// p = 1 + 0 * 3 = 1
// a = 10 % 3 = 1;

// 1 < 3
// r = 0 + 1 * 3 = 3;
// mod = 3 % 1 = 0


size_t	f1(size_t a, size_t mod)
{
	size_t	a2 = a;
	size_t	mod2 = mod;
	size_t	p;
	size_t	r;

	p = 1;
	r = 0;
	while (a > 1 && mod > 1)
	{
		if (a >= mod)
		{
			p = p + r * (a / mod);
			a = a % mod;
		}
		else
		{
			r = r + p * (mod / a);
			mod = mod % a;
		}
	}

// 3 1

// 3 > 1
// 2 > 1
// 1 > 1

	while (a && mod)
	{
		if (a >= mod)
		{
			p = p + r;
			a = a - mod;
		}
		else
		{
			r = r + p;
			mod = mod - a;
		}
	}
	if (mod != 1)
		return (-1);
	return (mod2 - r);
}

// 10 >= 3
// p = 1 + 0 = 1
// a = 10 - 3 = 7
// 7 >= 3
// p = 1 + 0 = 1;
// a = 7 - 3 = 4
// .........
// 1 < 3
// r = 0 + 1 = 1;
// 3 = 3 - 1 = 2;
// 1 < 2
// r = 1 + 1 = 2;
// 2 = 2 - 1 = 1;
// 1 >= 1
// p = 1 + 2 = 3;
// a = 1 - 1 = 0;


size_t	f2(size_t a, size_t mod)
{
	size_t	a2 = a;
	size_t	mod2 = mod;
	size_t	p;
	size_t	r;

	p = 1;
	r = 0;
	while (a && mod)
	{
		if (a >= mod)
		{
			p = p + r;
			a = a - mod;

			// p = p + r * (a / mod);
			// a = a % mod;
		}
		else
		{
			r = r + p;
			mod = mod - a;

			// r = r + p * (mod / a);
			// mod = mod % a;
		}
	}
	// printf("a = %zu\n", a);
	// printf("mod = %zu\n", mod);
	//printf("value1 = %zu\n", mod2 - r);
	// printf("value2 = %zu\n", mod2 - p);
	// printf("value3 = %zu\n", a2 - r);
	// printf("value4 = %zu\n", a2 - p);

	if (mod != 1)
		return (-1);
	
	return (mod2 - r);
}

int		main(int ac, char **av)
{
	t_alg	my;

	if (ac == 1)
		ft_parse_from_console(&my);
	else if (ft_choose_first_param(&my, av[1]))
		(my.flag_pointer)(&my, ac - 2, av + 2);
	return (0);
	USE(ac);
	USE(av);
}
