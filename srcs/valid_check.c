/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:12:07 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:33:37 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_output_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

void	valid_check2(const char *s, int *i)
{
	while (is_flag(s[*i]))
		(*i)++;
	if (s[*i] == '*')
		(*i)++;
	else
		while (ft_isdigit(s[*i]))
			(*i)++;
	if (s[*i] == '.')
		(*i)++;
	if (s[*i] == '*')
		(*i)++;
	else
		while (ft_isdigit(s[*i]))
			(*i)++;
}

int		valid_check(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			valid_check2(s, &i);
			if (!is_output_char(s[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
