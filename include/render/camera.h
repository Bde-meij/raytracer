/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:24 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:24 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <vec3.h>
# include "render/ray.h"

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	direction;
	t_vec3	up;
	double	hfov;

	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	lower_left_corner;
}	t_camera;

t_camera	camera_new(const t_vec3 position, const t_vec3 direction, \
	double hfov);

void		camera_prepare(t_camera *camera, double aspect_ratio);

void		camera_update(t_camera *camera, const t_vec3 position, \
	const t_vec3 direction, double hfov);

t_ray		camera_generate_ray(const t_camera *camera, double width_pct, \
	double height_pct);

#endif
