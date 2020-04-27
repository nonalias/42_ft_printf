/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 16:57:55 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/27 18:53:56 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print_process(t_data *data)
{
	if (!ft_strncmp(data->conversion, "d", 1))
		display_d(data);
	else if (!ft_strncmp(data->conversion, "i", 1))
		display_d(data);
	else if (!ft_strncmp(data->conversion, "s", 1))
		display_s(data);
	else if (!ft_strncmp(data->conversion, "c", 1))
		display_c(data);
	else if (!ft_strncmp(data->conversion, "p", 1))
		display_p(data);
	else if (!ft_strncmp(data->conversion, "u", 1))
		display_u(data);
	else if (!ft_strncmp(data->conversion, "x", 1))
		display_x(data);
	else if (!ft_strncmp(data->conversion, "X", 1))
		display_large_x(data);
	else if (!ft_strncmp(data->conversion, "%", 1))
		display_percent(data);
}

void	whole_process(t_data *data)
{
	while (data->copy[data->index])
	{
		if (data->copy[data->index] == '%')
		{
			reinitialize(data);
			flag_parse(data);
			input_parse(data);
			print_process(data);
			free(data->conversion);
			continue ;
		}
		write(1, &data->copy[data->index], 1);
		data->len++;
		data->index++;
	}
	va_end(data->ap);
}

int		ft_printf(const char *s, ...)
{
	t_data	*data;
	int		len;

	if (!valid_check(s))
		return (-1);
	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, s);
	initialize(data, s);
	whole_process(data);
	len = data->len;
	free(data);
	return (len);
}
