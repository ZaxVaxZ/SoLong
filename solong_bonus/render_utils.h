/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:24 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 17:57:57 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H

# include "mlx.h"
# include "extra_utils.h"
# include "structs.h"
# include "animation.h"

void	get_textures(t_map *g);
void	render_map(t_map g);

#endif