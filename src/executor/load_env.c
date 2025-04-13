#include "../../includes/minishell.h"

char *join_env_var(t_env *env)
{
    char *env_var;

    env_var = ft_strjoin(env->key, env->value);
    if(!env_var)
        return (NULL);
    return (env_var);
}

char **env_list_to_array(t_env *env)
{
    t_env	*temp;
	int		i;
    char **env_arr;

	i = 0;
	temp = env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	env_arr = (char**)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (env)
	{
		env_arr[i] = join_env_var(env);
		env = env->next;
		i++;
	}
	env_arr[i] = NULL;
    return env_arr;
}

t_env *create_env_node(char *key, char *value)
{
    t_env *node;

    node = malloc(sizeof(t_env));
    if(!node)
        return NULL;
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

t_env *init_env_list(char **envp)
{
    t_env *head;
    t_env *new_node;
    t_env *current;
    char *key;
    char *value;
    size_t equal_signe;
    int i;

    head = NULL;
    current = NULL;
    new_node = NULL;
    i = 0;
    while(envp[i])
    {
        equal_signe = ft_strchr(envp[i], '=') - envp[i] + 1;
        key = ft_substr(envp[i], 0, equal_signe);
        value = ft_substr(envp[i], equal_signe, ft_strlen(envp[i]) - 1);
        new_node = create_env_node(key , value);
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        i++;
    }
    return(head);
}