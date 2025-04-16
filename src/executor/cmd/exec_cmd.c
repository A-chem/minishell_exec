#include "../../../includes/minishell.h"

void exec_cmd(t_simple_cmd **data, char **env_arr)
{
    (void)env_arr;
    
    // pid_t pid;
    // int status;

    // if (!(*data)->args || !(*data)->args[0])
    //     return;

    // pid = fork();
    // if (pid == -1)
    // {
    //     perror("minishell: fork");
    //     return;
    // }

    // if (pid == 0)
    // {
    //     if (check_exec_cmd(((*data)->args[1], env_arr) == -1)
    //         exit (1);
    // }
    // else
    //     waitpid(pid, &status, 0);
}