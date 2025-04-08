#include "../../includes/minishell.h"

void exec_builtin(t_simple_cmd **data, t_env *env)
{
    if(!ft_strcmp((*data)->args[0],"echo"))
        builtin_echo(data);
    else if(!ft_strcmp((*data)->args[0],"env"))
        builtin_env(env);
}
int is_builtin(char *cmd)
{
    return (!strcmp(cmd, "echo") || !strcmp(cmd, "env"));
}
void single_cmd(t_simple_cmd **data, t_env *env)
{
   if(is_builtin((*data)->args[0]))
       exec_builtin(data, env);
}
void exec(t_cmd_table *data, t_env *env_list)
{
    char env;

    if(data->cmd_count == 1)
        single_cmd(data->cmds, env);
}