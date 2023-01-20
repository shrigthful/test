/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:57:56 by monabid           #+#    #+#             */
/*   Updated: 2023/01/18 18:54:54 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_list
{
	char			*content;
	int				next_is_space;
	struct s_list	*next;
}	t_list;

typedef struct s_tab_cmd
{
	char	*cmd;
	char	*param;
}	t_tab_cmd;
// strings
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
//linked list
t_list	*ft_lstnew(char *content, int is_space);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
//read line
void	handle_line(char *line);
//parsing step 1
t_list	*split_by_special_char(char **split);
//step 2
void	group_symbols(t_list **lst);
//step 3
char	check_is_symbol(char s);
void	replace_env(t_list **lst);

#endif
