/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:39:40 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 10:57:51 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printconv(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar_int(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr_int(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putdec(va_arg(ap, int)));
	if (c == 'p')
		return (ft_putpoint((intptr_t) va_arg(ap, void *)));
	if (c == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_putx(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_putxmaj(va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putchar_int('%'));
	else
	{
		ft_putchar_int('%');
		ft_putchar_int(c);
		return (2);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		total;
	va_list	ap;

	i = 0;
	total = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i ++;
			total += ft_printconv(ap, s[i]);
		}
		else
			total += write (1, &s[i], 1);
		i ++;
	}
	va_end(ap);
	return (total);
}
