/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:33:44 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/10 13:39:13 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*join;
	size_t	size1;
	size_t	size2;
	size_t	total;

	size1 = 0;
	size2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		size1 = ft_strlen(s1);
	if (s2)
		size2 = ft_strlen(s2);
	total = size1 + size2;
	join = (char *)malloc(total + 1);
	if (!join)
		return (NULL);
	if (s1)
		ft_memcpy(join, (char *)s1, size1);
	if (s2)
		ft_memcpy(join + size1, (char *)s2, size2);
	join[total] = '\0';
	return (join);
}
