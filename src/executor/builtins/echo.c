#include  "../../../includes/minishell.h"

int is_n_flage(char *str)
{
    int i;

    if(!str || str[0] != '-')
        return (0);
    if(str[0] == '-' && !str[1])
        return (0);
    
    i = 1;
    while(str[i])
    {
        if(str[i] != 'n')
            return(0);
        i++;
    }
    return (1);
}

void builtin_echo(t_simple_cmd **data)
{
    int i;          // Start from argv[1], since argv[0] is "echo"
    int newline;    // Assume we want to print a newline at the end

    i = 1;
    newline = 1;
    /********Handle -n flags********/
    while((*data)->args[i] && is_n_flage((*data)->args[i]))
    {
        newline = 0; // If we find any -n flag, we disable the newline
        i++;        
    }
    /********Print all remaining arguments********/
    while((*data)->args[i])
    {
        ft_putstr_fd((*data)->args[i], 1);
        if((*data)->args[i + 1])
            ft_putstr_fd(" ", 1);
        i++;
    }
    if (newline)    // Only print a newline if we didn’t detect -n
        ft_putstr_fd("\n", 1);
}