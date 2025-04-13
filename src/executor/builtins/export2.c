#include  "../../../includes/minishell.h"
t_env *copy_env(t_env *env)
{
	t_env *new_env = NULL;
	t_env *last = NULL;
	t_env *new_node;

	while (env)
	{
		new_node = malloc(sizeof(t_env));
		if (!new_node)
			return (NULL);
		new_node->key = strdup(env->key);
		if(env->value)
			new_node->value = strdup(env->value);
		else
			new_node->value = NULL;
		new_node->next = NULL;

		if (!new_env)
			new_env = new_node;
		else
			last->next = new_node;
			
		last = new_node;
		env = env->next;
	}
	return new_env;
}
t_env *sort_var(t_env *head)
{
	t_env *curr;
	char *swap_key;
	char *swap_value;

	if (!head)
		return (NULL);
	curr = head;
	while (curr && curr->next)
	{	
		if (ft_strcmp(curr->key, curr->next->key) > 0)
		{
			swap_key = curr->key;
			curr->key = curr->next->key;
			curr->next->key = swap_key;
			swap_value = curr->value;
			curr->value = curr->next->value;
			curr->next->value = swap_value;
			curr = head;
		}
		else
			curr = curr->next;
	}
	return (head);
}


void print_export(t_env *env)
{
	t_env *sorted;

	sorted = sort_var(copy_env(env));
	if(!sorted)
		return ;
	while(sorted)
	{
		if (!sorted->value)
			printf("declare -x %s\n", sorted->key);
		else
			printf("declare -x %s\"%s\"\n", sorted->key, sorted->value);
		sorted = sorted->next;
	}
}
