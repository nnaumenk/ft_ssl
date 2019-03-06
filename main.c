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




// size_t	ft_pow_mod2(size_t num, size_t pow, size_t mod)
// {
// 	size_t	res;

// 	if (pow == 0)
// 		return (1);
// 	else if (pow % 2 == 0)
// 	{
// 		res = ft_pow_mod2(num, pow / 2, mod);
// 		return ((res * res) % mod);
// 	}
// 	return (((num % mod) * ft_pow_mod2(num, pow - 1, mod)) % mod);
// }

// size_t	ft_pow_mod3(t_bigint *r, t_bigint *num, t_bigint *pow, t_bigint *mod)
// {
// 	size_t	res;

// 	if (pow == 0)
// 		return (1);
// 	else if (pow % 2 == 0)
// 	{
// 		pow /= 2;
// 		res = ft_pow_mod2(num, pow, mod);
// 		res = (res * res) % mod;
// 		return (res);
// 	}
// 	pow--;
// 	res = ft_pow_mod2(num, pow, mod);
// 	res = (num % mod) * res;
// 	res = res % mod;
// 	return (res);
// }

size_t	ft_get_random_in_range(size_t min, size_t max)
{
	size_t	random;
	size_t	range;

	range = max - min + 1;
	ft_generate_urandom(&random, sizeof(random));
	random = random % range + min;
	return (random);
}

size_t	ft_pow_mod2(size_t num, size_t pow, size_t mod)
{
	size_t	res;

	if (pow == 0)
		return (1);
	else if (pow % 2 == 0)
	{
		res = ft_pow_mod2(num, pow / 2, mod);
		return ((res * res) % mod);
	}
	return (((num % mod) * ft_pow_mod2(num, pow - 1, mod)) % mod);
}


static char	g_probability[] =
{
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 3, 3, 3, 3, 4
};

static void	ft_find_minimal_odd(size_t *minimal_odd, size_t *pow, size_t prime)
{
	*minimal_odd = prime - 1;
	*pow = 0;
	while (1)
	{
		*minimal_odd /= 2;
		++*pow;
		if (*minimal_odd % 2)
			break ;
	}
}

static int	ft_is_pseudoprime_by_2_statement(
			size_t random, size_t minimal_odd, size_t prime, size_t pow)
{
	size_t	result;

	while (--pow)
	{
		minimal_odd <<= 1;
		result = ft_pow_mod2(random, minimal_odd, prime);
		if (result == prime - 1)
			return (1);
	}
	return (0);
}



int			ft_is_composit_by_miller_rabin_int(
			size_t prime, unsigned probability)
{
	size_t		result;
	size_t		random;
	size_t		minimal_odd;
	size_t		pow;

	ft_find_minimal_odd(&minimal_odd, &pow, prime);
	probability = g_probability[probability];
	while (probability--)
	{
		random = ft_get_random_in_range(1, prime - 1);
		result = ft_pow_mod2(random, minimal_odd, prime);
		if (result == 1)
			continue ;
		if (result == prime - 1)
			continue ;
		if (ft_is_pseudoprime_by_2_statement(random, minimal_odd, prime, pow))
			continue ;
		return (1);
	}
	return (0);
}


int		main(int ac, char **av)
{
	t_alg	my;
	// size_t		r;
	// size_t		num;
	// size_t		pow;
	// size_t		mod;

	// num = 0x2935823985923993;
	// pow = 0x2503748572438574;
	// mod = 0x9305709475345438;



	// size_t	i = 100000;
	// while (i--)
	// {
	// 	ft_generate_urandom(&num, sizeof(num));
	// 	ft_generate_urandom(&pow, sizeof(pow));
	// 	ft_generate_urandom(&mod, sizeof(mod));
	// 	r = ft_pow_mod2(num, pow, mod);
	// 	ft_print("res = %U\n", r);

	// }


	// num.size = 8;
	// num.value = malloc(num.size);
	// ft_bzero(num.value, num.size);
	// *(size_t *)num.value = 2;

	// pow.size = 8;
	// pow.value = malloc(pow.size);
	// ft_bzero(pow.value, pow.size);
	// *(size_t *)pow.value = 0xffffffffffffffff;

	// mod.size = 8;
	// mod.value = malloc(mod.size);
	// ft_bzero(mod.value, mod.size);
	// *(size_t *)mod.value = 35237;


	// r = ft_pow_mod2(num, pow, mod);
	// ft_printf("r = %zu\n", r);
	// r = ft_pow_mod3(num, pow, mod);
	// ft_printf("r = %zu\n", r);

	// return (0);






	// size_t	num = 1608;// = 3616092561227787833;// = 600;

	// //ft_generate_urandom(&num, sizeof(num));
	// while (1)
	// {
		
	// 	//ft_printf("num = %zu\n", num);

	// 	if (ft_ssl_is_primary(num, 100))
	// 	{
	// 		break ;
	// 		//printf("%zu is prime by miller\n", num);
	// 	}
	// //	else
	// 		//printf("%zu is composite by miller\n", num);

	// 	if (ft_is_composit_by_sieve(num) == 0)
	// 		break ;
	// 	// else
	// 	// {
			
	// 	// 	//printf("%zu is prime by sieve\n", num);
			
	// 	// }
	// 	num++;
	// }

	t_bigint	a;

	a.size = 2;
	a.value = malloc(a.size);
	ft_generate_urandom(a.value, a.size);

	size_t b = *(short *)a.value;

	ft_bigint_print("bigint", &a);
	if (ft_ssl_is_primary(&a, 99))
		printf("is prime by miller\n");
	else
		printf("is composite by miller\n");

	

	if (ft_is_composit_by_miller_rabin_int(b, 99))
		printf("%zu is composite by miller\n", b);
	else
		printf("%zu is prime by miller\n", b);


	// if (ac == 1)
	// 	ft_parse_from_console(&my);
	// else if (ft_choose_first_param(&my, av[1]))
	// 	(my.flag_pointer)(&my, ac - 2, av + 2);
	// return (0);
	USE(ac);
	USE(av);
}
