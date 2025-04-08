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
t_env *create_env_node(char *env_str);

void exec(t_cmd_table *data, t_env *env);
void single_cmd(t_simple_cmd **data, t_env *env);
int is_builtin(char *cmd);
void exec_builtin(t_simple_cmd **data, t_env *env);

void builtin_echo(t_simple_cmd **data);
int is_n_flage(char *str);
void builtin_env(t_env *env);



#endif