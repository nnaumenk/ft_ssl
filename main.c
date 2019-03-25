/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:10:46 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:25:10 by nnaumenk         ###   ########.fr       */
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

static char			*g_all_commands =

"\nStandard commands:\n"				\
"rsa\n"									\
"genrsa\n"								\
"rsautl\n"								\

"\nMessage Digest commands:\n"			\
"md5\n"									\
"sha1\n"								\
"sha256\n"								\
"sha512\n"								\
"whirlpool\n"							\

"\nCipher commands:\n"					\
"base64\n"								\
"des\n"									\
"des-ecb\n"								\
"dec-cbc\n"								\
"des-ofb\n"								\
"des-pcbc\n"							\
"des-cfb\n"								\
"des3\n"								\
"des3-ecb\n"							\
"des3-cbc\n"							\
"des3-ofb\n"							\
"des3-pcbc\n"							\
"des3-cfb\n"							\

;

int		ft_choose_first_param(t_alg *my, char *str)
{
	int			i;

	i = -1;
	while (g_algors_arr[++i].name_big)
	{
		if (ft_strequ(str, g_algors_arr[i].name_big))
		{
			*my = g_algors_arr[i];
			return (1);
		}
		if (ft_strequ(str, g_algors_arr[i].name_small))
		{
			*my = g_algors_arr[i];
			return (1);
		}
	}
	ft_print_fd(2, "ft_ssl: '%s' is an invalid command.\n", str);
	ft_print_fd(2, "%s\n", g_all_commands);
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

void	ft_split_argument_line(t_alg *my, char *line)
{
	int		ac;
	char	**av;

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
}

void	ft_parse_from_console(t_alg *my)
{
	char	*line;

	while (1)
	{
		ft_print_fd(1, "ft_ssl> ");
		if (get_next_line(0, &line) == 1)
		{
			if (ft_strequ(line, "exit"))
			{
				ft_strdel(&line);
				break ;
			}
			ft_split_argument_line(my, line);
			ft_strdel(&line);
			continue ;
		}
		break ;
	}
}

0000 - 2a 2a 2a 20 66 74 5f 73-73 6c 20 70 72 6f 6a 65   *** ft_ssl proje
0010 - 63 74 20 2a 2a 2a 0a 0a-41 6c 72 65 61 64 79 20   ct ***..Already
0020 - 69 6d 70 6c 65 6d 65 6e-74 65 64 3a 0a 2d 67 65   implemented:.-ge
0030 - 6e 72 73 61 0a 2d 72 73-61 0a 2d 6d 64 35 0a 2d   nrsa.-rsa.-md5.-
0040 - 73 68 61 31 0a 2d 73 68-61 32 35 36 0a 2d 73 68   sha1.-sha256.-sh
0050 - 61 35 31 32 0a 2d 77 68-69 72 6c 70 6f 6f 6c 0a   a512.-whirlpool.
0060 - 2d 62 61 73 65 36 34 0a-2d 64 65 73 2d 63 62 63   -base64.-des-cbc
0070 - 0a 2d 64 65 73 2d 65 63-62 20 0a 2d 64 65 73 2d   .-des-ecb .-des-
0080 - 70 63 62 63 0a 2d 64 65-73 2d 63 66 62 0a 2d 64   pcbc.-des-cfb.-d
0090 - 65 73 2d 6f 66 62 0a 2d-64 65 73 33 2d 63 62 63   es-ofb.-des3-cbc
00a0 - 0a 2d 64 65 73 33 2d 65-63 62 0a 2d 64 65 73 33   .-des3-ecb.-des3
00b0 - 2d 70 63 62 63 0a 2d 64-65 73 33 2d 63 66 62 0a   -pcbc.-des3-cfb.
00c0 - 2d 64 65 73 33 2d 6f 66-62 0a 0a 49 6e 20 66 75   -des3-ofb..In fu
00d0 - 74 75 72 65 3a 0a 2d 72-73 61 75 74 6c 0a         ture:.-rsautl.





void	ft_all_blocks(char *text, size_t len, size_t row_count)
{
	size_t	i;

	while (row_count--)
	{
		ft_printf("%4zx -", i);///pererobyt
		i = 8;
		while (i--)
			ft_printf("% 2x", text++);
		ft_printf("-%2x", text++);
		i = 7;
		while (i--)
			ft_printf("% 2x", text++);
		ft_printf("   ");
		write(1, text, 16);
		ft_printf("\n");
		text += 16;
	}
}

void	ft_last_block_output(char *text, size_t len, size_t spaces_len)
{
	const char *space = "                                       ";

	write(1, spaces, spaces_len);
	write(1, text, len);
	write(1, "\n", 1);
}

void		ft_last_block(char *text, size_t len, size_t column_count)
{
	size_t	spaces;
	size_t	i;

	if (column_count == 0)
		return ;
	ft_printf("%4zx -", i);////////
	i = -1;
	while (++i < 8)
	{
		if (i < column_count)
			ft_printf("% 2x", block++);
		else
			return (ft_last_block_output(text, column_count, 10));
	}
	if (i < column_count)
		ft_printf("-%2x", block++);
	else
		return (ft_last_block_output(text, column_count, 10));
	while (++i < 8)
	{
		if (i < column_count)
			ft_printf("% 2x", block++);
		else
			return (ft_last_block_output(text, column_count, 10));
	}
}


int		ft_flag_hex_dump(t_rsa *rsa)
{
	size_t	new_len;
	char	*new;

	new = malloc()

	integer_value = rsa->len / 16;
	ft_all_block(rsa->text, integer_value);
	ft_last_block(rsa->text + integer_value, rsa->len - integer_value * 16);
}





int		main(int ac, char **av)
{
	t_alg	my;

	if (ac == 1)
		ft_parse_from_console(&my);
	else if (ft_choose_first_param(&my, av[1]))
		(my.flag_pointer)(&my, ac - 2, av + 2);
	//system("leaks ft_ssl");
	return (0);
}
