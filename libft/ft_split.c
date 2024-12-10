/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:48 by lthan             #+#    #+#             */
/*   Updated: 2024/11/12 10:06:13 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char *s, char c)
{
	size_t	nb_word;
	size_t	i;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			nb_word++;
	}
	return (nb_word);
}

char	*ft_strdup_word(char *s, char c, size_t i)
{
	size_t	len;
	size_t	j;
	char	*str;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = i - len;
	j = 0;
	while (j < len)
	{
		str[j] = ((char *)s)[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**free_all(char **tab, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_word;
	size_t	i;
	size_t	k;
	char	**tab;

	nb_word = count_words((char *)s, c);
	tab = malloc ((nb_word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	k = 0;
	i = 0;
	while (k < nb_word)
	{
		while (((char *)s)[i] && ((char *)s)[i] == c)
			i++;
		tab[k] = ft_strdup_word((char *)s, c, i);
		if (!tab[k])
			return (free_all(tab, k));
		while (((char *)s)[i] && ((char *)s)[i] != c)
			i++;
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

/* #include <stdio.h>
int	main(int arc, char **arv)
{
	(void)arc;

	char **tab = ft_split(arv[1], arv[2][0]);
	int k = 0;
	while (tab[k] != NULL)
	{
		printf("%d --> #%s#\n", k, tab[k]);
		k++;
	}
	return (0);
} */