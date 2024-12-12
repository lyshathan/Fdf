/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:54:22 by ly-sha            #+#    #+#             */
/*   Updated: 2024/12/02 08:54:31 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	print_ptr(void *ptr, int *count);
void	print_nbr(int nbr, int *count);
void	print_unsigned_nbr(unsigned int nbr, int *count);
void	print_hexa(int nbr, int *count, char c);

#endif
