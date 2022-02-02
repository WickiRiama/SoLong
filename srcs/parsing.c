/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by mriant            #+#    #+#             */
/*   Updated: 2022/02/02 17:29:18 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(char *m_path, t_vars *vars)
{
	int		fd;
	int		i;
	t_list	*first;
	t_list	*line;

	fd = open(m_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open file %s\n.", m_path);
		return (-1);
	}
	first = NULL;
	line = ft_lstnew(get_next_line(fd));
	i = 0;
	while (line->content)
	{
		ft_lstadd_back(&first, line);
		line = ft_lstnew(get_next_line(fd));
		i ++;
	}
	vars->grid = malloc(sizeof(char) * i);
	line = first;
	i = 0;
	while (line)
	{
		vars->grid[i] = ft_strdup(line->content);
		printf("%s\n", vars->grid[i]);
		line = line->next;
		i ++;
	}
	vars->grid[i] = NULL;
	fd = close(fd);
	if (fd == -1)
	{
		printf("Error\nCan't close file %s.\n", m_path);
	}
	return (0);
}
