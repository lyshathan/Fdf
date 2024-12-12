/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:42:46 by lthan             #+#    #+#             */
/*   Updated: 2024/11/12 08:43:10 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long long	result;
	int			sign;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result > (LONG_MAX - (nptr[i] - '0')) / 10 && sign > 0)
			return (-1);
		if (result > (LONG_MAX - (nptr[i] - '0')) / 10 && sign < 0)
			return (0);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

/* #include <stdlib.h>
int	main(int arc, char ** arv)
{
	(void)arc;

	printf("%d\n", ft_atoi(arv[1]));
	printf("%d", atoi(arv[1]));
	return (0);
} */