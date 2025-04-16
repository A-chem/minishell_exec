#include "../../../includes/minishell.h"

char	*fet_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = "PATH=";
	while (env[i])
	{
		if (ft_strncmp(env[i], path, 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_found_cmd(char *cmd, char **path)
{
	int		i;
	char	*cmd_path_join;
	char	*cmd_path_join_2;

	i = 0;
	while (path[i])
	{
		cmd_path_join = ft_strjoin(path[i], "/");
		cmd_path_join_2 = ft_strjoin(cmd_path_join, cmd);
		free(cmd_path_join);
		if (access(cmd_path_join_2, X_OK) == 0)
			return (cmd_path_join_2);
		free(cmd_path_join_2);
		i++;
	}
	return (NULL);
}

int	check_exec_cmd(char *cmd, char **env)
{
	char	**cmd_split;

	cmd_split = ft_split(cmd, ' ');
	if (ft_check_path_cmd(cmd) == 1)
	{
		if (pars_cmd_2(cmd_split, env) == -1)
			return (-1);
	}
	else
	{
		if (pars_cmd_3(cmd_split, env) == -1)
			return (-1);
	}
	ft_double_free(cmd_split);
	return (1);
}