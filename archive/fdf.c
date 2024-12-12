/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 15:24:33 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aff_map(t_setup stp, t_point **map)
{
	int x;
	int	y;
	int	color;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			if (*(map[y][x].z) > 0)
				color = 0x00FF0000;
			else
				color = 0x0000FFFF;
			mlx_pixel_put(stp.mlx, stp.win, (map[y][x].x * stp.scale + stp.shift), (map[y][x].y * stp.scale + stp.shift), color);
			x++;
		}
		y++;
	}
}

void	clear_all(t_point **map)
{
	int x;
	int y;

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
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
		dst = img->img.ptr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		i = img->bpp - 8;
        while (i >= 0)
        {
            if (img->endian == 0)
                *pixel++ = (color >> i) & 0xFF;
            else
                *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
            i -= 8;
        }
		// *(unsigned int*)dst = color;
	}
	
}

int	main(int arc, char **arv)
{
	
	t_setup	stp;
	int		width;
	int		heigth;
	t_img	img;

	if (arc != 2)
		return (1);

	width = 1920;
	heigth = 1080;
	stp.mlx = mlx_init();
	stp.win = mlx_new_window(stp.mlx, width, heigth, "Fdf");
	stp.scale = 30;
	stp.shift = 300;
	stp.h_z = 5;

	// img.img_ptr = mlx_new_image(mlx, width, heigth);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	stp.map = ft_parse_map(arv[1]);
	// print_map(stp.map);
	// printf("\n");

	set_map_iso(stp, stp.map);
	// print_map(stp.map);
	// printf("\n");
	
	// aff_map(stp, stp.map);
	draw_grid(stp, stp.map);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_hook(stp.win, 2, 1L<<0, close_esc, &stp);
	mlx_hook(stp.win, 17, 0L, close_cross, &stp);

	mlx_loop(stp.mlx);
	clear_all(stp.map);
	return (0);
}