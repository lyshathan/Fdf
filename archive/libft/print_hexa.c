/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:13:33 by ly-sha            #+#    #+#             */
/*   Updated: 2024/11/19 09:00:16 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(int nbr, int *count, char c)
{
	char	*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if ((unsigned int)nbr >= 16)
		print_hexa(((unsigned int)nbr / 16), count, c);
	ft_putchar_fd((hexa[(unsigned int)nbr % 16]), 1);
	*count += 1;
}
