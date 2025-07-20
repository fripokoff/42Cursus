/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:59:11 by redrouic          #+#    #+#             */
/*   Updated: 2025/01/11 23:59:18 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*create_node(char *str)
{
	t_env	*new;
	int		i;

	if (!str)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	new->name = ft_substr(str, 0, i);
	new->content = ft_substr(str, i + 1, ft_strlen(str));
	new->next = NULL;
	if (!new->name || !new->content)
		return (ft_free_node(new), NULL);
	return (new);
}

static char	**new_env(void)
{
	char	cwd[1024];
	char	**new;

	new = malloc(sizeof(char *) * 4);
	if (!new)
		return (NULL);
	getcwd(cwd, sizeof(cwd));
	new[0] = pwrapper("PWD", cwd, '=');
	new[1] = ft_strdup("_=/usr/bin/env");
	new[2] = ft_strdup("SHLVL=1");
	new[3] = NULL;
	return (new);
}

t_env	*arr2list(char **env)
{
	t_env	*head;
	t_env	*tmp;
	t_env	*result;

	if (!*env)
		env = new_env();
	head = create_node("a=b");
	if (!head)
		return (NULL);
	tmp = head;
	while (*env)
	{
		tmp->next = create_node(*env++);
		if (!tmp->next)
			return (free_list(head), NULL);
		tmp = tmp->next;
	}
	return (result = head->next, ft_free_node(head), (t_env *)result);
}

char	**list2arr(t_env *lenv)
{
	t_env	*tmp;
	char	**arr;
	int		i;

	i = 0;
	tmp = lenv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	tmp = lenv;
	while (tmp)
	{
		arr[i++] = pwrapper(tmp->name, tmp->content, '=');
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}
