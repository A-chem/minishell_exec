/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:21:40 by kkoujan           #+#    #+#             */
/*   Updated: 2025/04/07 21:19:16 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
