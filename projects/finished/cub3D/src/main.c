/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:03:08 by kpires            #+#    #+#             */
/*   Updated: 2025/07/15 14:28:14 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		return (ft_perror(USAGE, NULL), 1);
	if (parsing(av, &game) == EXIT_FAILURE)
		exit_game(&game, EXIT_FAILURE);
	if (check_fov_and_init(&game) == 1)
		exit_game(&game, 1);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
