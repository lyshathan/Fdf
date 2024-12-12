/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:46:12 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 14:54:48 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_esc(int keycode, t_setup *stp)
{
	if (keycode == ESC_KEY || keycode == CLOSE_CROSS)
	{
		mlx_destroy_window(stp->mlx, stp->win);
		clear_all(stp->map);
		exit(0);
	}
	return (0);
}

int	close_cross(t_setup *stp)
{

		mlx_destroy_window(stp->mlx, stp->win);
		clear_all(stp->map);
		exit(0);
	return (0);
}