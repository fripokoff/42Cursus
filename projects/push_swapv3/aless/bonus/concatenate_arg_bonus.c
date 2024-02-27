/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_arg_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:37:54 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 15:48:48 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	ft_strlen_p(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)

{
	while (*src)
		*dest++ = *src++;
	*dest = ' ';
	return (dest);
}

char	*concatenate_arg(char **argv, int argc, t_stack_node **a)
{
	int		i;
	size_t	len;
	size_t	current_index;
	char	*combined_arg;

	i = 0;
	len = 0;
	while (++i < argc)
		len = len + (ft_strlen_p(argv[i]) + 1);
	combined_arg = (char *)malloc(sizeof(char) * len + 1);
	if (combined_arg == NULL)
		return (NULL);
	current_index = 0;
	i = 0;
	while (++i < argc)
	{
		if (only_space(argv[i]))
			return (free_errors_conc(a, combined_arg), NULL);
		ft_strcpy(combined_arg + current_index, argv[i]);
		current_index += (ft_strlen_p(argv[i]) + 1);
	}
	combined_arg[current_index] = '\0';
	return (combined_arg);
}
