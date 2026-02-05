/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:10:35 by kpires            #+#    #+#             */
/*   Updated: 2024/07/21 13:10:35 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg, bool do_free, char *s_char, char **d_char)
{
	if (do_free)
	{
		if (s_char)
			free(s_char);
		if (d_char)
			ft_free(d_char);
	}
	printf("Error \n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_game(t_settings *settings, bool f_mlx, bool f_imgs, bool f_map)
{
	int	i;

	if (f_map)
		ft_free(settings->map);
	if (f_imgs)
	{
		i = 0;
		while (i < settings->imgs_count)
		{
			free(settings->imgs[i].name);
			mlx_destroy_image(settings->mlx_var, settings->imgs[i].obj);
			i++;
		}
		free(settings->imgs);
	}
	if (f_mlx)
	{
		mlx_destroy_window(settings->mlx_var, settings->window);
		mlx_destroy_display(settings->mlx_var);
		free(settings->mlx_var);
	}
}
