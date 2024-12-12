/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:48 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 14:29:06 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	count_words(char *s, char *charset)
{
	size_t	nb_word;
	size_t	i;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] && is_charset(s[i], charset))
			i++;
		while (s[i] && !is_charset(s[i], charset))
			i++;
		if (!is_charset(s[i - 1], charset))
			nb_word++;
	}
	return (nb_word);
}

char	*ft_strdup_word(char *s, char *charset, size_t i)
{
	size_t	len;
	size_t	j;
	char	*str;

	len = 0;
	while (s[i] && !is_charset(s[i], charset))
	{
		len++;
		i++;
	}
	str = malloc ((len + 1) * sizeof(char));
	// printf(RED"Mem alloc at %p(strdup_word)\n"RESET, str);
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

char	**free_split(char **tab, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(tab[i]);
		// printf(GREEN"Free alloc at %p(free_split)\n"RESET, tab[i]);
		i++;
	}
	free(tab);
	// printf(GREEN"Free alloc at %p(free_split)\n"RESET, tab);
	tab = NULL;
	return (tab);
}

char	**ft_split_set(char const *s, char *charset)
{
	size_t	nb_word;
	size_t	i;
	size_t	k;
	char	**tab;

	nb_word = count_words((char *)s, charset);
	tab = malloc ((nb_word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	k = 0;
	i = 0;
	while (k < nb_word)
	{
		while (((char *)s)[i] && is_charset(s[i], charset))
			i++;
		tab[k] = ft_strdup_word((char *)s, charset, i);
		if (!tab[k])
			return (free_split(tab, k));
		while (((char *)s)[i] && !is_charset(s[i], charset))
			i++;
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

// #include <stdio.h>
// int	main(int arc, char **arv)
// {
// 	(void)arc;

// 	char **tab = ft_split_set(arv[1], arv[2]);
// 	int k = 0;
// 	while (tab[k] != NULL)
// 	{
// 		printf("%d --> #%s#\n", k, tab[k]);
// 		k++;
// 	}
// 	return (0);
// }