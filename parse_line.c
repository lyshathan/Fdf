/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:02:19 by lthan             #+#    #+#             */
/*   Updated: 2024/12/17 08:36:05 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_point(char *s, int index, int y, t_point *parse)
{
	parse[index].x = index;
	parse[index].y = y;
	parse[index].z = malloc(sizeof(int));
	if (!parse[index].z)
		return (0);
	*(parse[index].z) = ft_atoi(s);
	if (*s == '-')
		s++;
	while ((*s >= '0' && *s <= '9') || *s == ',')
		s++;
	if (*s == 'x')
		s++;
	parse[index].col = ft_convert_base_hexa(s);
	return (1);
}

void	*free_parse_line(char **split, int len, t_point *parse_line, int i)
{
	int	k;

	free_split(split, len);
	if (parse_line)
	{
		k = 0;
		while (k < i)
		{
			free(parse_line[k].z);
			parse_line[k].z = NULL;
			k++;
		}
		ft_free(parse_line);
	}
	return (NULL);
}

t_point	*allocate_parse_line(char **split, char *line, int *len)
{
	t_point	*parse_line;

	*len = 0;
	while (split[*len])
		(*len)++;
	parse_line = ft_calloc((*len + 1), sizeof(t_point));
	if (!parse_line)
	{
		ft_free(line);
		free_parse_line(split, *len, NULL, 0);
		return (NULL);
	}
	return (parse_line);
}

int	fill_parse_line(char **split, int y, t_point *parse_line)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!set_point(split[i], i, y, parse_line))
		{
			free_parse_line(split, i, parse_line, i);
			return (i);
		}
		i++;
	}
	return (-1);
}

t_point	*ft_parse_line(int fd, int y)
{
	char	*line;
	char	**split;
	int		len;
	t_point	*parse_line;
	int		error_index;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	split = ft_split_set(line, " \n");
	if (!split)
		return (ft_free(line));
	parse_line = allocate_parse_line(split, line, &len);
	if (!parse_line)
		return (NULL);
	error_index = fill_parse_line(split, y, parse_line);
	if (error_index != -1)
	{
		ft_free(line);
		return (free_parse_line(split, len, parse_line, error_index));
	}
	ft_free(line);
	free_split(split, len);
	return (parse_line);
}
