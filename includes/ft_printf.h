/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 16:59:00 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/27 18:46:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			dot;
	int			l_align;
	int			zero;
}				t_flag;

typedef struct	s_data
{
	const char	*source;
	char		*copy;
	char		*conversion;
	t_flag		has;
	int			arglen;
	int			width;
	int			precision;
	int			index;
	int			len;
	va_list		ap;
}				t_data;

void			ft_put16base_fd(long long num, int fd);
void			ft_putnbr_x_fd(unsigned int num, int fd, t_data *data);
void			ft_putnbr_large_x_fd(unsigned int num, int fd, t_data *data);
int				ft_hexlen(unsigned int num);
int				ft_ptrlen(long long num, t_data *data);
int				ft_intlen(long long num);
void			display_d(t_data *data);
void			display_s(t_data *data);
void			display_c(t_data *data);
void			display_p(t_data *data);
void			display_u(t_data *data);
void			display_x(t_data *data);
void			display_large_x(t_data *data);
void			display_percent(t_data *data);
void			check_l_align_and_zero(t_data *data);
void			zero_print(t_data *data);
void			white_print(t_data *data);
int				valid_check(const char *s);
void			valid_check2(const char *s, int *i);
int				is_flag(char c);
int				is_output_char(char c);
void			initialize(t_data *data, const char *format);
void			reinitialize(t_data *data);
void			number_parse(t_data *data);
void			asterik_parse(t_data *data);
void			flag_parse(t_data *data);
void			input_parse(t_data *data);
void			int_swap(int *a, int *b);
void			asterik_minus_process(t_data *data);

/*
** libft
*/

int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd, t_data *data);
void			ft_putnbr_fd(long long temp, int fd, t_data *data);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(const char *s, unsigned int start, size_t len);

#endif
