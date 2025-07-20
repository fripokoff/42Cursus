/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:46:00 by redrouic          #+#    #+#             */
/*   Updated: 2025/07/15 18:31:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_extension(char *filename)
{
	char	*ext;
	int		size;
	int		i;

	i = 0;
	ext = ".cub";
	size = ft_strlen(filename);
	if (size < 5)
		return (false);
	size -= 4;
	while (i < 4)
	{
		if (ext[i] != filename[size + i])
			return (false);
		i++;
	}
	return (true);
}

#ifndef ERR_MSG_H
# define ERR_MSG_H

# define EXT	"Only [.cub] files are expected"
# define OPEN	"The file failed to open :"
# define READ	"The file failed to read :"

int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_perror(OPEN, path), fd);
	return (fd);
}

char	*get_buff(int fd, char *file)
{
	char	*buff;
	char	tmp;
	int		bread;
	size_t	sizeb;

	sizeb = 0;
	buff = NULL;
	while (1)
	{
		bread = read(fd, &tmp, 1);
		if (bread == -1)
			return (ft_perror(READ, file), free(buff), close(fd), NULL);
		if (bread == 0)
			break ;
		buff = ft_realloc(buff, sizeb, sizeb + 2);
		if (!buff)
			return (ft_perror(ALLOC, NULL), free(buff), close(fd), NULL);
		buff[sizeb++] = tmp;
	}
	close(fd);
	if (buff)
		buff[sizeb] = '\0';
	if (!buff)
		return (ft_perror(OPEN, file), free(buff), NULL);
	return (buff);
}

int	parsing(char **av, t_game *game)
{
	char	*map;
	int		fd;

	if (!valid_extension(av[1]))
		return (ft_perror(EXT, NULL), EXIT_FAILURE);
	fd = open_file(av[1]);
	if (fd == -1)
		(exit_game(game, 1));
	map = get_buff(fd, av[1]);
	if (map == NULL)
		exit_game(game, EXIT_FAILURE);
	if (is_error(map, game))
		(free(map), exit_game(game, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

#endif
