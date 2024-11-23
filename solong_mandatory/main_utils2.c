/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:57:26 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 17:21:18 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	open_files2(int *fd)
{
	*fd = open("./tex/BRTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/BLTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/PLeft0.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/PRight0.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/Enemy.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/BackTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	return (1);
}

int	open_files3(int *fd)
{
	*fd = open("./tex/PlatformTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/BadEnding.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/HappyEnding.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/DownShadow.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/LeftShadow.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	return (1);
}

int	map_lines(char *fname)
{
	int		c;
	int		ln;
	int		fd;
	int		valid;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (0);
	c = -1;
	line = get_next_line(fd);
	valid = (line != NULL && ft_strlen(line) > 0);
	if (line)
		c = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	while (line)
	{
		ln = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		valid = (valid && ln == c);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!valid)
		(write(2, "Error\nInconsistent row sizes.\n", 30), exit(1));
	return (1);
}

static void	init_t_map2(t_map *map)
{
	map->mlx = NULL;
	map->mw = NULL;
}

void	init_t_map(t_map *map)
{
	int	i;

	init_t_map2(map);
	map->map = NULL;
	map->tex.p.enemy = NULL;
	map->tex.p.pleft = NULL;
	map->tex.p.pright = NULL;
	map->tex.s.cshad = NULL;
	map->tex.s.lshad = NULL;
	map->tex.s.dshad = NULL;
	map->tex.s.dlshad = NULL;
	map->tex.e.blside = NULL;
	map->tex.e.tlside = NULL;
	map->tex.e.brside = NULL;
	map->tex.e.trside = NULL;
	map->tex.e.downside = NULL;
	map->tex.e.leftside = NULL;
	map->tex.e.rightside = NULL;
	map->tex.w.back = NULL;
	map->tex.w.bend = NULL;
	map->tex.w.gend = NULL;
	map->tex.w.plat = NULL;
	i = -1;
	while (++i < 18)
		map->tex.w.cd[i] = NULL;
}
