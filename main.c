/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:10:46 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:45:22 by nnaumenk         ###   ########.fr       */
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

size_t	gcd1_b(size_t a, size_t b)
{
	size_t tmp;

	while (a)
	{
		tmp = a;
		a = b % a;
		b = tmp;
	}
	return (b);
}

size_t	gcd2_b(size_t a, size_t b)
{
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	while (a != b)
	{
		if (a >= b)
			a -= b;
		else
			b -= a;
	}
	return (a);
}

// static int	ft_iszero(void *memptr, size_t num)
// {
// 	size_t			i;
// 	size_t			*str64;
// 	unsigned char	*str8;

// 	str64 = (size_t *)memptr;
// 	i = num / sizeof(size_t);
// 	while (i--)
// 		if (*str64++ != 0)
// 			return (0);
// 	str8 = (unsigned char *)str64;
// 	i = num % sizeof(size_t);
// 	while (i--)
// 		if (*str8++ != 0)
// 			return (0);
// 	return (1);
// }

// void	gcd2(unsigned char *mem1, unsigned char *mem2, size_t len1, size_t len2)
// {
// 	unsigned char	*res;
// 	size_t			res_len;

// 	while (ft_bigint_equal(mem1, mem2, len1, len2) == 0)
// 	{
// 		if (ft_bigint_bigger(mem1, mem2, len1, len2))
// 			ft_bigint_sub(mem1, mem2, len1);
// 		else
// 			ft_bigint_sub(mem2, mem1, len2);
// 	}
// }




// void	gcdex(unsigned char *mem1, unsigned char *mem2, size_t len1, size_t len2)
// {
// 	unsigned char	*res;
// 	size_t			res_len;
// 	unsigned char	*buf1;
// 	unsigned char	*buf2;
	
// 	if (mem1 + 1 == mem2)
// 		return ;
// 	if (mem1 < )

// }

// size_t	gcdex1(size_t val1, size_t val2)
// {
// 	size_t		counter;
// 	size_t		res;
// 	size_t		buf1;
// 	size_t		buf2;
	
// 	counter = 1;
// 	buf1 = val1;
// 	buf2 = val2;
// 	while (1)
// 	{
// 		if (buf1 == buf2 + 1)
// 			break ; 
// 		if (buf1 < buf2 + 1)
// 			while (1)
// 			{
// 				counter++;
// 				buf1 += val1;
// 				if (buf1 > buf2)
// 					break ;
// 			}
// 		if (buf1 > buf2 + 1)
// 			while (1)
// 			{
// 				buf2 += val2;
// 				if (buf2 > buf1)
// 					break ;
// 			}
// 	}
// 	return (counter);
// }

// static int	ft_check_b_null(size_t a, size_t b, size_t *x, size_t *y)
// {
// 	if (b == 0)
// 	{
// 		*x = 1;
// 		*y = 0;
// 		return (1);
// 	}
// 	return (0);
// }

// void 		gcdex(size_t a, size_t b, size_t *x, size_t *y)
// {
// 	size_t	integer;
// 	size_t	remainder;
// 	size_t	x_buf[2];
// 	size_t	y_buf[2];

// 	if (ft_check_b_null(a, b, x, y))
// 		return ;
// 	x_buf[1] = 1;
// 	x_buf[0] = 0;
// 	y_buf[1] = 0;
// 	y_buf[0] = 1;
// 	while (b > 0)
// 	{
// 		integer = a / b;
// 		remainder = a - integer * b;
// 		*x = x_buf[1] - integer * x_buf[0];
// 		*y = y_buf[1] - integer * y_buf[0];
// 		a = b;
// 		b = remainder;
// 		x_buf[1] = x_buf[0];
// 		x_buf[0] = *x;
// 		y_buf[1] = y_buf[0];
// 		y_buf[0] = *y;
// 	}
// 	*x = x_buf[1];
// 	*y = y_buf[1];
// }

int		main(int ac, char **av)
{





	// t_alg	my;
	// size_t	a = 24723892;
	// size_t	b = 39429;
	// size_t	x;
	// size_t	y;
	// size_t	d;
	// gcdex(a, b, &x, &y, &d);

	// ft_printf("%zu\n", a);
	// ft_printf("%zu\n", b);
	// ft_printf("%zu\n", x);
	// ft_printf("%zu\n", y);
	// ft_printf("%zu\n", d);


	// 123 - 463;
	// 123 - 123;

	// 888 - 99;

	// 255 - 653;
	// 255 - 255;
	// 65533 - 255;

	unsigned char	*val1;
	unsigned char	*val2;
	unsigned char	*val3;
	unsigned char	*val4;

	size_t	len1 = 8;
	size_t	len2 = 4;
	size_t	len3;
	size_t	len4;

	val1 = malloc(len1);
	val2 = malloc(len2);
	val3 = malloc(len1);
	val4 = malloc(len2);


	while (1)
	{
		len1 = 8;
		len2 = 4;
		len3 = len1;
		len4 = len2;

		ft_generate_urandom(val1, len1);
		ft_generate_urandom(val2, len2);
		ft_memcpy(val3, val1, len3);
		ft_memcpy(val4, val2, len4);

		ft_print_big_int("1", val1, len1);
		ft_print_big_int("2", val2, len2);

		ft_bigint_div((void *)&val1, (void *)&val2, &len1, &len2);

		ft_print_big_int("tselaya chast", val1, len1);
		ft_print_big_int("ostatok", val2, len2);
	// 
		ft_bigint_mul((void *)&val4, (void *)&val1, &len4, &len1);
		ft_print_big_int("otvet1", val4, len4);
		ft_bigint_add((void *)&val4, (void *)&val2, &len4, &len2);
		ft_print_big_int("otvet1", val4, len4);

		if (ft_bigint_equal(val3, val4, len3, len4) == 0)
		{
			ft_print_big_int("1", val3, len3);
			ft_print_big_int("2", val4, len4);
			ft_printf("\n\n\n{error}\n\n\n");
			break ;
		}
	}
	USE(len3);
	USE(len4);
	USE(val3);
	USE(val4);

//	system("leaks ft_ssl");

	// unsigned char	*mem1;
	// unsigned char	*mem2;

	// size_t	len1 = 1024;
	// size_t	len2 = 1024;

	// mem1 = malloc(len1);
	// mem2 = malloc(len2);

	// ft_generate_urandom(mem1, len1);
	// ft_generate_urandom(mem2, len2);

	// ft_print_big_int("mem1", mem1, len1);
	// ft_print_big_int("mem2", mem2, len2);

	// gcd2(mem1, mem2, len1, len2);
		
	// ft_print_big_int("res1", mem1, len1);
	// ft_print_big_int("res2", mem2, len2);	

	// if (ac == 3)
	// 	printf("%zu\n", gcdex1(atoi(av[1]), atoi(av[2])));

	// if (ac == 1)
	// 	ft_parse_from_console(&my);
	// else if (ft_choose_first_param(&my, av[1]))
	// 	(my.flag_pointer)(&my, ac - 2, av + 2);

	USE(ac);
	USE(av);
	return (0);
}
