/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 20:54:21 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/27 17:39:26 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_hexlen(unsigned int num)
{
	int		count;

	if (!num)
		return (1);
	count = 0;
	while (num)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

int		ft_ptrlen(long long num, t_data *data)
{
	int		count;

	if (!num && data->has.dot)
		return (2);
	else if (!num && !data->has.dot)
		return (3);
	count = 0;
	while (num)
	{
		num = num / 16;
		count++;
	}
	return (count + 2);
}

int		ft_intlen(long long num)
{
	int		count;

	if (!num)
		return (1);
	count = 0;
	if (num < 0)
		num = -num;
	while (num)
	{
		num = num / 10;
		count++;
	}
	return (count);
}
