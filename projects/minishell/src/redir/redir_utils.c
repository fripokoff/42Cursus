/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:02:53 by kpires            #+#    #+#             */
/*   Updated: 2025/01/11 23:06:32 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_fname_len(char *redir, char *dels)
{
	int		i;
	char	q;
	int		real_len;

	i = skip_chars(redir, " \t");
	q = '\0';
	real_len = 0;
	while (redir[i] && (!is_chr(dels, redir[i])
			|| (is_chr("'\"", q) && redir[i] != q)))
	{
		if (is_chr("'\"", redir[i]) && !q)
			q = redir[i];
		else if (redir[i] == q)
			q = '\0';
		else
			real_len++;
		i++;
	}
	return (real_len);
}

char	*ft_fname(char *redir, int i, int len, char *dels)
{
	char	*file;
	char	q;

	file = ft_calloc(sizeof(char), (count_fname_len(redir, dels) + 1));
	if (!file)
		return (NULL);
	i = skip_chars(redir, " \t") - 1;
	q = '\0';
	while (redir[++i] && (!is_chr(dels, redir[i])
			|| (is_chr("'\"", q) && redir[i] != q)))
	{
		if ((is_chr("'\"", redir[i]) && !q) || redir[i] == q)
		{
			if (redir[i] == q)
				q = '\0';
			else
				q = redir[i];
			continue ;
		}
		file[len++] = redir[i];
	}
	if (!q)
		if (len > 0 && file[len - 1] == ' ')
			len--;
	return (file[len] = '\0', file);
}

void	handl_heredoc(int sig)
{
	g_signal = sig;
	close(STDIN_FILENO);
}
