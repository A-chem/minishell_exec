#include  "../../../includes/minishell.h"

int equal_char(char *str, char *key)
{
	int i; 

	i = 1;
	if(!ft_isalpha(key[0]))
		{
			if(key[0] != '_')
				return (printf("export: '%s': not a valid identifier\n", str),0);
		}
	while(key[i])
	{
		if(key[i] == '+' && key[i+1] == '=')
		{
			return 1;
		}
		if(!ft_isalnum(key[i]) && key[i] != '=')
		{
			if(key[i] != '_')
				return (printf("export: '%s': not a valid identifier\n", str),0);
		}
		i++;
	}
	return (1);
}
int not_equal(char *str)
{
	int i;

	i = 1;
	if(!ft_isalpha(str[0]))
		{
			if(str[0] != '_')
				return (printf("export: '%s': not a valid identifier\n", str),0);
		}
	while(str[i])
	{
		if(!ft_isalnum(str[i]))
		{
			
			if(str[i] != '_')
				return (printf("export: '%s': not a valid identifier\n", str),0);
		}
		i++;
	}
	return (1);
}
int valid_export(char *str)
{
	char *key;
	size_t size;

	if(ft_strchr(str, '='))
	{
		size = ft_strchr(str, '=') - str + 1;
		key = ft_substr(str, 0, size);
		if(!key)
			return 0;
		if(!equal_char(str, key))
			return (0);
	}
	else
	{
		if(!not_equal(str))
			return (0);
	}
	return (1);
}
