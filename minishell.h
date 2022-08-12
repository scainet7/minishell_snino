/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 22:02:13 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define END "\033[0m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/libft.h"
# include <signal.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_comand
{
	char			**comand;
	int				fd[2];
	struct s_comand	*next;
}	t_cmd;

typedef struct s_minishell
{
	t_list			*words_list;
	t_cmd 			*cmd;

	int				exit_flag;
	char			*line;
}		t_mini;

t_cmd	*ft_cmd_new(void *cmd);
void	free_tcmd(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
int		ft_memory_num(t_list *words_list, char *symbol);

void	add_history(char *line);
void	ft_freelst(t_list *lst);

void	ft_lexer(t_mini *mini);
void 	*ft_lex_quotes(t_mini *mini, char *line);
char	*ft_pars_words(t_mini *mini, char *line);
char	*ft_pars_quotes2(t_mini *mini, char *line);
char	*ft_pars_quotes(t_mini *mini, char *line);
char	*ft_pars_pipe(t_mini *mini, char *line);
char	*ft_pars_there(t_mini *mini, char *line);
char	*ft_pars_here(t_mini *mini, char *line);
char	*ft_pars_and(t_mini *mini, char *line);
char	*ft_pars_star(t_mini *mini, char *line);
int		ft_check_symbol(char *line);


void	ft_parser(t_mini *mini);
void	ft_parser2(t_mini *mini);

void 	SHOW(t_mini *mini, char *place);
void	SHOW1(t_cmd *cmd, char *place);
void	SHOW2(t_list *list, char *place);
#endif