/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:28:23 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 17:12:12 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	open_files4(int *fd)
{
	*fd = open("./tex/DLShadow.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/CornerShadow.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	return (1);
}

static int	open_files5(int *fd)
{
	int		i;
	char	*cdn;
	char	*tmp;

	i = 0;
	while (i < 18)
	{
		cdn = ft_itoa(i);
		tmp = ft_strjoin("./tex/CD", cdn);
		if (cdn)
			free(cdn);
		cdn = ft_strjoin(tmp, ".xpm");
		if (tmp)
			free(tmp);
		if (!cdn)
			return (0);
		*fd = open(cdn, O_RDONLY);
		free(cdn);
		if (*fd < 0)
			return (0);
		i++;
	}
	return (1);
}

static int	count_enemies(t_map *g)
{
	int	i;
	int	j;

	i = 0;
	g->enemies = 0;
	while (i < g->rows)
	{
		j = -1;
		while (++j < g->cols)
			g->enemies += (g->map[i][j] == 'G' || g->map[i][j] == 'Q');
		i++;
	}
	if (g->enemies > 0)
		g->enemy_dir = malloc(sizeof(int) * g->enemies);
	if (g->enemies)
	{
		if (g->enemy_dir == NULL)
			return (0);
		i = 0;
		while (i < g->enemies)
			g->enemy_dir[i++] = 1;
	}
	return (1);
}

static int	setup_game(t_map *g, char **av)
{
	int		fd;
	char	**m;

	g->mvs = 0;
	g->speed = 3;
	fd = open(av[1], O_RDONLY);
	m = parse_map(fd, g);
	close(fd);
	if (!g->map)
		return (3);
	if (!m)
		return (9);
	if (!count_enemies(g))
		return (7);
	if (handle_deets(*g, is_playable(*g, g->px, g->py)))
		return (handle_deets(*g, is_playable(*g, g->px, g->py)));
	g->mlx = mlx_init();
	if (!g->mlx)
		return (1);
	g->mw = mlx_new_window(g->mlx, g->cols * 64, g->rows * 64, "Hack & Battle");
	if (!g->mw)
		return (2);
	get_textures(g);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		err;
	t_map	g;

	if (ac != 2 || ft_strlen(av[1]) < 5
		|| ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".ber"))
	{
		write(2, "Usage: ./so_long <map_name.ber>\n", 32);
		exit(EXIT_FAILURE);
	}
	if (!open_files1(&fd) || !open_files2(&fd) || !open_files3(&fd)
		|| !open_files4(&fd) || !open_files5(&fd) || !map_lines(av[1]))
	{
		write(2, "Error\nCould not open a file.\n", 29);
		exit(EXIT_FAILURE);
	}
	init_t_map(&g);
	fd = open(av[1], O_RDONLY);
	get_map_size(fd, &g.rows, &g.cols, &g);
	if (g.rows > 20 || g.cols > 35)
		free_up(&g, 10, 1);
	err = setup_game(&g, av);
	if (err)
		free_up(&g, err, EXIT_FAILURE);
	setup_hooks(&g);
}
