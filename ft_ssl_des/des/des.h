/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:33:01 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/01/20 01:34:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# define DF_1	{"-a",		ft_check_flag_a}
# define DF_2	{"-d",		ft_check_flag_d}
# define DF_3	{"-e",		ft_check_flag_e}
# define DF_4	{"-i",		ft_check_flag_i}
# define DF_5	{"-k",		ft_check_flag_k}
# define DF_6	{"-o",		ft_check_flag_o}
# define DF_7	{"-p",		ft_check_flag_p}
# define DF_8 	{"-s",		ft_check_flag_s}
# define DF_9 	{"-v",		ft_check_flag_v}
# define DF_A	{"-pbkdf2",	ft_check_flag_pbkdf2}
# define DF_0	{0, 0}
# define DES_FUN_OPTION_1	DF_1, DF_2, DF_3, DF_4, DF_5, DF_6
# define DES_FUN_OPTION_2	DF_7, DF_8, DF_9, DF_A, DF_0
# define DES_OPTIONS_FUNCTIONS DES_FUN_OPTION_1, DES_FUN_OPTION_2

# define DES_FL_1 "-a 		decode/encode the input/output in base64"
# define DES_FL_1_1 ", depending on the encrypt mode"
# define DES_FL_2 "-d		decrypt mode"
# define DES_FL_3 "-e		encrypt mode"
# define DES_FL_4 "-i		input file for message"
# define DES_FL_5 "-k		key in hex is the next arguement"
# define DES_FL_6 "-o		output file for message"
# define DES_FL_7 "-p		password in ascii is the next argument"
# define DES_FL_8 "-s		the salt in hex is the next argument"
# define DES_FL_9 "-v		initialization vector in hex is the next argument"
# define DES_FL_10 "-pbkdf2		using pbkdf2 function as default"
# define DES_FL_OPTION_1 	DES_FL_1, DES_FL_1_1, DES_FL_2, DES_FL_3, DES_FL_4
# define DES_FL_OPTION_2 	DES_FL_5, DES_FL_6, DES_FL_7, DES_FL_8, DES_FL_9
# define DES_OPTIONS		DES_FL_OPTION_1, DES_FL_OPTION_2, DES_FL_10

# define IP_0 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4
# define IP_1 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8
# define IP_2 57, 49, 41, 33, 25, 17,  9, 1, 59, 51, 43, 35, 27, 19, 11, 3
# define IP_3 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
# define IP_TABLE IP_0, IP_1, IP_2, IP_3

# define IP_REV_0 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31
# define IP_REV_1 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29
# define IP_REV_2 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27
# define IP_REV_3 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41,  9, 49, 17, 57, 25
# define IP_REV_TABLE IP_REV_0, IP_REV_1, IP_REV_2, IP_REV_3

# define KEY48_0 14, 17, 11, 24, 01, 05, 03, 28, 15, 06, 21, 10, 23, 19, 12, 04
# define KEY48_1 26,  8, 16, 07, 27, 20, 13, 02, 41, 52, 31, 37, 47, 55, 30, 40
# define KEY48_2 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
# define KEY48_TABLE KEY48_0, KEY48_1, KEY48_2

# define KEY56_0 57, 49, 41, 33, 25, 17,  9,  1, 58, 50, 42, 34, 26, 18
# define KEY56_1 10,  2, 59, 51, 43, 35, 27, 19, 11,  3, 60, 52, 44, 36
# define KEY56_2 63, 55, 47, 39, 31, 23, 15,  7, 62, 54, 46, 38, 30, 22
# define KEY56_3 14,  6, 61, 53, 45, 37, 29, 21, 13,  5, 28, 20, 12,  4
# define KEY56_TABLE KEY56_0, KEY56_1, KEY56_2, KEY56_3

# define BK48_0 32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,  8,  9, 10, 11
# define BK48_1 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21
# define BK48_2 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 01
# define BLOCK48_TABLE BK48_0, BK48_1, BK48_2

# define P_0	16, 7, 20, 21, 29, 12, 28, 17,  1, 15, 23, 26,  5, 18, 31, 10
# define P_1	 2, 8, 24, 14, 32, 27,  3,  9, 19, 13, 30,  6, 22, 11,  4, 25
# define P_TABLE P_0, P_1

# define ST_0_0 14, 04, 13, 01, 02, 15, 11, 8, 03, 10, 06, 12, 05, 9, 00, 07
# define ST_0_1 00, 15, 07, 04, 14, 02, 13, 01, 10, 06, 12, 11, 9, 05, 03, 8
# define ST_0_2 04, 01, 14, 8, 13, 06, 02, 11, 15, 12, 9, 07, 03, 10, 05, 00
# define ST_0_3 15, 12, 8, 02, 04, 9, 01, 07, 05, 11, 03, 14, 10, 00, 06, 13
# define STR0	ST_0_0, ST_0_1, ST_0_2, ST_0_3

