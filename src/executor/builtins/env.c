#include  "../../../includes/minishell.h"

void builtin_env(t_simple_cmd **data, t_env *env)
{
    if((*data)->args[1])
    {
        printf("env: ‘%s’: No such file or directory\n", (*data)->args[1]);
            return ;
    }
    
    while (env)
    {
        if (env->value)
        {
            printf("%s", env->key);
            printf("%s\n",env->value);
        }
        env = env->next;
    }
}