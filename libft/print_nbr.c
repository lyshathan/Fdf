/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:37 by ly-sha            #+#    #+#             */
/*   Updated: 2024/11/15 11:12:03 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	print_nbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
	{
		*count += 11;
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		*count += 1;
		nbr = -nbr;
	}
	if (nbr >= 10)
		print_nbr(nbr / 10, count);
	ft_putchar_fd((nbr % 10 + '0'), 1);
	*count += 1;
}
