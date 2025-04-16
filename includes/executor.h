#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./parser.h"
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;


t_env *init_env_list(char **envp);
void handle_shlvl(t_env **env);
void init_pwd(t_env **env);
t_env *create_env_node(char *key, char *value);
void	add_node(t_env **env, t_env *new);
char *ft_getenv(t_env *env, char *key);
char **env_list_to_array(t_env *env) ;

void exec(t_cmd_table *data, t_env *env);
void single_cmd(t_simple_cmd **data, t_env *env, char **env_arr);
int is_builtin(char *cmd);
void exec_builtin(t_simple_cmd **data, t_env *env, char **env_array);

void builtin_echo(t_simple_cmd **data);
int  is_n_flage(char *str);

void builtin_env(t_simple_cmd **data, t_env *env);

void builtin_cd(t_simple_cmd **data, t_env *env);

void builtin_pwd();

void builtin_export(t_simple_cmd **data, t_env *env);
void print_export(t_env *env);
int  valid_export(char *str);
void var_set(char *str, t_env *env);

void builtin_exit(t_simple_cmd **data);

void  builtin_unset(t_simple_cmd **data, t_env *env);

void exec_cmd(t_simple_cmd **data, char **env_arr);
int	check_exec_cmd(char *cmd, char **env);
int	ft_check_path_cmd(char *cmd);
char	*fet_path(char **env);
char	*ft_found_cmd(char *cmd, char **path);
int	pars_cmd_1(char *cmd);
int	pars_cmd_2(char **cmd_split, char **env);
int	pars_cmd_3(char **cmd_split, char **env);
void	ft_double_free(char **str);

void inf_outf_cmd(t_simple_cmd **data);

#endif