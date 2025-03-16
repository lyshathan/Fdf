/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:46:12 by lthan             #+#    #+#             */
/*   Updated: 2024/12/16 15:14:52 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_esc(int keycode, t_setup *stp)
{
	if (keycode == ESC_KEY)
	{
		clear_ending(*stp);
		exit(0);
	}
	return (0);
}

int	close_cross(t_setup *stp)
{
	clear_ending(*stp);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_setup *stp)
{
	if (keycode == UP)
		stp->shift_y -= 100;
	if (keycode == DOWN)
		stp->shift_y += 100;
	if (keycode == LEFT)
		stp->shift_x -= 100;
	if (keycode == RIGHT)
		stp->shift_x += 100;
	else if (keycode == ROTATION)
	{
		stp->angle -= 0.1;
		set_map_iso(*stp, stp->map);
	}
	else if (keycode == PLUS)
	{
		stp->h_z = stp->h_z / 1.05;
		set_map_iso(*stp, stp->map);
	}
	else if (keycode == MINUS)
	{
		stp->h_z = stp->h_z * 1.05;
		set_map_iso(*stp, stp->map);
	}
	print_image(stp);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_setup *stp)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		stp->scale = stp->scale + 1;
		print_image(stp);
	}
	else if (button == 5)
	{
		stp->scale = stp->scale - 1;
		print_image(stp);
	}
	return (0);
}
