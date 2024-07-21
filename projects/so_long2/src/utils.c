/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:52:00 by aautin            #+#    #+#             */
/*   Updated: 2024/01/27 17:17:05 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_msg_exit(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	do_free_game(t_game *game, char freemlx, char freeimgs, char freemap)
{
	int	i;

	if (freemap == TRUE)
		free_stab(game->map);
	if (freeimgs == TRUE)
	{
		i = 0;
		while (i < game->imgs_nb)
		{
			free(game->imgs[i].name);
			mlx_destroy_image(game->mlxvar, game->imgs[i].obj);
			i++;
		}
		free(game->imgs);
	}
	if (freemlx == TRUE)
	{
		mlx_destroy_window(game->mlxvar, game->win);
		mlx_destroy_display(game->mlxvar);
		free(game->mlxvar);
	}
}
