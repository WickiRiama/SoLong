/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:53:30 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 10:58:11 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printuint(t_llui n, int *result, char *base, int len)
{
	char	c;

	if (n / len != 0)
		ft_printuint(n / len, result, base, len);
	c = base[(n % len)];
	*result += ft_putchar_int(c);
}

int	ft_putpoint(intptr_t n)
{
	int	result;

	result = 0;
	result += ft_putstr_int("0x");
	ft_printuint(n, &result, "0123456789abcdef", 16);
	return (result);
}

int	ft_putuint(unsigned int n)
{
	int	result;

	result = 0;
	ft_printuint(n, &result, "0123456789", 10);
	return (result);
}

int	ft_putx(unsigned int n)
{
	int	result;

	result = 0;
	ft_printuint(n, &result, "0123456789abcdef", 16);
	return (result);
}

int	ft_putxmaj(unsigned int n)
{
	int	result;

	result = 0;
	ft_printuint(n, &result, "0123456789ABCDEF", 16);
	return (result);
}