# define ST_1_0 15,	01,	8,	14,	06,	11,	03,	04,	9,	07,	02,	13,	12,	00,	05,	10
# define ST_1_1 03,	13,	04,	07,	15,	02,	8,	14,	12,	00,	01,	10,	06,	 9, 11,	05
# define ST_1_2 00, 14,	07,	11,	10,	04,	13,	01,	05,	8,	12,	06,	9,	03,	02,	15
# define ST_1_3 13,	8,	10,	01,	03,	15,	04,	02,	11,	06,	07,	12,	00,	05,	14,	9
# define STR1	ST_1_0, ST_1_1, ST_1_2, ST_1_3

# define ST_2_0 10,	00,	9,	14,	06,	03,	15,	05,	01,	13,	12,	07,	11,	04,	02,	8
# define ST_2_1 13,	07,	00,	9,	03,	04,	06,	10,	02,	8,	05,	14,	12,	11,	15,	01
# define ST_2_2 13,	06,	04,	9,	8,	15,	03,	00,	11,	01,	02,	12,	05,	10,	14,	07
# define ST_2_3 01,	10,	13,	00,	06,	9,	8,	07,	04,	15,	14,	03,	11,	05,	02,	12
# define STR2	ST_2_0, ST_2_1, ST_2_2, ST_2_3

# define ST_3_0 07,	13,	14,	03,	00,	06,	 9,	10,	01,	02,	 8, 05,	11,	12,	04, 15
# define ST_3_1 13,	 8,	11,	05,	06,	15,	00,	03,	04,	07,	02,	12,	01,	10,	14,  9
# define ST_3_2 10,	06,  9, 00,	12,	11,	07,	13,	15,	01,	03,	14,	05,	02,	 8, 04
# define ST_3_3 03,	15,	00,	06,	10,	01,	13,	 8,	 9,	04,	05,	11,	12,	07,	02,	14
# define STR3	ST_3_0, ST_3_1, ST_3_2, ST_3_3

# define ST_4_0 02,	12,	04,	01,	07,	10,	11,	06,	8,	05,	03,	15,	13,	00,	14,	9
# define ST_4_1 14,	11,	02,	12,	04,	07,	13,	01,	05,	00,	15,	10,	03,	9,	8,	06
# define ST_4_2 4,	02,	01,	11,	10,	13,	07,	8,	15,	9,	12,	05,	06,	03,	00,	14
# define ST_4_3 11,	8,	12,	07,	01,	14,	02,	13,	06,	15,	00,	9,	10,	04,	05,	03
# define STR4	ST_4_0, ST_4_1, ST_4_2, ST_4_3

# define ST_5_0 12,	01,	10,	15,	9,	02,	06,	8,	00,	13,	03,	04,	14,	07,	05,	11
# define ST_5_1 10,	15,	04,	02,	07,	12,	9,	05,	06,	01,	13,	14,	00,	11,	03,	8
# define ST_5_2 9,	14,	15,	05,	02,	8,	12,	03,	07,	00,	04,	10,	01,	13,	11,	06
# define ST_5_3 04,	03,	02,	12,	9,	05,	15,	10,	11,	14,	01,	07,	06,	00,	8,	13
# define STR5	ST_5_0, ST_5_1, ST_5_2, ST_5_3

# define ST_6_0 04, 11, 02, 14, 15, 00, 8, 13, 03, 12, 9, 07, 05, 10, 06, 01
# define ST_6_1 13, 00, 11, 07, 04, 9, 01, 10, 14, 03, 05, 12, 02, 15, 8, 06
# define ST_6_2 01, 04, 11, 13, 12, 03, 07, 14, 10, 15, 06, 8, 00, 05, 9, 02
# define ST_6_3 06, 11, 13, 8, 01, 04, 10, 07, 9, 05, 00, 15, 14, 02, 03, 12
# define STR6	ST_6_0, ST_6_1, ST_6_2, ST_6_3

# define ST_7_0 13, 02, 8, 04, 06, 15, 11, 01, 10, 9, 03, 14, 05, 00, 12, 07
# define ST_7_1 01, 15, 13, 8, 10, 03, 07, 04, 12, 05, 06, 11, 00, 14, 9, 02
# define ST_7_2 07, 11, 04, 01, 9, 12, 14, 02, 00, 06, 10, 13, 15, 03, 05, 8
# define ST_7_3 02, 01, 14, 07, 04, 10, 8, 13, 15, 12, 9, 00, 03, 05, 06, 11
# define STR7	ST_7_0, ST_7_1, ST_7_2, ST_7_3

# define S_TABLE {STR0}, {STR1}, {STR2}, {STR3}, {STR4}, {STR5}, {STR6}, {STR7}

#endif
