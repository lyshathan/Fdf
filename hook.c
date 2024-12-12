/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:46:12 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 15:46:32 by lthan            ###   ########.fr       */
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