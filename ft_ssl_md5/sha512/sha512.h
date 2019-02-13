/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 22:58:32 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 16:31:19 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

# define CH(x, y, z) 	XOR((AND(x, y)), (AND((~x), z)))
# define MA(x, y, z) 	XOR((AND(x, y)), (XOR((AND(x, z)), (AND(y, z)))))
# define SIGMA0(x)		XOR((ROR(x, 28)), XOR((ROR(x, 34)), (ROR(x, 39))))
# define SIGMA1(x)		XOR((ROR(x, 14)), XOR((ROR(x, 18)), (ROR(x, 41))))
# define DELTA0(x)		XOR((ROR(x, 1)), (XOR((ROR(x, 8)), (x >> 7))))
# define DELTA1(x)		XOR((ROR(x, 19)), (XOR((ROR(x, 61)), (x >> 6))))

uint64_t g_sha512_k[80];

#endif
