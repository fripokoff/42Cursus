/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:58:06 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/13 02:14:12 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	unset_var(t_env **lenv, char *var)
{
	t_env	*tmp;
	t_env	*to_delete;

	tmp = *lenv;
	if (ft_strcmp(var, (*lenv)->name))
	{
		to_delete = *lenv;
		*lenv = (*lenv)->next;
		ft_free_node(to_delete);
		return ;
	}
	while (tmp && tmp->next)
	{
		if (ft_strcmp(var, tmp->next->name))
		{
			to_delete = tmp->next;
			tmp->next = tmp->next->next;
			ft_free_node(to_delete);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_unset(t_global *g, char **str)
{
	int	i;

	i = 0;
	if (!g->lenv || !str)
		return ;
	g->exit_val = 0;
	while (str[i] != NULL)
	{
		unset_var(&g->lenv, str[i]);
		i++;
	}
}
