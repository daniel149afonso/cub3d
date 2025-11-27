/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:01:49 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/24 15:34:07 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_param_handler(const char	*str, va_list args)
{
	if (*str == 'p')
		return (ft_print_p(args));
	else if (*str == 'c')
		return (ft_print_c(args));
	else if (*str == 's')
		return (ft_print_s(args));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_i(args));
	else if (*str == 'u')
		return (ft_print_u(args));
	else if (*str == 'x')
		return (ft_print_x(args, 0));
	else if (*str == 'X')
		return (ft_print_x(args, 1));
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				counter;

	va_start(args, str);
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			counter += ft_param_handler(str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			counter++;
		}
		str++;
	}
	va_end(args);
	return (counter);
}
