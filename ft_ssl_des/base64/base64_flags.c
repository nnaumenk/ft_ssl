/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:48:11 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:10:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "base64.h"

int		ft_b64_process_flags(t_alg *my, t_des *data)
{
	data->flag.fd_input = ft_make_input_fd(data->flag.name_input);
	if (data->flag.fd_input == -1)
		return (1);
	data->flag.fd_output = ft_make_output_fd(data->flag.name_output);
	if (data->flag.fd_output == -1)
		return (1);
	data->text = ft_read_from(data->flag.fd_input, &(data->len));
	(my->alg_pointer)(data);
	if (write(data->flag.fd_output, data->text, data->len))
		return (1);
	return (0);
}

static char			*g_options_output =

"-d\t\tdecode mode\n"													\
"-e\t\tencode mode(default)\n"											\
"-i file\t\tinput file(default stdin)\n"								\
"-o file\t\toutput file(default stdout)\n"								\

;

void	ft_b64_search_flags(t_alg *my, t_des *data, int argc, char **argv)
{
	const t_des_options		options[] = {BASE64_OPTIONS_FUNCTIONS};
	int						i;
	int						j;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		while (options[++j].name)
			if (ft_strequ(argv[i], options[j].name))
			{
				if ((options[j].function)(&i, argc, argv, data))
					return ;
				break ;
			}
		if (options[j].name == NULL)
		{
			ft_print_fd(2, "ft_ssl: '%s' is an unknown option\n", argv[i]);
			ft_print_fd(2, "options are\n%s\n", g_options_output);
			return ;
		}
	}
	if (ft_b64_process_flags(my, data) == 0)
		ft_delete_flags(data);
}

void	ft_b64_flags(void *my, int argc, char **argv)
{
	t_des		data;

	data.flag.decrypt = 0;
	data.flag.name_input = NULL;
	data.flag.name_output = NULL;
	ft_b64_search_flags(my, &data, argc, argv);
}
