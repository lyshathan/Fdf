/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:00:25 by lthan             #+#    #+#             */
/*   Updated: 2024/11/12 13:53:06 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if ((size != 0 && nmemb > SIZE_MAX / size)
		|| (nmemb != 0 && size > SIZE_MAX / nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <stdio.h>
int	main(int arc, char **arv)
{
	(void)arc;
	
	char *tab;
	tab = ft_calloc(atoi(arv[1]), atoi(arv[2]));

	int i = 0;
	while (i < atoi(arv[1]))
	{
		printf("%p --> #%c#\n", &tab[i], ((char *)tab)[i]);
		i++;
	}
	return 0;
} */