/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:30:20 by lthan             #+#    #+#             */
/*   Updated: 2024/11/14 14:01:39 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (((char *)s)[i])
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

/* char	ft_even_upper(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

int	main(int arc, char **arv)
{
	(void)arc;

	printf("%s", ft_strmapi(arv[1], &ft_even_upper));
	return (0);
} */