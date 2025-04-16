#include  "../../../includes/minishell.h"

int is_numeric(const char *str)
{
    int i = 0;

    if (!str)
        return 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
int ft_atoll(const char *str, long long *code)
{
    unsigned long long result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if (sign == 1 && result > (unsigned long long)LLONG_MAX)
			return 0;
		if (sign == -1 && result > (unsigned long long)LLONG_MAX + 1)
			return 0;
        str++;
    }
    *code = sign * result;
    return 1;
}
void builtin_exit(t_simple_cmd **data)
{
    long long code;

    if((*data)->argc == 1)
    {
        printf("exit\n");
        exit(0);
    }
    if((*data)->argc == 2)
    {
        if (!is_numeric((*data)->args[1]))
        {
            printf("exit\nexit: %s: numeric argument required\n", (*data)->args[1]);
            exit(255);
        }
        if (!ft_atoll((*data)->args[1], &code))
        {
            printf("exit\nexit: %s: numeric argument required\n", (*data)->args[1]);
            exit(255);
        }
    }
    else
        return(printf("exit\nexit: too many arguments\n"),
            exit(255));
    return (printf("exit\n"), exit(code % 256));
}
