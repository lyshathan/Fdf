/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/15 20:44:41 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*clear_all(t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			free(map[y][x].z);
			x++;
		}
		ft_free(map[y]);
		y++;
	}
	ft_free(map);
	return (NULL);
}

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

void	print_image(t_img *img, t_setup *stp)
{
	img->width = stp->width;
	img->height = stp->height;
	img->img_ptr = mlx_new_image(stp->mlx, img->width, img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size_line, &img->endian);
	draw_grid(img, *stp, stp->map);
	mlx_put_image_to_window(stp->mlx, stp->win, img->img_ptr, 0, 0);
	mlx_destroy_image(stp->mlx, img->img_ptr);
}

void	fdf(char **arv)
{
	t_setup		stp;
	t_map_info	map_info;
	t_img		img;

	stp.width = WIDTH;
	stp.height = HEIGHT;
	if (arv[2])
	{
		// ft_printf("arv 2");
		stp.width = ft_atoi(arv[2]);
	}
	if (arv[3])
	{
		// ft_printf("arv 3");
		stp.height = ft_atoi(arv[3]);
	}
	stp.mlx = mlx_init();
	stp.win = mlx_new_window(stp.mlx, stp.width, stp.height, "Fdf");
	stp.map = ft_parse_map(arv[1]);

	stp.h_z = find_average_gap(stp.map);

	// stp.h_z = 10;

	printf("hz = %f\n", stp.h_z);


	set_map_iso(stp, stp.map);
	// print_map(stp.map);

	set_map_info(stp.map, &map_info);
	find_scale(map_info, &stp);
	print_image(&img, &stp);
	mlx_hook(stp.win, 2, 1L << 0, close_esc, &stp);
	mlx_hook(stp.win, 17, 0L, close_cross, &stp);
	mlx_loop(stp.mlx);
	clear_all(stp.map);
}

int	main(int arc, char **arv)
{
	if (arc < 2 || arc > 4)
		return (1);
	fdf(arv);
	return (0);
}
