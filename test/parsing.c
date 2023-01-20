/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:44:03 by monabid           #+#    #+#             */
/*   Updated: 2023/01/19 13:38:44 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_char(unsigned int c, char *s)
{
	c = 0;
	if (*s ==  '\f' || *s ==  '\r' || *s ==  '\v'
		|| *s ==  '\n' || *s ==  '\t' || *s == ' ')
	{
		*s = ' ';
	}
}

void	print_linked(t_list *lst)
{
	while (lst)
	{
		printf("%s			(is_next_space %i)\n", lst->content, lst->next_is_space);
		lst = lst->next;
	}
}

void	tests(t_list *lst)
{
	execve(lst->content, (char * const *)lst->next->content, NULL);
}

void	handle_line(char *line)
{
	char	**split;
	t_list	*lst;

	ft_striteri(line, change_char);
	split = ft_split(line, ' ');
	if (split == NULL)
		exit (1);
	lst = split_by_special_char(split);
	group_symbols(&lst);
	replace_env(&lst);
	tests(lst);
	//print_linked(lst);
	ft_lstclear(&lst, free);
}
