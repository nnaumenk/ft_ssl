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

// static int	ft_check_b_null(size_t b, size_t *x, size_t *y)
// {
// 	if (b == 0)
// 	{
// 		*x = 1;
// 		*y = 0;
// 		return (1);
// 	}
// 	return (0);
// }

void 		gcdex(long a, long b, long *x, long *y)
{
	long	integer;
	long	remainder;
	long	x_buf[2];
	long	y_buf[2];

	// if (ft_check_b_null(b, x, y))
	// 	return ;
	x_buf[1] = 1;
	x_buf[0] = 0;
	y_buf[1] = 0;
	y_buf[0] = 1;
	while (b > 0)
	{
		integer = a / b;
		remainder = a - integer * b;
		*x = x_buf[1] - integer * x_buf[0];
		*y = y_buf[1] - integer * y_buf[0];
		a = b;
		b = remainder;
		x_buf[1] = x_buf[0];
		x_buf[0] = *x;
		y_buf[1] = y_buf[0];
		y_buf[0] = *y;
	}
	*x = x_buf[1];
	*y = y_buf[1];
}

// void 		ft_bigint_gcdex(void **mem1, void **mem2, size_t *n1, size_t *n2)
// {
// 	unsigned char	*integer;
// 	size_t			integer_len;
// 	unsigned char	*remainder;
// 	size_t			remainder_len;


// 	size_t	remainder;
// 	size_t	x_buf[2];
// 	size_t	y_buf[2];

// 	if (ft_check_b_null(a, b, x, y))
// 		return ;



// 	integer = ft_memdup(*mem1, *n1);
// 	integer_len = *n1;
// 	remainder = ft_memdup(*mem2, *n2);
// 	remainder_len = *n2;

// 	while (b > 0)
// 	{
// 		ft_bigint_div(&integer, remainder, &integer_len, &remainder_len);






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




// void	gcdex2(size_t a, size_t b)
// {
// 	size_t			i1;
// 	size_t			i2;

// 	i1 = 0;
// 	i2 = 0;
// 	while (a != b)
// 	{
// 		if (a > b)
// 		{
// 			while (a > b)
// 				a -= b;
// 			++i1;
// 		}
// 		else
// 		{
// 			while (a <= b)
// 				b -= a;
// 			++i2;
// 		}
// 	}
// 	ft_printf("num1 = %zu\n", i1);
// 	ft_printf("num2 = %zu\n", i2);
// }

// void	gcdex2(size_t a, size_t b)
// {
// 	size_t			c;
// 	size_t			i;

// 	i = 0;
// 	while (b)
// 	{
// 		c = b;
// 		b = a % b;
// 		a = c;
// 		++i;
// 	}
// 	ft_printf("num1 = %zu\n", i);
// }

void	gcdex2(size_t a, size_t b)
{
	size_t buf = b;
	size_t p;
	size_t q;
	size_t r;
	size_t s;
	size_t x;
	size_t y;
	
	p = 1;
	q = 0;
	r = 0;
	s = 1;
	while (a && b)
	{
		if (a>=b)
		{
			a = a - b;
			p = p + r;
			q = q + s;
		}
		else
		{
			b = b - a;
			r = r + p;
			s = s + q;
		}
		ft_printf("x = %zu\n", r);
	}
	if (a)
	{
		ft_printf("1\n");
		x = p;
		y = q;
	}
	else
	{
		ft_printf("2\n");
		x = r;
		y = s;
	}
	printf("%zu %zu\n", buf - x, y);
}


int		main(int ac, char **av)
{
	// t_alg	my;
	
	gcdex2(3, 26);
	//ft_printf("x = %u\n", x);


	// if (ac == 1)
	// 	ft_parse_from_console(&my);
	// else if (ft_choose_first_param(&my, av[1]))
	// 	(my.flag_pointer)(&my, ac - 2, av + 2);
	// return (0);
	USE(ac);
	USE(av);
}
