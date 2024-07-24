/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:42 by kpires            #+#    #+#             */
/*   Updated: 2024/07/23 17:54:42 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_settings *settings)
{
	settings->mlx_var = mlx_init();
	if (settings->mlx_var == NULL)
	{
		ft_free(settings->map);
		exit_error("Mlx init issue");
	}
	settings->window = mlx_new_window(settings->mlx_var,
			settings->map_size.x * SPRITES_SIZE,
			settings->map_size.y * SPRITES_SIZE, GAME_NAME);
	if (settings->window == NULL)
	{
		mlx_destroy_display(settings->mlx_var);
		free(settings->mlx_var);
		ft_free(settings->map);
		exit_error("Window issue");
	}
}
