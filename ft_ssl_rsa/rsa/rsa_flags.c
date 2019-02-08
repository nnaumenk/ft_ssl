/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:45:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static t_rsa_option	g_option[] =
{
	{"-inform", ft_rsa_check_flag_inform},
	{"-outform", ft_rsa_check_flag_outform},
	{"-in", ft_rsa_check_flag_in},
	{"-passin", ft_rsa_check_flag_passin},
	{"-out", ft_rsa_check_flag_out},
	{"-passout", ft_rsa_check_flag_passout},
	{"-des", ft_rsa_check_flag_des},
	{"-text", ft_rsa_check_flag_text},
	{"-noout", ft_rsa_check_flag_noout},
	{"-modulus", ft_rsa_check_flag_modulus},
	{"-check", ft_rsa_check_flag_check},
	{"-pubin", ft_rsa_check_flag_pubin},
	{"-pubout", ft_rsa_check_flag_pubout},
	{0, 0}
};

static char			*g_options_output =

"-inform format\t\tinput format (DER, NET or PEM(default))\n"	\
"-outform format\t\toutput format (DER, NET or PEM(default))\n"	\
"-in file\t\tinput file (default stdin)\n"						\
"-passin src\t\tinput file passphrase source\n"					\
"-out file\t\toutput file (default stdout)\n"					\
"-passout src\t\toutput file passphrase source\n"				\
"-des\t\t\tencrypt key using des-cbc algorithm\n"				\
"-text\t\t\tprint in plain text in addition to encoded\n"		\
"-noout\t\t\tdo not print encoded version of the key\n"			\
"-modulus\t\tprint the RSA key modulus\n"						\
"-check\t\t\tcheck consistency of RSA private key\n"			\
"-pubin\t\t\texpect a public key (default private key)\n"		\
"-pubout\t\t\toutput a public key (default private key)\n"		\

;

static void		ft_search_flags(t_alg *my, t_rsa_flag *flag, int ac, char **av)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (g_option[++j].option_name)
			if (ft_strequ(av[i], g_option[j].option_name))
			{
				if ((g_option[j].option_function)(&i, ac, av, flag))
					return ;
				break ;
			}
		if (g_option[j].option_name == NULL)
		{
			ft_print("ft_ssl: '%s' is an unknown option\noptions are\n", av[i]);
			ft_print("%s\n", g_options_output);
			return ;
		}
	}
	(my->alg_pointer)(flag);
}

void		ft_rsa_flags(void *my, int ac, char **av)
{
	t_rsa_flag		flag;

	ft_bzero(&flag, sizeof(t_rsa_flag));
	ft_search_flags(my, &flag, ac, av);
}
