/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:58 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:58 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>

t_vec3	vec3_scalar(const t_vec3 *lhs, const VEC3_TYPE rhs)
{
	uint_fast8_t	i;
	t_vec3			ret;

	i = 0;
	while (i < 3)
	{
		ret.data[i] = lhs->data[i] * rhs;
		i++;
	}
	return (ret);
}

t_vec3	vec3_scalar_c(const t_vec3 lhs, const VEC3_TYPE rhs)
{
	return (vec3_scalar(&lhs, rhs));
}
