/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:49:49 by kpires            #+#    #+#             */
/*   Updated: 2025/01/10 11:50:09 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (n < len)
		len = n;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, src, len);
	dup[len] = '\0';
	return (dup);
}
