/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:45:01 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 17:03:39 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "map_utils.h"
# include "animation.h"
# include "hook_handles.h"
# include "render_utils.h"
# include "freeing.h"

void	setup_hooks(t_map *g);
int		ft_strcmp(const char *s1, const char *s2);
int		handle_deets(t_map g, t_deets ret);
int		open_files1(int *fd);
int		open_files2(int *fd);
int		open_files3(int *fd);
void	init_t_map(t_map *map);
int		map_lines(char *fname);
void	*get_tex(void *mlx, char *name);

#endif