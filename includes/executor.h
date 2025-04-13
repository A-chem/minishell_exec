#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./parser.h"

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;


t_env *init_env_list(char **envp);
t_env *create_env_node(char *key, char *value);
char **env_list_to_array(t_env *env) ;

void exec(t_cmd_table *data, t_env *env);
void single_cmd(t_simple_cmd **data, t_env *env, char **env_arr);
int is_builtin(char *cmd);
void exec_builtin(t_simple_cmd **data, t_env *env, char **env_array);

void builtin_echo(t_simple_cmd **data);
int  is_n_flage(char *str);

void builtin_env(t_env *env);

void builtin_cd(t_simple_cmd **data, t_env *env);

void builtin_pwd();
void builtin_export(t_simple_cmd **data, t_env *env);
void print_export(t_env *env);
int  valid_export(char *str);
void var_set(char *str, t_env *env);



#endif 