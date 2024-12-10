/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:23:12 by lthan             #+#    #+#             */
/*   Updated: 2024/11/07 16:31:43 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size;
	size_t	i;
	char	*str;

	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	if ((start + len) > s_len)
		size = s_len - start;
	else
		size = len;
	str = malloc ((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (((char *)s)[start] && i < size)
	{
		str[i] = ((char *)s)[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

/* int	main (int arc, char ** arv)
{
	(void)arc;

	printf("%s\n", ft_substr(arv[1], atoi(arv[2]), atoi(arv[3])));
	return (0);
} */