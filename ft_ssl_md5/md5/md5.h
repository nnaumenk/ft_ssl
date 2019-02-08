/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 03:31:05 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/09/19 19:44:20 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define F(x, y, z) ((x & y) | ((~x) & z))
# define G(x, y, z) ((x & z) | ((~z) & y))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ ((~z) | x))

# define T00 0xd76aa478
# define T01 0xe8c7b756
# define T02 0x242070db
# define T03 0xc1bdceee
# define T04 0xf57c0faf
# define T05 0x4787c62a
# define T06 0xa8304613
# define T07 0xfd469501
# define T08 0x698098d8
# define T09 0x8b44f7af
# define T10 0xffff5bb1
# define T11 0x895cd7be
# define T12 0x6b901122
# define T13 0xfd987193
# define T14 0xa679438e
# define T15 0x49b40821
# define T16 0xf61e2562
# define T17 0xc040b340
# define T18 0x265e5a51
# define T19 0xe9b6c7aa
# define T20 0xd62f105d
# define T21 0x02441453
# define T22 0xd8a1e681
# define T23 0xe7d3fbc8
# define T24 0x21e1cde6
# define T25 0xc33707d6
# define T26 0xf4d50d87
# define T27 0x455a14ed
# define T28 0xa9e3e905
# define T29 0xfcefa3f8
# define T30 0x676f02d9
# define T31 0x8d2a4c8a
# define T32 0xfffa3942
# define T33 0x8771f681
# define T34 0x6d9d6122
# define T35 0xfde5380c
# define T36 0xa4beea44
# define T37 0x4bdecfa9
# define T38 0xf6bb4b60
# define T39 0xbebfbc70
# define T40 0x289b7ec6
# define T41 0xeaa127fa
# define T42 0xd4ef3085
# define T43 0x04881d05
# define T44 0xd9d4d039
# define T45 0xe6db99e5
# define T46 0x1fa27cf8
# define T47 0xc4ac5665
# define T48 0xf4292244
# define T49 0x432aff97
# define T50 0xab9423a7
# define T51 0xfc93a039
# define T52 0x655b59c3
# define T53 0x8f0ccc92
# define T54 0xffeff47d
# define T55 0x85845dd1
# define T56 0x6fa87e4f
# define T57 0xfe2ce6e0
# define T58 0xa3014314
# define T59 0x4e0811a1
# define T60 0xf7537e82
# define T61 0xbd3af235
# define T62 0x2ad7d2bb
# define T63 0xeb86d391

#endif
