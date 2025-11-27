/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:07 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/10 13:40:09 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char	*set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*str;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	end = ft_strlen(s1);
	while (end > i && ft_isset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], end - i + 1);
	return (str);
}
