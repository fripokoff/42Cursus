/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:44:33 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:22:48 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower( int c )
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int	main()
{
	char	upthis;

	upthis = '$';
	upthis = ft_tolower(upthis);
	printf("Upped : %s\n" , &upthis);
        return (0);
}
*/