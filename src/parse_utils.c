/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:13:09 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/23 15:59:55 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strtrim_space(char *s)
{
	int		start;
	int		end;
	char	*trim;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && (s[start] == ' ' || s[start] == '\t'
			|| s[start] == '\n'))
		start++;
	end = ft_strlen(s);
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'
			|| s[end - 1] == '\n'))
		end--;
	trim = ft_substr(s, start, end - start);
	return (trim);
}

int	parse_color_trim(char **split)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = ft_strtrim_space(split[i]);
		free(split[i]);
		split[i] = tmp;
		i++;
	}
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	if (!is_number(split))
		return (0);
	return (1);
}
