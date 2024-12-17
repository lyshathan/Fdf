/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/17 08:56:01 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->data + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
		if (img->endian == 0)
		{
			dst[0] = (color >> 0) & 0xFF;
			dst[1] = (color >> 8) & 0xFF;
			dst[2] = (color >> 16) & 0xFF;
			if (img->bpp == 32)
				dst[3] = (color >> 24) & 0xFF;
		}
		else
		{
			dst[0] = (color >> 24) & 0xFF;
			dst[1] = (color >> 16) & 0xFF;
			dst[2] = (color >> 8) & 0xFF;
			dst[3] = (color >> 0) & 0xFF;
		}
	}
}

void	print_image(t_setup *stp)
{
	stp->img->width = stp->width;
	stp->img->height = stp->height;
	stp->img->img_ptr
		= mlx_new_image(stp->mlx, stp->img->width, stp->img->height);
	stp->img->data = mlx_get_data_addr(stp->img->img_ptr, &stp->img->bpp,
			&stp->img->size_line, &stp->img->endian);
	draw_grid(stp->img, *stp, stp->map);
	mlx_put_image_to_window(stp->mlx, stp->win, stp->img->img_ptr, 0, 0);
	mlx_destroy_image(stp->mlx, stp->img->img_ptr);
}

void	init_setup(t_setup *stp, t_img *img)
{
	stp->img = img;
	stp->width = WIDTH;
	stp->height = HEIGHT;
	stp->angle = 120;
	stp->h_z = find_average_gap(stp->map);
	set_map_iso(*stp, stp->map);
}

t_point	**ft_parse_map(char *filename)
{
	int		count_line;
	int		i;
	int		fd;
	t_point	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count_line = ft_count_line(filename);
	if (count_line == 0)
		return (NULL);
	map = ft_calloc((count_line + 1), sizeof(t_point *));
	if (!map)
		return (NULL);
	i = 0;
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

void	print_map(t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			// printf("%f|", map[y][x].y);
			// printf("%f	", map[y][x].x);
			// ft_printf("%d	", *(map[y][x].z));
			ft_printf("%d	", map[y][x].col);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}


int	fdf(char **arv)
{
	t_setup		stp;
	t_map_info	map_info;
	t_img		img;

	stp.map = ft_parse_map(arv[1]);
	if (!stp.map)
		return (0);
	// print_map(stp.map);
	init_setup(&stp, &img);
	stp.mlx = mlx_init();
	stp.win = mlx_new_window(stp.mlx, stp.width, stp.height, "Fdf");
	if (!stp.mlx || !stp.win)
	{
		return (clear_ending(stp));
	}
	set_map_info(stp.map, &map_info);
	find_scale(map_info, &stp);
	print_image(&stp);
	mlx_hook(stp.win, 2, 1L << 0, close_esc, &stp);
	mlx_hook(stp.win, 17, 0L, close_cross, &stp);
	mlx_key_hook(stp.win, key_hook, &stp);
	mlx_mouse_hook(stp.win, mouse_zoom, &stp);
	mlx_loop(stp.mlx);
	clear_ending(stp);
	return (1);
}
