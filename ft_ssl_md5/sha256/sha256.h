/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 16:30:59 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define CH(x, y, z) 	XOR((AND(x, y)), (AND((~x), z)))
# define MA(x, y, z) 	XOR((AND(x, y)), (XOR((AND(x, z)), (AND(y, z)))))
# define SIGMA0(x)		XOR((ROR(x, 2)), XOR((ROR(x, 13)), (ROR(x, 22))))
# define SIGMA1(x)		XOR((ROR(x, 6)), XOR((ROR(x, 11)), (ROR(x, 25))))
# define DELTA0(x)		XOR((ROR(x, 7)), (XOR((ROR(x, 18)), (x >> 3))))
# define DELTA1(x)		XOR((ROR(x, 17)), (XOR((ROR(x, 19)), (x >> 10))))

# define K00 0x428A2F98
# define K01 0x71374491
# define K02 0xB5C0FBCF
# define K03 0xE9B5DBA5
# define K04 0x3956C25B
# define K05 0x59F111F1
# define K06 0x923F82A4
# define K07 0xAB1C5ED5
# define K08 0xD807AA98
# define K09 0x12835B01
# define K10 0x243185BE
# define K11 0x550C7DC3
# define K12 0x72BE5D74
# define K13 0x80DEB1FE
# define K14 0x9BDC06A7
# define K15 0xC19BF174
# define K16 0xE49B69C1
# define K17 0xEFBE4786
# define K18 0x0FC19DC6
# define K19 0x240CA1CC
# define K20 0x2DE92C6F
# define K21 0x4A7484AA
# define K22 0x5CB0A9DC
# define K23 0x76F988DA
# define K24 0x983E5152
# define K25 0xA831C66D
# define K26 0xB00327C8
# define K27 0xBF597FC7
# define K28 0xC6E00BF3
# define K29 0xD5A79147
# define K30 0x06CA6351
# define K31 0x14292967
# define K32 0x27B70A85
# define K33 0x2E1B2138
# define K34 0x4D2C6DFC
# define K35 0x53380D13
# define K36 0x650A7354
# define K37 0x766A0ABB
# define K38 0x81C2C92E
# define K39 0x92722C85
# define K40 0xA2BFE8A1
# define K41 0xA81A664B
# define K42 0xC24B8B70
# define K43 0xC76C51A3
# define K44 0xD192E819
# define K45 0xD6990624
# define K46 0xF40E3585
# define K47 0x106AA070
# define K48 0x19A4C116
# define K49 0x1E376C08
# define K50 0x2748774C
# define K51 0x34B0BCB5
# define K52 0x391C0CB3
# define K53 0x4ED8AA4A
# define K54 0x5B9CCA4F
# define K55 0x682E6FF3
# define K56 0x748F82EE
# define K57 0x78A5636F
# define K58 0x84C87814
# define K59 0x8CC70208
# define K60 0x90BEFFFA
# define K61 0xA4506CEB
# define K62 0xBEF9A3F7
# define K63 0xC67178F2

# define K_R0 K00, K01, K02, K03, K04, K05, K06, K07, K08, K09
# define K_R1 K10, K11, K12, K13, K14, K15, K16, K17, K18, K19
# define K_R2 K20, K21, K22, K23, K24, K25, K26, K27, K28, K29
# define K_R3 K30, K31, K32, K33, K34, K35, K36, K37, K38, K39
# define K_R4 K40, K41, K42, K43, K44, K45, K46, K47, K48, K49
# define K_R5 K50, K51, K52, K53, K54, K55, K56, K57, K58, K59
# define K_R6 K60, K61, K62, K63

# define SHA256_K_VALUES K_R0, K_R1, K_R2, K_R3, K_R4, K_R5, K_R6

#endif
