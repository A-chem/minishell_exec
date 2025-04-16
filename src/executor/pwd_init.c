#include "../../includes/minishell.h"


void init_pwd(t_env **env)
{
    t_env *curr;
    t_env *new_node;
    char *pwd;
    int flag;

    curr = *env;
    flag = 0;
    while(curr)
    {
        if(ft_strcmp(curr->key, "PWD=") == 0)
            return ;
        if(ft_strcmp(curr->key, "OLDPWD") == 0)
            flag = 1;
        curr = curr->next;
    }
    pwd = getcwd(NULL, 0);
    new_node = create_env_node("PWD=", pwd);
    add_node(env, new_node);
    if(flag == 0)
    {
        new_node = create_env_node("OLDPWD", NULL);
        add_node(env, new_node);
    }
}
