/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:20:43 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:25:35 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			glynn_info(t_env *env)
{
	env->zr = (env->x * (env->x2 - env->x1) / env->image_x) + env->x1;
	env->zi = (env->y * (env->y2 - env->y1) / env->image_y) + env->y1;
	env->cr = 0.291;
	env->ci = 0.006;
	return (0);
}

void		glynn(t_env *env)
{
	int		i;

	env->x = 0;
	while (env->x++ < env->image_x)
	{
		env->y = 0;
		while (env->y++ < env->image_y)
		{
			i = glynn_info(env);
			while (i++ < env->iter && env->zr * env->zr + env->zi * env->zi < 4)
			{
				env->tmp = env->zr;
				env->zr = sqrt((env->zr * env->zr - env->zi * env->zi) *
						(env->zr * env->zr - env->zi * env->zi)) + env->cr;
				env->zi = sqrt((2 * env->zi * env->tmp) * (2 * env->zi *
					env->tmp)) + env->ci;
			}
			if (i == env->iter)
				display(env, 0, 0, 0);
			else
				display(env, i * 200 / env->iter - env->blue - 200, i * 200 /
						env->iter - env->green - 200, i * 200 / env->iter -
						env->red - 250);
		}
	}
}

t_env		init_glynn(t_env *env)
{
	env->x1 = -1.0;
	env->x2 = 1.0;
	env->y1 = -1.0;
	env->y2 = 1.0;
	env->red = 10;
	env->green = 10;
	env->blue = 14;
	env->image_x = env->img.width;
	env->image_y = env->img.height;
	env->iter = 50;
	return (*env);
}
