/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:27:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 16:37:45 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# define AND(x, y) (x & y)
# define OR(x, y) (x | y)
# define XOR(x, y) (x ^ y)
# define ROL(x, count) (OR((x << count), (x >> (sizeof(x) * 8 - count))))
# define ROR(x, count) (OR((x >> count), (x << (sizeof(x) * 8 - count))))

# define MD5_FL_1_1 	"-p		echo STDIN to STDOUT"
# define MD5_FL_1 		MD5_FL_1_1 " and append the checksum to STDOUT"
# define MD5_FL_2 		"-q		quiet mode"
# define MD5_FL_3 		"-r		reverse the format of the output"
# define MD5_FL_4 		"-s		print the sum of the given string"
# define MD5_OPTIONS 	MD5_FL_1, MD5_FL_2, MD5_FL_3, MD5_FL_4

typedef struct	s_md5_flags
{
	int			p;
	int			q;
	int			r;
	int			s;
}				t_md5_flags;

typedef struct	s_md5_data
{
	char		*text;
	size_t		len;
	uint8_t		hash[64];
	uint8_t		hash_len;
}				t_md5_data;

#endif
