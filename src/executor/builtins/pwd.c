#include  "../../../includes/minishell.h"

void builtin_pwd()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)))
    {
        ft_putstr_fd(cwd, 1);
        ft_putstr_fd("\n", 1);
    }
    else
        perror("pwd");
}
