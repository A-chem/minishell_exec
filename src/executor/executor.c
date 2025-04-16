#include "../../includes/minishell.h"


void exec_builtin(t_simple_cmd **data, t_env *env, char **env_arr)
{
    (void)env_arr;
    if(!ft_strcmp((*data)->args[0],"echo"))
        builtin_echo(data);
    else if(!ft_strcmp((*data)->args[0],"env"))
        builtin_env(data, env);
    else if(!ft_strcmp((*data)->args[0],"cd"))
        builtin_cd(data, env);
    else if(!ft_strcmp((*data)->args[0],"pwd"))
        builtin_pwd();
    else if(!ft_strcmp((*data)->args[0], "export"))
        builtin_export(data, env);
    else if(!ft_strcmp((*data)->args[0], "exit"))
        builtin_exit(data);
    else if(!ft_strcmp((*data)->args[0], "unset"))
        builtin_unset(data, env);
}
int is_builtin(char *cmd)
{
    return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "cd")
            ||!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "exit")
            ||!ft_strcmp(cmd, "unset"));
}
void single_cmd(t_simple_cmd **data, t_env *env, char **env_arr)
{
   if(is_builtin((*data)->args[0]))
       exec_builtin(data, env, env_arr);
   else
       exec_cmd(data, env_arr);
}
void exec(t_cmd_table *data, t_env *env)
{
    char **env_arr;
    

    env_arr = env_list_to_array(env);
    if(!env_arr)
         return ;
    if(data->cmd_count == 1)
        single_cmd(data->cmds, env, env_arr);
}