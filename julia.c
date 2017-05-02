/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:29:33 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:31:53 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ju(t_env *env)
{
	env->zr = (env->x * (env->x2 - env->x1) / env->image_x) + env->x1;
	env->zi = (env->y * (env->y2 - env->y1) / env->image_y) + env->y1;
	return (0);
}

void		julia(t_env *env)
{
	int		i;
	double	tmp;

	env->x = 0;
	while (env->x++ < env->image_x)
	{
		env->y = 0;
		while (env->y++ < env->image_y)
		{
			i = ju(env);
			while (i++ < env->iter && env->zr * env->zr + env->zi * env->zi < 4)
			{
				tmp = env->zr;
				env->zr = (env->zr * env->zr) - (env->zi * env->zi) + env->cr;
				env->zi = 2 * (env->zi * tmp) + env->ci;
			}
			if (i == env->iter)
				display(env, 0, 0, 0);
			else
				display(env, i * 200 / env->iter - env->blue - 200, i * 200 /
						env->iter - env->green - 200, i * 200 / env->iter -
						env->red - 240);
		}
	}
}

t_env		init_julia(t_env *env)
{
	env->cr = 0.284;
	env->ci = 0.01;
	env->x1 = -1;
	env->x2 = 1;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->red = 2;
	env->green = 10;
	env->blue = 4;
	env->image_x = env->img.width;
	env->image_y = env->img.height;
	env->iter = 120;
	return (*env);
}
