/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/11 17:29:30 by lthan            ###   ########.fr       */
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
	parse[index].color = ft_strdup(s);
	if (!*parse[index].color)
		parse[index].color = NULL;
	return (1);
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
		if (!set_point(split[i], i, y, parse_line))
			return (NULL);
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
	// ft_printf("count line = %d\n", count_line);
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
	// print_map(map);
	return (map);
}
void	print_square(void *mlx, void *mlx_win, int x, int y, int size, int color)
{
	int	sq_x;
	int	sq_y;

	sq_y = 0;
	while (sq_y < size)
	{
		sq_x = 0;
		while (sq_x < size)
		{
			mlx_pixel_put(mlx, mlx_win, (sq_x + x), (sq_y + y), color);
			sq_x++;
		}
		sq_y++;
	}
	
}

void	aff_map(void *mlx, void *mlx_win, t_point **map)
{
	int x;
	int	y;
	int	color;
	int	shift;

	shift = 250;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			map[y][x].x = iso_x(map[y][x], x, y);
			map[y][x].y = iso_y(map[y][x], x, y);
			if (*(map[y][x].z) > 0)
				color = 0x00FF0000;
			else
				color = 0x0000FFFF;
			// mlx_pixel_put(mlx, mlx_win, (map[y][x].x * 10), (map[y][x].y * 10), color);
			mlx_pixel_put(mlx, mlx_win, (map[y][x].x * 30 + shift), (map[y][x].y * 30 + shift), color);
			ft_printf("%d	", *(map[y][x].z));
			x++;
		}
		ft_printf("\n");
		y++;
	}
	draw_line(mlx, mlx_win, shift, map[5][7], map[10][15]);
}



int	main(int arc, char **arv)
{
	if (arc != 2)
		return (1);
	
	void	*mlx;
	void	*mlx_win;
	t_point	**map;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	map = ft_parse_map(arv[1]);
	aff_map(mlx, mlx_win, map);
	
	mlx_loop(mlx);
	return (0);
}