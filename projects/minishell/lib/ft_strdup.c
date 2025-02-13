/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:23:16 by redrouic          #+#    #+#             */
/*   Updated: 2024/12/23 22:46:49 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	if (!src)
		return (NULL);
	dup = ft_calloc(ft_strlen(src) + 1, 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, ft_strlen(src) + 1);
	return (dup);
}
