#include  "../../../includes/minishell.h"

void builtin_export(t_simple_cmd **data, t_env *env)
{
	int i; 
    
	i = 1;
	if(!(*data)->args[1])
		return(print_export(env));
	while((*data)->args[i])
	{
		if(!valid_export((*data)->args[i]))
		{
			i++;
			continue ;
		}
		else
			var_set((*data)->args[i], env);
		i++;
	}
	
}
