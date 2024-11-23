/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:45:45 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/18 18:17:02 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	exit_hook(t_map *g)
{
	free_up(g, 0, 0);
	return (0);
}

void	setup_hooks(t_map *g)
{
	g->frame = 0;
	render_map(*g);
	mlx_hook(g->mw, 17, 1L << 2, exit_hook, g);
	mlx_hook(g->mw, 3, 0, handle_keys, g);
	mlx_loop_hook(g->mlx, animations, g);
	mlx_expose_hook(g->mw, expose_hook, g);
	mlx_key_hook(g->mw, handle_keys, g);
	mlx_loop(g->mlx);
	free_up(g, 0, 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	handle_deets(t_map g, t_deets ret)
{
	if (ret.ends == -1)
		return (7);
	if (!ret.ends)
		return (4);
	if (ret.discs != g.coins)
		return (5);
	return (0);
}

int	open_files1(int *fd)
{
	*fd = open("./tex/UpTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/RightTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/LeftTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/DownTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/TRTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	*fd = open("./tex/TLTile.xpm", O_RDONLY);
	if (*fd < 0)
		return (0);
	close(*fd);
	return (1);
}
