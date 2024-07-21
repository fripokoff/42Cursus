/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:40:44 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 01:33:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_img_keyword(char letter)
{
	if (letter == '1')
		return ("wall");
	if (letter == '0')
		return ("empty");
	if (letter == 'E')
		return ("exit");
	if (letter == 'C')
		return ("coin");
	if (letter == 'G')
		return ("ghost");
	else
		return ("pac_closed");
}

void	*get_img_obj(t_game *game, char *keyword)
{
	int	i;
	int	img_name_len;

	i = 0;
	while (i < game->imgs_nb)
	{
		img_name_len = ft_strlen(game->imgs[i].name);
		if (ft_strnstr(game->imgs[i].name, keyword, img_name_len) != NULL)
			return (game->imgs[i].obj);
		i++;
	}
	do_free_game(game, TRUE, TRUE, TRUE);
	ft_printf("Error\nThe %s img is missing in the sprites folder\n", keyword);
	exit(EXIT_FAILURE);
}

void	put_map(t_game *game)
{
	t_coords	i;

	put_move(game, game->moves_nb, 0);
	i.y = 0;
	while (game->map[i.y])
	{
		i.x = 0;
		while (game->map[i.y][i.x])
		{
			mlx_put_image_to_window(game->mlxvar, game->win,
				get_img_obj(game, get_img_keyword(game->map[i.y][i.x])),
				i.x * 32, i.y * 32);
			i.x++;
		}
		i.y++;
	}
}
