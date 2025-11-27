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

int	ft_print_hex(unsigned long nb, int upcase)
{
	char	*hex_digit;
	int		len;
	char	digit;

	len = 0;
	if (upcase == 1)
		hex_digit = "0123456789ABCDEF";
	else
		hex_digit = "0123456789abcdef";
	if (nb >= 16)
		len += ft_print_hex(nb / 16, upcase);
	digit = hex_digit[nb % 16];
	ft_putchar_fd(digit, 1);
	len++;
	return (len);
}

int	ft_count_nb(int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_count_u_nb(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_print_p(va_list args)
{
	unsigned long	nb;

	nb = (unsigned long)va_arg(args, void *);
	if (!nb)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	return (2 + ft_print_hex(nb, 0));
}

int	ft_print_x(va_list args, int uppercase)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_print_hex(nb, uppercase));
}
