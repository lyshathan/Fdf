/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:55:55 by ly-sha            #+#    #+#             */
/*   Updated: 2024/11/19 09:22:11 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa_ptr(size_t address, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (address >= 16)
		print_hexa_ptr((address / 16), count);
	ft_putchar_fd(hexa[address % 16], 1);
	*count += 1;
}

void	print_ptr(void *ptr, int *count)
{
	size_t	address;

	address = (size_t)ptr;
	if (address == 0)
	{
		write (1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write (1, "0x", 2);
	*count += 2;
	print_hexa_ptr(address, count);
	return ;
}
