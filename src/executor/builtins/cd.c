
#include  "../../../includes/minishell.h"

char *ft_getenv(t_env *env, char *key)
{
    if(!env || !key)
        return NULL;
    while(env)
    {
        if(ft_strcmp(env->key, key) == 0)
            return (env->value);
        env = env->next;
    }
    return NULL;
}
void update_pwd(t_env **env, char *key, char *value)
{
    t_env *current = *env;
    t_env *node;
    while (current)
    {
        if (ft_strcmp(current->key, key) == 0)
        {
            current->value = ft_strdup(value);
                return;
        }
        current = current->next;
    }
    node = create_env_node(key, value);
    add_node(env, node);
}

void builtin_cd(t_simple_cmd **data, t_env *env)
{
    char *target;
    char *oldpwd;
    char *newpwd;
    
    if((*data)->args[2])
        {
            printf("cd: too many arguments\n");
            return ;
        }
    target = NULL;
    oldpwd = getcwd(NULL, 0);
    if(!oldpwd)
        return ;
    if(!(*data)->args[1])
    {
        target = ft_getenv(env, "HOME=");
        printf("cd: HOME not set\n");
        return ;
    }
    else if (strcmp((*data)->args[1], "-") == 0)    
    target = ft_getenv(env, "OLDPWD=");
    else 
        target = (*data)->args[1];
    if(!target)
        return ;
    if (chdir(target) != 0)
    {
        perror("cd");
        return ;
    }
    update_pwd(&env, "OLDPWD=", oldpwd);
    newpwd = getcwd(NULL, 0);
    if (newpwd)
            update_pwd(&env, "PWD=", newpwd);
}



