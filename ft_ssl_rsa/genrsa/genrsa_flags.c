/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa_flags.c                                     :+:      :+:    :+:   */
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
	{"-i", ft_rsa_check_flag_i},
	{"-o", ft_rsa_check_flag_o},
	{0, 0}
};

static char			*g_options_output =

"-rand\t\tusing dev/urandom\n"		\
"-in file\t\tusing file as input random data\n"		\
"-out file\t\toutput to file\n"	\

;

static int		ft_is_flag_numbits(t_rsa_flag *flag, char *str)
{
	size_t	numbits;

	if (*str > '0' && *str < '9')
	{
		numbits = *str++ - '0';
		while (*str > '0' && *str < '9')
			numbits = numbits * 10 + *str++ - '0'
		flag->numbits = numbits;
		return (1);
	}
	return (0);
}

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
			if (ft_is_numbits(t_rsa_flag *flag, av[ac]))
				break ;
			ft_print("ft_ssl: '%s' is an unknown option\noptions are\n", av[i]);
			ft_print("%s\n", g_options_output);
			return ;
		}
	}
	(my->alg_pointer)(flag);
}

void		ft_genrsa_flags(void *my, int ac, char **av)
{
	t_rsa_flag		flag;

	ft_bzero(&flag, sizeof(t_rsa_flag));
	ft_search_flags(my, &flag, ac, av);
	USE(my);
}
