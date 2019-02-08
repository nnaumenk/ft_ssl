/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:45:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

int		ft_md5_check_flag(int *i, int ac, char **av, t_md5_flags *flags)
{
	if (ft_strequ(av[*i], "-s"))
	{
		if (++*i == ac)
		{
			ft_print("ft_ssl: missing string argument for -s\n");
			return (0);
		}
		flags->s = 1;
	}
	else if (ft_strequ(av[*i], "-p"))
	{
		if (flags->p == 0)
			flags->p = 1;
	}
	else if (ft_strequ(av[*i], "-q"))
		flags->q = 1;
	else if (ft_strequ(av[*i], "-r"))
		flags->r = 1;
	else
	{
		ft_print("ft_ssl: '%s' is an unknown option\noptions are\n", av[*i]);
		ft_print("%s\n%s\n%s\n%s\n", MD5_OPTIONS);
		return (0);
	}
	return (1);
}

void	ft_md5_search_files(t_alg *my, t_md5_flags *flags, int ac, char **av)
{
	int			i;

	i = -1;
	while (++i < ac)
		ft_md5_output(my, flags, av[i]);
}

void	ft_md5_search_flags(t_alg *my, t_md5_flags *flags, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_md5_search_files(my, flags, ac - i, &av[i]);
			return ;
		}
		else if (ft_md5_check_flag(&i, ac, av, flags) == 0)
			return ;
		else if (flags->s == 1)
		{
			ft_md5_output_flag_s(my, flags, av[i]);
			flags->s = -1;
		}
		else if (flags->p == 1)
		{
			ft_md5_output_flag_p(my);
			flags->p = -1;
		}
	}
	if (flags->p == 0 && flags->s == 0)
		ft_md5_output_noflags(my);
}

void	ft_md5_flags(void *my, int ac, char **av)
{
	t_md5_flags		flags;

	flags.p = 0;
	flags.q = 0;
	flags.r = 0;
	flags.s = 0;
	ft_md5_search_flags(my, &flags, ac, av);
}
