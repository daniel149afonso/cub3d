/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:19:18 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/07 16:21:43 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*return_zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb_digit;
	int		ngt;
	long	num;

	num = n;
	ngt = (n < 0);
	if (n == 0)
		return (return_zero());
	if (ngt)
		num = -num;
	nb_digit = count_digit(n) + ngt;
	str = (char *)malloc(nb_digit + 1);
	if (!str)
		return (NULL);
	str[nb_digit--] = '\0';
	while (num > 0)
	{
		str[nb_digit--] = (num % 10) + '0';
		num /= 10;
	}
	if (ngt)
		str[0] = '-';
	return (str);
}
