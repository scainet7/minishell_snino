/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:04:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 19:06:55 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	(void)argc;
	(void)argv;
	(void)envp;

	mini.exit_flag = 1;
	while (mini.exit_flag)
	{
		rl_replace_line("", 0);
		mini.line = readline(MAG"username@minishell "END);
		if (mini.line && *mini.line)
			add_history(mini.line);
		if (mini.line && *mini.line)
		{
			ft_lexer(&mini);
			ft_parser(&mini);
			SHOW(&mini, "main: ");
			SHOW1(mini.cmd, "main: ");
			ft_freelst(mini.words_list);
			free_tcmd(mini.cmd);
		}
		if (!mini.line)
		{
			mini.exit_flag = 0;
			printf("%s"BLU"exit\n"END, MAG"username@minishell "END);
		}
		free(mini.line);
	}
	return (0);
}
