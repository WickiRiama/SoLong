/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:59:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 10:58:04 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_int(char c)
{
	int	result;

	result = write(1, &c, 1);
	return (result);
}

int	ft_putstr_int(char *s)
{
	int	result;

	if (!s)
		result = write(1, "(null)", 6);
	else
		result = write(1, s, ft_strlen(s));
	return (result);
}
