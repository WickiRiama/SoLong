/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 09:58:58 by mriant           ###   ########.fr       */
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

int	ft_parse_grid(t_list **first, t_vars *vars)
{
	t_list	*line;
	int		i;

	vars->map.height = ft_lstsize(*first);
	vars->map.grid = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!(vars->map.grid))
	{
		ft_lstclear(first, &free);
		return (-1);
	}
	line = *first;
	i = 0;
	while (line)
	{
		vars->map.grid[i] = ft_strdup((char *)(line->content));
		if (vars->map.grid[i][ft_strlen(vars->map.grid[i]) - 1] == '\n')
			vars->map.grid[i][ft_strlen(vars->map.grid[i]) - 1] = '\0';
		line = line->next;
		i ++;
	}
	vars->map.grid[i] = NULL;
	vars->map.width = ft_strlen(vars->map.grid[0]);
	ft_lstclear(first, &free);
	return (0);
}

int	ft_check_map(t_vars *vars, char **grid)
{
	int	i;
	int	j;
	int	count_p;

	i = 0;
	count_p = 0;
	while (grid[i])
	{
		if (ft_strlen(grid[i]) == 0 || ft_strlen(grid[i]) != vars->map.width)
			return (-1);
		j = 0;
		while (grid[i][j])
		{
			if (ft_count_assets(i, j, &count_p, vars) == -1)
				return (-1);
			j ++;
		}
		i ++;
	}
	if (vars->collect.count == 0 || vars->exit.count == 0 || count_p != 1)
		return (-1);
	return (0);
}

int	ft_set_map(int fd, t_vars *vars)
{
	t_list	*lst_grid;
	int		ret;

	lst_grid = ft_read_grid(fd);
	ret = ft_parse_grid(&lst_grid, vars);
	if (ret == -1 || !vars->map.grid[0])
	{
		ft_printf("Error\nCouldn't read map\n");
		return (-1);
	}
	ret = ft_check_map(vars, vars->map.grid);
	if (ret == -1)
	{
		ft_printf("Error\nInvalid map\n");
		return (-1);
	}
	mlx_get_screen_size(vars->mlx, &vars->screen_x, &vars->screen_y);
	if ((size_t)vars->screen_x < vars->map.width * 48
		|| (size_t)vars->screen_y < vars->map.height * 48)
	{
		ft_printf("Error\nMap too big\n");
		return (-1);
	}
	return (0);
}

int	ft_build_map(char *m_path, t_vars *vars)
{
	int		fd;
	int		ret;

	ret = ft_strlen(m_path);
	if (ret < 5 || m_path[ret - 4] != '.' || m_path[ret - 3] != 'b'
		|| m_path[ret - 2] != 'e' || m_path[ret - 1] != 'r')
	{
		ft_printf("Error\nInvalid file %s\n", m_path);
		return (-1);
	}
	fd = open(m_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid file %s\n", m_path);
		return (-1);
	}
	ret = ft_set_map(fd, vars);
	fd = close(fd);
	if (fd == -1)
	{
		ft_printf("Error\nCan't close file %s.\n", m_path);
		return (-1);
	}
	return (ret);
}
