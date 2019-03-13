/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsautl_flags.c                                     :+:      :+:    :+:   */
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
	{"-rand", ft_rsa_check_flag_rand},
	{"-in", ft_rsa_check_flag_in},
	{"-out", ft_rsa_check_flag_out},
	{0, 0}
};

static char			*g_options_output =

"-in file\tinput file\n"					\
"-out file\toutput file\n"					\
"-inkey file\tinput key\n"					\
"-pubin\t\tinput is an RSA public\n"		\
"-encrypt\tencrypt with public key\n"		\
"-decrypt\tdecrypt with private key\n"		\
"-hexdump\thex dump output\n"				\

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
			ft_print_fd(2, "ft_ssl: '%s' is an unknown option\n", av[i]);
			ft_print_fd(2, "options are\n%s\n", g_options_output);
			return ;
		}
	}
	(my->alg_pointer)(flag);
}

void			ft_rsautl_flags(void *my, int ac, char **av)
{
	t_rsa_flag		flag;

	ft_bzero(&flag, sizeof(t_rsa_flag));
	ft_search_flags(my, &flag, ac, av);
	USE(my);
}
