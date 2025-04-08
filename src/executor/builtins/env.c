#include  "../../../includes/minishell.h"

void builtin_env(t_env *env)
{
    while (env)
    {
        if (env->value)
        {
            ft_putstr_fd(env->key, 1);
            ft_putstr_fd("=", 1);
            ft_putstr_fd(env->value, 1);
            ft_putstr_fd("\n", 1);
        }
        env = env->next;
    }
}