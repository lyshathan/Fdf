/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:02:25 by lthan             #+#    #+#             */
/*   Updated: 2024/11/25 11:19:05 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	special_print(char c, va_list args, int *count)
{
	if (c == 'c')
		print_char(va_arg(args, int), count);
	if (c == 's')
		print_str(va_arg(args, char *), count);
	if (c == 'p')
		print_ptr(va_arg(args, void *), count);
	if (c == 'i' || c == 'd')
		print_nbr(va_arg(args, int), count);
	if (c == 'u')
		print_unsigned_nbr(va_arg(args, unsigned int), count);
	if (c == 'x' || c == 'X')
		print_hexa(va_arg(args, int), count, c);
	if (c == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && !is_format(format[i + 1]))
			return (va_end(args), -1);
		if (format[i] == '%' && format[i + 1] && is_format(format[i + 1]))
			special_print(format[++i], args, &count);
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	return (va_end(args), count);
}
