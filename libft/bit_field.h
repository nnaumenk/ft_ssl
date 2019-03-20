/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_field.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 19:38:10 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_FIELD_H
# define BIT_FIELD_H

typedef struct	s_bit
{
	unsigned	n8:1;
	unsigned	n7:1;
	unsigned	n6:1;
	unsigned	n5:1;
	unsigned	n4:1;
	unsigned	n3:1;
	unsigned	n2:1;
	unsigned	n1:1;
}				t_bit;

typedef struct	s_tetrit
{
	unsigned	n4:2;
	unsigned	n3:2;
	unsigned	n2:2;
	unsigned	n1:2;
}				t_tetrit;

typedef union	u_byte
{
	t_bit		bit;
	t_tetrit	tetrit;
	char		byte;
}				t_byte;

#endif
