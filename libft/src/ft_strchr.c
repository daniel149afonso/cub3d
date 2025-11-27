/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:24:53 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/03 13:41:54 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int				i;
	unsigned char	u;

	i = 0;
	u = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == u)
			return ((char *)&s[i]);
		i++;
	}
	if (u == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
