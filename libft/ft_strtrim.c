/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:52:54 by lthan             #+#    #+#             */
/*   Updated: 2024/12/08 16:58:24 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (((char *)s1)[start] && is_set((char *)set, ((char *)s1)[start]) == 1)
		start++;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = ft_strlen((char *)s1);
	while (end == 0 && is_set((char *)set, ((char *)s1)[end - 1]) == 1)
		end--;
	if (start >= end)
		return (ft_calloc(1, sizeof(char)));
	str = malloc ((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (((char *)s1)[start] && start < end)
	{
		str[i] = ((char *)s1)[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

/* #include <stdio.h>
int	main (int arc, char ** arv)
{
	(void)arc;

	printf("|%s|\n", ft_strtrim(arv[1], arv[2]));
	return (0);
} */
