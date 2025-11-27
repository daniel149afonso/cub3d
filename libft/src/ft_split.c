/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthbernstudent.@42lausanne.ch> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:23:10 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/08 12:51:37 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count_sub;
	int	in_word;

	count_sub = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count_sub++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count_sub);
}

static char	*ft_dup_word(const char	*s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_arr(char **str_arr, int j)
{
	while (--j >= 0)
		free(str_arr[j]);
	free(str_arr);
}

static int	ft_add_word(char **str_arr, int *j, char *word)
{
	if (!word)
	{
		free_arr(str_arr, *j);
		return (0);
	}
	str_arr[*j] = word;
	(*j)++;
	return (1);
}

char	**ft_split(char const	*s, char c)
{
	char	**str_arr;
	size_t	i;
	int		j;
	int		start;

	start = -1;
	i = 0;
	j = 0;
	str_arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str_arr)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i] == '\0') && start >= 0)
		{
			if (!ft_add_word(str_arr, &j, ft_dup_word(s, start, i)))
				return (NULL);
			start = -1;
		}
		i++;
	}
	str_arr[j] = NULL;
	return (str_arr);
}
