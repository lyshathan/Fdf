/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:37 by ly-sha            #+#    #+#             */
/*   Updated: 2024/11/15 11:10:41 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	print_unsigned_nbr(unsigned int nbr, int *count)
{
	if ((unsigned int)nbr >= 10)
		print_nbr((unsigned int)nbr / 10, count);
	ft_putchar_fd(((unsigned int)nbr % 10 + '0'), 1);
	*count += 1;
}
