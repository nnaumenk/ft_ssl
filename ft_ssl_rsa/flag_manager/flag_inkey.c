/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_inkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:52 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	(*g_input[])(t_rsa *) =
{
	ft_pem_inform_private_key,
	ft_pem_inform_public_key
};

int		ft_rsa_make_flag_inkey(t_rsa *rsa)
{
	int		fd;

	if (rsa->flag.inkey == NULL)
	{
		ft_print_fd(2, "ft_ssl: no keyfile specified\n");
		return (1);
	}
	fd = ft_make_input_fd(rsa->flag.inkey);
	if (fd == -1)
	{
		ft_print_fd(2, "ft_ssl: unable to load keyfile\n");
		return (1);
	}
	rsa->text = ft_read_from(fd, &rsa->len);
	ft_close_fd(fd);
	if (g_input[rsa->flag.pubin](rsa))
		return (1);
	return (0);
}

int		ft_rsa_check_flag_inkey(int *i, int ac, char **av, t_rsa_flag *flag)
{
	if (++(*i) == ac)
	{
		ft_print_fd(2, "ft_ssl: missing file argument for %s\n", av[*i - 1]);
		return (1);
	}
	flag->inkey = av[*i];
	return (0);
}