/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:08:27 by kkoujan           #+#    #+#             */
/*   Updated: 2025/03/30 18:49:55 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"


int main()
{
	char    *line;
	while (1337)
	{
	line = readline("minishell$ ");
	if (!line)
		return (0);
	printf("line %s\n", line);
	printf("line %i\n", has_unclosed_quotes(line));
	printf("line %i\n", has_misplaced_pipes(line));
	printf("redir %i\n", has_invalid_redir(line));

	free(line);
	}
}
