/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:04:29 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 18:09:02 by lthan            ###   ########.fr       */
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

void put_pixel_to_image(t_img *img, int x, int y, int color)
{
    char *dst;

    // Ensure the pixel coordinates are within the image bounds
    if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
        // Calculate the position of the pixel in the image data
        dst = img->data + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int*)dst = color;

        // // Set the pixel color
        // if (img->endian == 0)
        // {
        //     dst[0] = (color >> 0) & 0xFF;    // Blue
        //     dst[1] = (color >> 8) & 0xFF;    // Green
        //     dst[2] = (color >> 16) & 0xFF;   // Red
        //     if (img->bpp == 32)
        //         dst[3] = (color >> 24) & 0xFF; // Alpha
        // }
        // else
        // {
        //     dst[0] = (color >> 24) & 0xFF;   // Alpha
        //     dst[1] = (color >> 16) & 0xFF;   // Red
        //     dst[2] = (color >> 8) & 0xFF;    // Green
        //     dst[3] = (color >> 0) & 0xFF;    // Blue
        // }
    }
}


int main(int arc, char **arv)
{
    t_setup stp;
    t_img img;

    if (arc != 2)
        return (1);

    stp.width = 1920;
    stp.height = 1080;

    stp.mlx = mlx_init();
    stp.win = mlx_new_window(stp.mlx, stp.width, stp.height, "Fdf");
    // stp.scale = 20;
    stp.shift = 200;
    stp.h_z = 5;
    stp.map = ft_parse_map(arv[1]);

    set_map_iso(stp, stp.map);
	print_map(stp.map);
	find_scale(stp.map, &stp);

	img.width = stp.width;
    img.height = stp.height;
    img.img_ptr = mlx_new_image(stp.mlx, img.width, img.height);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
    

    draw_grid(&img, stp, stp.map);

    mlx_put_image_to_window(stp.mlx, stp.win, img.img_ptr, 0, 0);
    mlx_destroy_image(stp.mlx, img.img_ptr);

    mlx_hook(stp.win, 2, 1L<<0, close_esc, &stp);
    mlx_hook(stp.win, 17, 0L, close_cross, &stp);

    mlx_loop(stp.mlx);
    clear_all(stp.map);
    return (0);
}