/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:37:00 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:37:33 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandel(t_env *env)
{
	env->cr = (env->x * (env->x2 - env->x1) / env->image_x) + env->x1;
	env->ci = (env->y * (env->y2 - env->y1) / env->image_y) + env->y1;
	env->zr = 0;
	env->zi = 0;
	return (0);
}

void		mandelbrot(t_env *env)
{
	int		i;
	double	tmp;

	env->x = 0;
	while (env->x++ < env->image_x)
	{
		env->y = 0;
		while (env->y++ < env->image_y)
		{
			i = mandel(env);
			while (i++ < env->iter && env->zr * env->zr + env->zi * env->zi < 4)
			{
				tmp = env->zr;
				env->zr = (env->zr * env->zr) - (env->zi * env->zi) + env->cr;
				env->zi = 2 * env->zi * tmp + env->ci;
			}
			if (i == env->iter)
				display(env, 0, 0, 0);
			else
				display(env, i * 200 / env->iter - env->blue - 200, i * 200 /
						env->iter - env->green - 200, i * 200 / env->iter
						- env->red - 200);
		}
	}
}

t_env		init_mandel(t_env *env)
{
	env->red = 3389;
	env->green = 5391;
	env->blue = 1541;
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->image_x = env->img.width;
	env->image_y = env->img.height;
	env->iter = 50;
	return (*env);
}
