#include "../../includes/minishell.h"

t_env *create_env_node(char *env_str)
{
    t_env *node;
    char *equal_sign;

    node = malloc(sizeof(t_env));
    equal_sign = ft_strchr(env_str, '=');

    node->key = ft_substr(env_str, 0, equal_sign - env_str);
    node->value = ft_strdup(equal_sign + 1);
    node->next = NULL;
    return node;
}

t_env *init_env_list(char **envp)
{
    t_env *head;
    t_env *new_node;
    t_env *current;
    int i;

    head = NULL;
    current = NULL;
    new_node = NULL;
    i = 0;
    while(envp[i])
    {
        new_node = create_env_node(envp[i]);
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        i++;
    }
    return(head);
}