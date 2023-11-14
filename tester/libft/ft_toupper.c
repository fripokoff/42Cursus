/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:44:33 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:22:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper( int c )
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
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
	upthis = ft_toupper(upthis);
	printf("Upped : %s\n" , &upthis);
        return (0);
}
*/