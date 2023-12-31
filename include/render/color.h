/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:26 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:26 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <vec3.h>
# include <stdint.h>

void		color_add(t_vec3 *light, const t_vec3 *color, const t_vec3 *add);
void		color_scale(t_vec3 *light, double scale);

uint32_t	color_to_uint32(t_vec3 *color);

#endif