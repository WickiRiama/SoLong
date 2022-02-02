/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:38:19 by mriant            #+#    #+#             */
/*   Updated: 2021/12/07 17:19:49 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(char), (ft_strlen(s) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i ++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i ++;
		j ++;
	}
	result[i] = '\0';
	return (result);
}
