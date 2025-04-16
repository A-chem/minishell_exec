#include  "../../../includes/minishell.h"

void unset_env(char *key, t_env **env)
{
    t_env *prev = NULL;
    t_env *curr = *env;
    char *key_env;

    if(ft_strchr(key, '='))
        return ;
    while (curr) 
    {
        key_env = ft_strtrim(curr->key, "=");
        if (ft_strcmp(key_env, key) == 0) 
        {
            if (prev)
                prev->next = curr->next;
            else
                *env = curr->next;
            return(free(curr->key), free(curr->value),
                        free(curr));
        }
        prev = curr;
        curr = curr->next;
    }
}

void  builtin_unset(t_simple_cmd **data, t_env *env)
{
    int i;
 
    i = 1;
    while((*data)->args[i])
    {
       unset_env((*data)->args[i], &env);
        i++;
    }
}
