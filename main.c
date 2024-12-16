/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:41:49 by lthan             #+#    #+#             */
/*   Updated: 2024/12/16 14:48:13 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int arc, char **arv)
{
	if (arc != 2)
	{
		errno = EINVAL;
		perror("Error opening or parsing file");
		return (1);
	}
	if (!fdf(arv))
	{
		errno = EINVAL;
		perror("Error opening or parsing file");
		return (1);
	}
	errno = 0;
	return (0);
}

