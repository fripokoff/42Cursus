/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:39:39 by kpires            #+#    #+#             */
/*   Updated: 2024/07/23 19:39:39 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_img_keyword(char letter)
{
	if (letter == '1')
		return ("wall");
	if (letter == 'E')
		return ("exit");
	if (letter == 'C')
		return ("potion");
	if (letter == '0')
		return ("floor");
	else
		return ("player");
}

void	*get_img_obj(t_settings *settings, char *keyword)
{
	int	i;
	int	img_name_len;

	i = 0;
	while (i < settings->imgs_count)
	{
		img_name_len = ft_strlen(settings->imgs[i].name);
		if (ft_strnstr(settings->imgs[i].name, keyword, img_name_len) != NULL)
			return (settings->imgs[i].obj);
		i++;
	}
	free_game(settings, true, true, true);
	ft_printf("Error\nThe %s img is missing in the sprites folder\n", keyword);
	exit(EXIT_FAILURE);
}

void	build_map(t_settings *settings)
{
	t_pos	i;

	i.y = 0;
	while (settings->map[i.y])
	{
		i.x = 0;
		while (settings->map[i.y][i.x])
		{
			mlx_put_image_to_window(settings->mlx_var, settings->window,
				get_img_obj(settings, get_img_keyword(settings->map[i.y][i.x])),
				i.x * SPRITES_SIZE, i.y * SPRITES_SIZE);
			if (settings->map[i.y][i.x] == 'E')
				settings->exit_pos = get_pos(i.x, i.y);
			i.x++;
		}
		i.y++;
	}
}
