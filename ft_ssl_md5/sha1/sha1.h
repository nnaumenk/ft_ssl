/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 16:30:59 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
# define SHA1_H

# define CH(x, y, z) 		((x & y) | ((~x) & z))
# define PARITY(x, y, z)	(x ^ y ^ z)
# define MA(x, y, z) 		((x & y) | (x & z) | (y & z))

# define K00 0x5A827999
# define K01 0x6ED9EBA1
# define K02 0x8F1BBCDC
# define K03 0xCA62C1D6

# define SHA1_K_VALUES K00, K01, K02, K03

#endif
