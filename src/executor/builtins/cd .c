
#include  "../../../includes/minishell.h"


void builtin_cd(t_simple_cmd **data, t_env *env)
{
    char *target;
    char *oldpwd;
    char *cwd;

    // Get current directory before changing
    cwd = current_cwd(env);
    // Save old directory
    oldpwd = ft_strdup(cwd);
    // Determine target path
    if(!(*data)->args[1] || !ft_strcmp((*data)->args[1], "~"))
    {
        target = getenv("HOME");
        if (!target)
        {
            ft_putstr_fd("cd: HOME not set\n", 2);
            return ;
        }
    }

}