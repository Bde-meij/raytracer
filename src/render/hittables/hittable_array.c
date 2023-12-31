/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hittable_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:11 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:11 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable_array.h"
#include <libft.h>
#include <math.h>

t_hittable_array	*hittable_array_new(const size_t capacity)
{
	t_hittable_array	*array;

	array = malloc(sizeof(t_hittable_array));
	if (!array)
		return (NULL);
	array->capacity = capacity;
	array->size = 0;
	array->hittables = malloc(capacity * sizeof(t_hittable));
	if (!array->hittables)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

void	hittable_array_destroy(t_hittable_array *array)
{
	if (array == NULL)
		return ;
	free(array->hittables);
	free(array);
}

t_hittable_array	*hittable_array_append(t_hittable_array **array, \
	t_hittable hittable)
{
	t_hittable	*tmp;

	if ((*array)->size >= (*array)->capacity)
	{
		tmp = (*array)->hittables;
		(*array)->hittables = ft_realloc((*array)->hittables, \
			(*array)->capacity * sizeof(t_hittable), \
			(*array)->capacity * 2 * sizeof(t_hittable));
		if (!(*array)->hittables)
		{
			(*array)->hittables = tmp;
			return (hittable_array_destroy(*array), *array = NULL, NULL);
		}
		free(tmp);
		(*array)->capacity *= 2;
	}
	(*array)->hittables[(*array)->size] = hittable;
	(*array)->size++;
	return (*array);
}

bool	hittable_array_hit(const t_hittable_array *list, const t_ray *ray, \
	t_hit_record *hit_record)
{
	t_hit_record	closest;
	t_hit_record	tmp;
	bool			hit_anything;
	size_t			i;

	i = 0;
	hit_anything = false;
	closest.distance = ray->max_distance;
	while (i < list->size)
	{
		if (hittable_hit(&list->hittables[i], ray, &tmp))
		{
			if (hit_record == NULL)
				return (true);
			hit_anything = true;
			if (fabs(tmp.distance) <= fabs(closest.distance))
				closest = tmp;
		}
		i++;
	}
	if (!hit_anything)
		return (false);
	*hit_record = closest;
	return (true);
}
