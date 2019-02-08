/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 16:29:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

// t_rsa_option	g_option[] =
// {
// 	{"-inform", ft_rsa_make_flag_inform},
// 	{"-outform", ft_rsa_make_flag_outform},
// 	{"-in", ft_rsa_make_flag_in},
// 	{"-passin", ft_rsa_make_flag_passin},
// 	{"-out", ft_rsa_make_flag_out},
// 	{"-passout", ft_rsa_make_flag_passout},
// 	{"-des", ft_rsa_make_flag_des},
// 	{"-text", ft_rsa_make_flag_text},
// 	{"-noout", ft_rsa_make_flag_noout},
// 	{"-modulus", ft_rsa_make_flag_modulus},
// 	{"-check", ft_rsa_make_flag_check},
// 	{"-pubin", ft_rsa_make_flag_pubin},
// 	{"-pubout", ft_rsa_make_flag_pubout},
// 	{0, 0}
// };



void	ft_rsa(void *v_data)
{
	t_rsa	data;

	data.flag = *(t_rsa_flag *)v_data;
	data.flag.fd_input = ft_make_input_fd(data.flag.in);
	data.flag.fd_output = ft_make_output_fd(data.flag.out);
	data.text = ft_read_from(data.flag.fd_input, &data.len);
	ft_rsa_make_flag_text(&data);
}
