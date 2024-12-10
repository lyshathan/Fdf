/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/10 16:04:17 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_line(char *filename)
{
	char	*line;
	int		fd;
	int		count;
	
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		exit(1);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		if (line)
		{
			free(line);
			line = NULL;
		}
		count++;
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

t_point *ft_parse_line(int fd, int y)
{
	char	*line;
	char	**split;
	int		i;
	t_point	*parse_line;
	
	line = get_next_line(fd);
	split = ft_split_set(line, " \n");
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	parse_line = ft_calloc((i + 1), sizeof(t_point));
	if (!parse_line)
		return (NULL);
	i = 0;
	while (split[i])
	{
		parse_line[i].x = i;
		parse_line[i].y = y;
		parse_line[i].z = malloc(sizeof(int));
		if (!parse_line[i].z)
			return (NULL);
		*(parse_line[i].z) = ft_atoi(split[i]);
		i++;
	}
	return (parse_line);
}

t_point **ft_parse_map(char *filename)
{
	int		count_line;
	int		i;
	int		fd;
	t_point	**map;

	count_line = ft_count_line(filename);
	ft_printf("count line = %d\n", count_line);
	map = ft_calloc((count_line + 1), sizeof(t_point*));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		exit(1);
	while (i < count_line)
	{
		map[i] = ft_parse_line(fd, i);
		i++;
	}
	close(fd);
	print_map(map);
	return (map);
}

int	main(int arc, char **arv)
{
	if (arc != 2)
		return (1);
	ft_parse_map(arv[1]);
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
}