/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:40:04 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 00:42:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "des.h"

void	ft_delete_flags(t_des *data)
{
	ft_strdel(&data->text);
	if (data->flag.fd_input != 0)
		close(data->flag.fd_input);
	if (data->flag.fd_output != 1)
		close(data->flag.fd_output);
}

void	ft_des_search_flags(t_alg *my, t_des *data, int ac, char **av)
{
	const t_des_options		options[] = {DES_OPTIONS_FUNCTIONS};
	int						i;
	int						j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (options[++j].name)
			if (ft_strequ(av[i], options[j].name))
			{
				if ((options[j].function)(&i, ac, av, data))
					return ;
				break ;
			}
		if (options[j].name == NULL)
		{
			ft_print("ft_ssl: '%s' is an unknown option\noptions are\n", av[i]);
			ft_print("%s%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", DES_OPTIONS);
			return ;
		}
	}
	(my->alg_pointer)(data);
	if ((data->encrypt_decrypt_fun)(data) == 0)
		ft_delete_flags(data);
}

void	ft_des_flags(void *my, int ac, char **av)
{
	t_des		data;

	data.flag.a = 0;
	data.flag.decrypt = 0;
	data.flag.name_input = NULL;
	data.flag.name_output = NULL;
	data.flag.password = NULL;
	data.flag.salt = NULL;
	data.flag.key = NULL;
	data.flag.vector = NULL;
	data.flag.pbkdf2 = 0;
	ft_des_search_flags(my, &data, ac, av);
}
