/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:56:27 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include "bit_field.h"

void			ft_bzero(void *s, size_t n);
char			*ft_malloc_str(size_t size);
char			*ft_strnew(size_t size);
size_t			ft_strlen(char *str);
char			*ft_strchr(char *str, char elem);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strncpy(char *dst, char *src, size_t len);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_search_pos_int(char *s, int *i);
void			ft_strdel(char **as);

int				ft_strequ(char *str1, char *str2);
char			*ft_strtrim(char *str, char val);

char			*ft_str_parse(char *str, char c);

void			ft_xor_mem_value(void *dst, int val, size_t count);
void			ft_xor_mem(void	*dst, void *src, size_t count);

void			ft_bits_to_mem(void *mem, void *bits, size_t n);
void			ft_mem_to_bits(void *bits, void *mem, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *memptr, int val, size_t num);
int				ft_memequ(void *mem1, void *mem2, size_t n);
void			*ft_memjoin(void *mem1, void *mem2, size_t n1, size_t n2);
void			*ft_memjoin_del(void *mem1, void *mem2, size_t n1, size_t n2);
void			ft_memrev(void *mem, size_t num);
void			ft_memswap(void *a, void *b, size_t n);
void			*ft_memdup(void *memptr, size_t n);

void			ft_free_matrix(char ***str);
char			**ft_strsplit(char *s, char c);

int				get_next_line(const int fd, char **line);

int				ft_print_fd(const int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
char			*ft_mem_joiner(size_t *len, const int n, ...);
char			*ft_str_joiner(size_t *len, const int n, ...);
void			ft_generate_random(void *mem, size_t n);
void			ft_generate_urandom(void *mem, size_t n);
size_t			ft_get_random_in_range(size_t min, size_t max);

#endif
