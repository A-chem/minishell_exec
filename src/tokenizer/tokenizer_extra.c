/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 03:07:06 by kkoujan           #+#    #+#             */
/*   Updated: 2025/03/31 03:35:22 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

int str_concat_len(char *cmd)
{
	int	    i;
	int	    counter;
	char    quote_char;
	int	    in_quote;

	counter = 0;
	i = -1;
	in_quote = 0;
	quote_char = 0;	
	while (cmd[++i])
	{
		if (!in_quote && (cmd[i] == '\'' || cmd[i] == '\"'))
		{
			in_quote = 1;
			quote_char = cmd[i];
		}
		else if (in_quote && cmd[i] == quote_char)
		{
			in_quote = 0;
			quote_char = 0;
		}
		else
			counter++;
	}
    return (counter);
}

char *concat_str(char *cmd, char *str ,int len)
{
	int	i;
	char	quote_char;
	int	in_quote;

	i = -1;
	in_quote = 0;
	quote_char = 0;	
	len = 0;
	while (cmd[++i])
	{
		if (!in_quote && (cmd[i] == '\'' || cmd[i] == '\"'))
		{
			in_quote = 1;
			quote_char = cmd[i];
		}
		else if (in_quote && cmd[i] == quote_char)
		{
			in_quote = 0;
			quote_char = 0;
		}
		else
			str[len++] = cmd[i];
	}
	str[len] = '\0';
	return (str);
}

char *join_cmd(char *cmd)
{
	int	len;
	char	*str;

	len = str_concat_len(cmd);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
    str = concat_str(cmd, str, len);
	if (str == NULL)
		return (NULL);
	return (str);
}

t_token	*handle_tokenizer(t_token **tokenlst)
{
	t_token *lst;
	char	*val;

	lst = *tokenlst;
	while (lst)
	{
		if (lst->type == WORD_T)
		{
			val = join_cmd(lst->val);
			if (val == NULL)
				return (NULL);
			free(lst->val);
			lst->val = val;
			val = NULL;
		}
		lst = lst->next;
	}
	return *tokenlst;
}
