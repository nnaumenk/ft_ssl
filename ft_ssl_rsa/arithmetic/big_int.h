/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:12:53 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/14 18:04:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct	s_big_int
{
	unsigned char	*value;
	size_t			size;
}				t_big_int;

#endif
