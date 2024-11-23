/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:19:45 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/24 21:39:36 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "structs.h"
# include <stdlib.h>
# include "extra_utils.h"
# include "mlx.h"
# include "hook_handles.h"
# include "freeing.h"

void	check_textures(t_map *g, t_tex t);
void	get_cd_tex(t_map *g);
int		handle_keys(int keycode, t_map *g);
char	*ft_strjoin(char const *s1, char const *s2);

#endif