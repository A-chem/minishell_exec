#include  "../../../includes/minishell.h"

void builtin_env(t_env *env)
{
    if(!env)
        ft_putstr_fd("not found\n", 2);
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