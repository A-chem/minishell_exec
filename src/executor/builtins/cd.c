
#include  "../../../includes/minishell.h"


void builtin_cd(t_simple_cmd **data, t_env *env)
{
    char *oldpwd;
    char cwd[1024];
    (void)env;
    
    if((*data)->args[1] && (*data)->args[2])
    return(ft_putstr_fd("cd: too many arguments\n", 2));
    
    if(!getcwd(cwd, sizeof(cwd)))
    return(ft_putstr_fd("cd: getcwd", 2));
    getcwd(cwd, ft_strlen(cwd));
    oldpwd = cwd;
    if(!oldpwd)
        return ;
    if(!(*data)->args[1])
    {
        if(chdir(getenv("HOME")) == -1)
            return(ft_putstr_fd("cd: HOME not set\n", 2));
    }
    else
    {
        if(chdir((*data)->args[1]) == -1)
            return ;
    }    
}



