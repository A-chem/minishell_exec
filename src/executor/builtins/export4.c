#include  "../../../includes/minishell.h"
void handle_plus(t_env **env, char **key, char **value, int flag)
{
    t_env *curr;
    t_env *new_node;
    char *str;

    curr = *env;
    *key = ft_strtrim(*key, "+=");
    *key = ft_strjoin(*key, "=");
    str = *value;
    if(!*key)
    return ;
    if(flag == 1)
    {
        while(curr)
        {
            if(ft_strcmp(curr->key, *key) == 0)
            {
                curr->value = ft_strjoin(curr->value, *value);
                return ;
            }
            curr =  curr->next;
        }
    }
    new_node = create_env_node(*key, str);
    add_node(env, new_node);
    
}

int update_var(t_env **env, char *key, char *value)
{
    char *str;
    char *new;
    t_env *curr = *env;
    
    if(ft_strchr(key, '+'))
        return (handle_plus(env, &key, &value, 1), 1);
    if(!ft_strchr(key, '='))
    {
        while(curr)
        {
            str = ft_strtrim(curr->key, "=");
            if(!str)
                return 0;
            if(ft_strcmp(str, key) == 0)
                return 1;
            curr =  curr->next;
        }
    }
    else
    {
        curr = *env;
        while(curr)
        {
            str = ft_strtrim(curr->key, "=");
            new = ft_strtrim(key, "=");
            if(!str || !new)
                return 0;
            if(ft_strcmp(str, new) == 0)
            {
                curr->key = key;
                curr->value = value;
                return 1;
            }
            curr =  curr->next;
        }
    }
    return 0;
}

void	add_node(t_env **env, t_env *new)
{
	t_env	*l;
	if (!env || !new)
		return ;
	if (*env == NULL)
	{
		*env = new;
	}
	else
	{
		l = *env;
		while (l->next != NULL)
		{
			l = l->next;
		}
		l->next = new;
	}
}

void add_var(t_env **env, char *key, char *value)
{
    t_env *new_node;

    if(update_var(env, key, value) == 1)
        return ;
    else
    {
        if(ft_strchr(key, '+'))
            handle_plus(env, &key, &value, 0);
        new_node = create_env_node(key, value);
        add_node(env, new_node);
    }
}

void var_set(char *str, t_env *env)
{
    char *key;
    char *value;
    size_t size;

    key = NULL;
    value= NULL;

    if(ft_strchr(str, '='))
    {
        size = ft_strchr(str, '=') - str + 1;
        key = ft_substr(str, 0, size);
        if(!key)
            return ;
        value = ft_substr(str, size , ft_strlen(str) - 1);
        if(!value)
            return ;
    }
    else
    {
        key = ft_strdup(str);
        if(!key)
            return ;
    }
    add_var(&env, key, value);
}
