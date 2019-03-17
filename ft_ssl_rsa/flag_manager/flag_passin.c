/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_passin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:01:04 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_rsa_check_flag_passin(int *i, int ac, char **av, t_rsa_flag *flag)
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
	flag->passin = av[*i] + 5;
	return (0);
}
