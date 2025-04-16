#include "./includes/minishell.h"
#include <stdio.h>

int	sigcode = 0;

void print_cmd_table(t_cmd_table *cmd_table)
{
    int i;
    int j;
    t_redirection *redir;

    if (!cmd_table)
    {
        printf("here Command table is NULL\n");
        return;
    }
    
    printf("Command Table:\n");
    
    if (cmd_table->cmd_count == 0)
    {
        printf(" here No commands in table\n");
        return;
    }
    
    i = 0;
    while (i < cmd_table->cmd_count)
    {
        printf("Command %d:\n", i + 1);
        
        if (!cmd_table->cmds[i])
        {
            printf("  Command is NULL\n");
            i++;
            continue;
        }
        
        // Print arguments
        printf("  Arguments: ");
        if (cmd_table->cmds[i]->argc == 0 || !cmd_table->cmds[i]->args)
        {
            printf("None\n");
        }
        else
        {
            j = 0;
            while (j < cmd_table->cmds[i]->argc)
            {
                if (j > 0)
                    printf(" ");
                printf("'%s'", cmd_table->cmds[i]->args[j]);
                j++;
            }
            printf("\n");
        }
        
        // Print redirections
        printf("  Redirections: ");
        if (!cmd_table->cmds[i]->redirs)
        {
            printf("None\n");
        }
        else
        {
            printf("\n");
            
            redir = cmd_table->cmds[i]->redirs;
            while (redir)
            {
                printf("    ");
                
                // Print redirection type
                if (redir->type == REDIR_IN)
                    printf("< ");
                else if (redir->type == REDIR_OUT)
                    printf("> ");
                else if (redir->type == REDIR_APPEND)
                    printf(">> ");
                else if (redir->type == REDIR_HEREDOC)
                    printf("<< ");
                
                // Print file or delimiter
                if (!redir)
                {
                    printf("Redirection node is NULL\n");
                     return;
                }

                if (redir->file_or_delimiter)
                    printf("%s\n", redir->file_or_delimiter);
                else
                    printf("(NULL)\n");  // To debug i                
                redir = redir->next;
            }
        }
        
        i++;
    }
}
void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		sigcode = SIGINT;
	}
}

int main(int argc, char **argv, char **envp)
{
	char		*cmd;
	t_token		*token_head;
	t_cmd_table	*cmd_table;
    t_env   *env;
    
    (void)argc;
    (void)argv;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
    env = init_env_list(envp);
    handle_shlvl(&env);
    init_pwd(&env);
	while (1337)
	{
        cmd = readline("minishell$ ");
		if (!cmd || !*cmd)
			return (free(cmd), rl_clear_history(), 0);
		if (ft_strlen(cmd) == 1 && cmd[0] == 4)
			return (0);
		add_history(cmd);
		// if (!syntax_error(cmd))
		// {
		// 	free(cmd);
		// 	continue ;
		// }
		token_head = tokenize(cmd);
		if (!token_head)
			return (free(cmd), rl_clear_history(), 1);
		//print_token_list(token_head);
		cmd_table = parse(token_head);
		if (!cmd_table)
			return (free(cmd), rl_clear_history(), \
			ft_token_lstclear(&token_head, free), 1);
		//print_cmd_table(cmd_table);
        exec(cmd_table, env);
		free(cmd);
		ft_token_lstclear(&token_head, free);
		free_table(cmd_table);
		token_head = NULL;
		cmd_table = NULL;
        
	}
}
