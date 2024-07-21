/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:09:41 by kpires            #+#    #+#             */
/*   Updated: 2024/07/20 11:09:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int ac, char **av)
{
	t_settings	settings;

	if(ac == 2)
	{
		settings.map = get_map_by_file(av[1]);
	}
	(void)settings;
	return (0);
}