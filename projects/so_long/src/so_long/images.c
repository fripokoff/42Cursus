/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:58:00 by kpires            #+#    #+#             */
/*   Updated: 2024/07/24 08:58:00 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_imgs_objs(t_settings *settings, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		mlx_destroy_image(settings->mlx_var, settings->imgs[i].obj);
		i++;
	}
}

static void	set_img_name(t_settings *settings, char **imgs_name, int i)
{
	int	fd;

	fd = open(imgs_name[i], O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		settings->imgs[i].name = imgs_name[i];
	}
	else
	{
		ft_free(imgs_name);
		free_imgs_objs(settings, i);
		free(settings->imgs);
		free_game(settings, true, false, true);
		exit_error("Opening or read-right issue with a .xpm image");
	}
}

static void	set_img_obj(t_settings *settings, char **imgs_name, int i)
{
	t_pos	size;

	settings->imgs[i].obj = mlx_xpm_file_to_image(settings->mlx_var,
			settings->imgs[i].name, &(size.x), &(size.y));
	if (settings->imgs[i].obj == NULL)
	{
		ft_free(imgs_name);
		free_imgs_objs(settings, i);
		free(settings->imgs);
		free_game(settings, true, false, true);
		exit_error("Malloc issue during an img creation from an .xpm file");
	}
}

static void	set_imgs(t_settings *settings, char **imgs_name)
{
	int	i;
	int	len;

	i = -1;
	while (++i < settings->imgs_count)
	{
		len = ft_strlen(imgs_name[i]);
		if (len < 5 || ft_strncmp(imgs_name[i] + len - 4, ".xmp", len) != EOT)
		{
			ft_free(imgs_name);
			free_imgs_objs(settings, i);
			free(settings->imgs);
			free_game(settings, true, false, true);
			exit_error("A sprites's img does't end up with .xpm extention");
		}
		set_img_name(settings, imgs_name, i);
		set_img_obj(settings, imgs_name, i);
	}
}

void	init_images(t_settings *settings)
{
	char	**imgs_name;

	imgs_name = ft_split(IMGS, ' ');
	if (imgs_name == NULL)
	{
		free_game(settings, true, false, true);
		exit_error("Malloc issue during set_images from env var IMGS");
	}
	settings->imgs_count = 0;
	while (imgs_name[settings->imgs_count])
		settings->imgs_count++;
	settings->imgs = (t_image *)malloc(sizeof(t_image)
			* (settings->imgs_count + 1));
	if (settings->imgs == NULL)
	{
		ft_free(imgs_name);
		free_game(settings, true, false, true);
		exit_error("Malloc issue");
	}
	set_imgs(settings, imgs_name);
	free(imgs_name);
}
