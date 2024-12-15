/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:46:12 by lthan             #+#    #+#             */
/*   Updated: 2024/12/14 14:49:05 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_esc(int keycode, t_setup *stp)
{
	if (keycode == ESC_KEY)
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
