/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_passout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:01:06 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int		ft_read_password(t_rsa *rsa)
{
	char	*password;

	password = getpass("Enter PEM pass phrase:");
	if (ft_strlen(password) < 4)
	{
		ft_print_fd(2, "unable to write key\npassword too small\n");
		return (1);
	}
	rsa->flag.passout = ft_strdup(password);
	password = getpass("Verifying - Enter PEM pass phrase:");
	if (ft_strlen(password) < 4)
	{
		ft_print_fd(2, "unable to write key\npassword too small\n");
		ft_strdel(&rsa->flag.passout);
		return (1);
	}
	if (ft_strequ(rsa->flag.passout, password) == 0)
	{
		ft_print_fd(2, "Verify failure\nunable to write key\n");
		ft_strdel(&rsa->flag.passout);
		return (1);
	}
	ft_strdel(&rsa->flag.passout);
	rsa->flag.passout = password;
	return (0);
}


int		ft_rsa_make_flag_passout(t_rsa *rsa)
{
	char	*password1;

	if (rsa->flag.passout == 0)
	{
		if (ft_read_password(rsa))
			return (1);
	}
	return (0);
}

int		ft_rsa_check_flag_passout(int *i, int ac, char **av, t_rsa_flag *flag)
{
	const char	*pass = "pass:";

	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing src argument for %s\n", av[*i - 1]);
		return (1);
	}
	if (ft_memequ((void *)pass, (void *)av[*i], 5) == 0)
	{
		ft_print_fd(2, "Invalid password argument\n");
		ft_print_fd(2, "Error getting passwords\n");///perenesty v des
		return (1);
	}
	flag->passout = av[*i] + 5;
	return (0);
}
