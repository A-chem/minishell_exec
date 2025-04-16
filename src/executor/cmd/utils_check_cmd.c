#include "../../../includes/minishell.h"

int	ft_check_path_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	pars_cmd_1(char *cmd)
{
	char	*trimmed;

	trimmed = ft_strtrim(cmd, " ");
	if (!trimmed || !trimmed[0])
		return (ft_putstr_fd(cmd, 2), ft_putstr_fd(": Command not found\n", 2),
			free(trimmed), -1);
	if ((cmd[0] == ' ' || cmd[ft_strlen(cmd) - 1] == ' ' || cmd[0] == '.' )
		&& ft_check_path_cmd(cmd) == 0)
	{
		free(trimmed);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Command not found\n", 2);
		return (-1);
	}
	return (0);
}

int	pars_cmd_2(char **cmd_split, char **env)
{
	if (access(cmd_split[0], F_OK) == -1)
	{
		perror(cmd_split[0]);
		ft_double_free (cmd_split);
		return (-1);
	}
	if (access(cmd_split[0], X_OK) == -1)
	{
		ft_putstr_fd(cmd_split[0], 2);
		ft_putstr_fd(": Permission Denied\n", 2);
		ft_double_free (cmd_split);
		return (-1);
	}
	if (execve(cmd_split[0], cmd_split, env) == -1)
	{
		ft_double_free (cmd_split);
		ft_putstr_fd(cmd_split[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
		return (-1);
	}
	return (0);
}

int	pars_cmd_3(char **cmd_split, char **env)
{
	char	**path;
	char	*path_cmd;

	path = ft_split(fet_path(env), ':');
	if (!path)
		return (ft_double_free (cmd_split), ft_putstr_fd("Error\n", 2), -1);
	path_cmd = ft_found_cmd(cmd_split[0], path);
	if (!path_cmd)
	{
		ft_putstr_fd(cmd_split[0], 1);
		ft_putstr_fd(": Command not found\n", 2);
		return (ft_double_free (cmd_split),
			ft_double_free(path), -1);
	}
	if (execve(path_cmd, cmd_split, env) == -1)
		return (ft_double_free (cmd_split), ft_double_free(path),
			free(path_cmd), ft_putstr_fd("Execve Failed\n", 2), -1);
	return (0);
}

void	ft_double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}