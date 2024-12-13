/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:02:19 by lthan             #+#    #+#             */
/*   Updated: 2024/12/13 18:51:26 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_line(char *filename)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		if (*line != '\n')
			count++;
		ft_free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
	return (count);
}

int	set_point(char *s, int index, int y, t_point *parse)
{
	parse[index].x = index;
	parse[index].y = y;
	parse[index].z = malloc(sizeof(int));
	if (!parse[index].z)
		return (0);
	*(parse[index].z) = ft_atoi(s);
	while ((*s >= '0' && *s <= '9') || *s == ',')
		s++;
	if (*s == 'x')
		s++;
	parse[index].col = ft_convert_base_hexa(s);
	return (1);
}

t_point	*ft_parse_line(int fd, int y)
{
	char	*line;
	char	**split;
	int		i;
	int		len;
	t_point	*parse_line;

	line = get_next_line(fd);
	split = ft_split_set(line, " \n");
	if (!split)
	{
		ft_free(line);
		free_split(split, len);
		return (NULL);
	}
	len = 0;
	while (split[len])
		len++;
	parse_line = ft_calloc((len + 1), sizeof(t_point));
	if (!parse_line)
		return (NULL);
	i = 0;
	while (split[i])
	{
		if (!set_point(split[i], i, y, parse_line))
			return ((t_point *)*free_split(split, len));
		i++;
	}
	ft_free(line);
	free_split(split, len);
	return (parse_line);
}

t_point	**ft_parse_map(char *filename)
{
	int		count_line;
	int		i;
	int		fd;
	t_point	**map;

	count_line = ft_count_line(filename);
	map = ft_calloc((count_line + 1), sizeof(t_point *));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit (1);
	while (i < count_line)
	{
		map[i] = ft_parse_line(fd, i);
		if (!map[i])
			return (clear_all(map));
		i++;
	}
	close(fd);
	return (map);
}
