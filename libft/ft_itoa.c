/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:46:29 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 13:36:33 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		nb_cpy;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = find_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	nb_cpy = n;
	if (n < 0)
	{
		nb_cpy = -nb_cpy;
		str[0] = '-';
	}
	str[len--] = 0;
	while (nb_cpy > 0)
	{
		str[len--] = nb_cpy % 10 + '0';
		nb_cpy = nb_cpy / 10;
	}
	return (str);
}

/* int	main(int arc, char **arv)
{
	(void)arc;

	printf("%s\n", ft_itoa(atoi(arv[1])));
	return (0);
} */