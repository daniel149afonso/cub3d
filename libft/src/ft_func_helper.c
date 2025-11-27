/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:41:14 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:37 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	ft_print_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_print_i(va_list args)
{
	int	nb;
	int	counter;

	counter = 0;
	nb = va_arg(args, int);
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		counter += 11;
	else if (nb < 0)
	{
		counter++;
		nb = -nb;
	}
	if (nb == 0)
		counter++;
	else if (nb)
		counter += ft_count_nb(nb);
	return (counter);
}

int	ft_print_u(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_u(nb, 1);
	return (ft_count_u_nb(nb));
}

void	ft_putnbr_u(unsigned int n, int fd)
{
	char	digit;

	if (n >= 10)
		ft_putnbr_u(n / 10, fd);
	digit = (n % 10) + '0';
	ft_putchar_fd(digit, 1);
}
