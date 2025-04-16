#include "../../../includes/minishell.h"


void exec_proc(t_simple_cmd **data, char **env_arr)
{
    inf_outf_cmd(data);
    //check_is_buiding();
    if (check_exec_cmd((*data)->args[0], env_arr) == -1)
        return (exit(1));
}

void exec_cmd(t_simple_cmd **data, char **env_arr)
{
    pid_t pid;
    int status;

    if (!(*data)->args || !(*data)->args[0])
        return ;

    pid = fork();
    if (pid == -1)
        return (perror("Error: fork"));

    if (pid == 0)
    {
        exec_proc(data, env_arr);
    }
    else
        waitpid(pid, &status, 0);
}