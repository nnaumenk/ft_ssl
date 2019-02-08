/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:43:22 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/10/08 23:19:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define B64_F1 {"-o", ft_check_flag_o}
# define B64_F2 {"-i", ft_check_flag_i}
# define B64_F3 {"-e", ft_check_flag_e}
# define B64_F4 {"-d", ft_check_flag_d}
# define B64_F0 {0, 0}
# define BASE64_OPTIONS_FUNCTIONS B64_F1, B64_F2, B64_F3, B64_F4, B64_F0

# define BASE64_FL_1 "-d		decode mode"
# define BASE64_FL_2 "-e		encode mode"
# define BASE64_FL_3 "-i		input file"
# define BASE64_FL_4 "-o		output file"
# define BASE64_OPTIONS BASE64_FL_1, BASE64_FL_2, BASE64_FL_3, BASE64_FL_4

# define BASE_1 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define BASE_2 "abcdefghijklmnopqrstuvwxyz"
# define BASE_3 "0123456789+/=\n"
# define BASE 	BASE_1 BASE_2 BASE_3

#endif
