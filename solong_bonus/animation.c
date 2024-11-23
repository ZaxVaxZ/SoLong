/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:42:56 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/25 13:34:56 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void	get_cd_tex(t_map *g)
{
	int		i;
	int		x;
	int		y;
	char	*tmp;
	char	*cdn;

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
			g->tex.w.cd[i] = cdn;
		else
			g->tex.w.cd[i] = mlx_xpm_file_to_image(g->mlx, cdn, &x, &y);
		if (cdn)
			free(cdn);
		i++;
	}
}

void	check_textures(t_map *g, t_tex t)
{
	int	i;

	if (!t.e.upside || !t.e.leftside || !t.e.rightside || !t.e.downside
		|| !t.e.trside || !t.e.tlside || !t.e.brside || !t.e.blside
		|| !t.p.enemy
		|| !t.p.pleft || !t.p.pright || !t.w.back || !t.w.plat || !t.w.gend
		|| !t.s.dshad || !t.s.lshad || !t.s.dlshad || !t.s.cshad || !t.w.bend)
		free_up(g, 8, 127);
	i = 0;
	while (i < 18)
	{
		if (!t.w.cd[i])
			free_up(g, 8, 127);
		i++;
	}
}
