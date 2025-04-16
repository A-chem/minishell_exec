#include "../../includes/minishell.h"

void update_shlvl(t_env **env, char *key, char *value)
{
    t_env *curr;

    curr = *env;
    while(curr)
    {
        if(ft_strcmp(curr->key, key) == 0)
        {
            curr->value = value;
            return ;
        }
        curr = curr->next;
    }
}

int is_valid_number(char *str)
{
    if (!str || !*str)
        return 0;

    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
void handle_shlvl(t_env **env)
{
    t_env *new_node;
    char *shlvl_str;
    char *new_shlvl;
    int shlvl;

    shlvl = 0;
    shlvl_str = ft_getenv(*env, "SHLVL=");
    
    if (shlvl_str)
    {
        if(!is_valid_number(shlvl_str))
             new_shlvl = "1";
        else
        {
            shlvl = ft_atoi(shlvl_str);
            shlvl++;
            if (shlvl < 0)
                shlvl = 0;
            if (shlvl > 999)
            {
                printf("warning: shell level (1000) too high, resetting to 1\n");
                shlvl = 1;
            }
            new_shlvl = ft_itoa(shlvl);
            update_shlvl(env, "SHLVL=", new_shlvl);
        }
    }
    else
    {
        new_shlvl = "1";
        new_node = create_env_node("SHLVL=", new_shlvl);
        add_node(env, new_node);
    }
}

