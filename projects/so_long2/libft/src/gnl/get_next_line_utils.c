/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:56:47 by aautin            #+#    #+#             */
/*   Updated: 2024/01/11 17:18:12 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*string_chr(char *str, char letter)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == letter)
			return (&str[i]);
	}
	return (NULL);
}
