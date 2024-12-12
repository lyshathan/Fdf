/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:47:40 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 14:29:25 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	*ft_free(void *data)
{
	if (data)
		free(data);
	data = NULL;
	return(NULL);
}

int	ft_find_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_base_hexa(char *hexa)
{
	char	*base;
	int		result;
	int		i;
	
	i = 0;
	base = "0123456789abcdef";
	while (hexa[i])
	{
		if (ft_find_char(hexa[i], "ABCDEF") >= 0)
		{
			base = "0123456789ABCDEF";
			break;
		}
		i++;
	}
	result = 0;
	i = 0;
	while (hexa[i])
	{
		result = result * 16 + ft_find_char(hexa[i], base);
		i++;
	}
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("nb = %d\n", ft_convert_base_hexa("FF00FF"));
// 	return (0);
// }