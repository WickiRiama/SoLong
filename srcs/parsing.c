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

t_list	*ft_read_grid(int fd)
{
	t_list	*first;
	t_list	*line;
	
	first = NULL;
	line = ft_lstnew(get_next_line(fd));
	while (line->content)
	{
		ft_lstadd_back(&first, line);
		line = ft_lstnew(get_next_line(fd));
	}
	free(line);
	return (first);
}

int ft_parse_grid(t_list **first, t_vars *vars)
{
	t_list	*line;
	int		i;
	char	**grid;

	vars->map.height = ft_lstsize(*first);
	grid = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!grid)
	{
		printf("Error\nCouldn't allocate map\n");
		ft_lstclear(first, &free);
		return (-1);
	}
	line = *first;
	i = 0;
	while (line)
	{
		grid[i] = ft_strdup((char *)(line->content));
		line = line->next;
		i ++;
	}
	grid[i] = NULL;
	vars->map.grid = grid;
	vars->map.width = ft_strlen(grid[0]) - 1;
	ft_lstclear(first, &free);
	return (0);
}

int	ft_build_map(char *m_path, t_vars *vars)
{
	int		fd;
	t_list	*lst_grid;
	int		ret;

	fd = open(m_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open file %s\n.", m_path);
		return (-1);
	}
	lst_grid = ft_read_grid(fd);
	if (!lst_grid)
	{
		printf("Error\nCouldn't read map\n");
		return (-1);
	}
	ret = ft_parse_grid(&lst_grid, vars);
	if(ret == -1)
	{
		printf("Error\nCouldn't read map\n");
		return (-1);
	}
	fd = close(fd);
	if (fd == -1)
	{
		printf("Error\nCan't close file %s.\n", m_path);
		return (-1);
	}
	return (0);
}
