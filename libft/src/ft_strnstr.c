/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <cuthber4student.2lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:55:17 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/08 12:33:14 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle,
					size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	needle_len = ft_strlen(needle);
	if (len == 0 || len < needle_len)
		return (NULL);
	while (haystack[i] != '\0' && i <= len - needle_len)
	{
		if (haystack[i] == needle[0] && ft_strncmp(&haystack[i],
				needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
