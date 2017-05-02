/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kawai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:32:43 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:33:37 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		kawai_info(t_env *env)
{
	env->zr = (env->x * (env->x2 - env->x1) / env->image_x) + env->x1;
	env->zi = (env->y * (env->y2 - env->y1) / env->image_y) + env->y1;
	return (0);
}

void	kawai(t_env *env)
{
	int	i;

	env->x = 0;
	while (env->x++ < env->image_x)
	{
		env->y = 0;
		while (env->y++ < env->image_y)
		{
			i = kawai_info(env);
			while (i++ < env->iter && env->zr * env->zr + env->zi * env->zi < 4)
			{
				env->cr = exp(-0.5 * M_PI * env->zi);
				env->ci = M_PI * env->zr / 2;
				env->zr = env->cr * cos(env->ci);
				env->zi = env->cr * sin(env->ci);
			}
			if (i == env->iter)
				display(env, 0, 0, 0);
			else
				display(env, i * 200 / env->iter - env->blue - 200, i * 200 /
						env->iter - env->green - 200, i * 200 / env->iter
						- env->red - 240);
		}
	}
}

t_env	init_kawai(t_env *env)
{
	env->x1 = -2.0;
	env->x2 = 2.0;
	env->y1 = -2.0;
	env->y2 = 2.0;
	env->red = 750;
	env->green = 1200;
	env->blue = 344;
	env->image_x = env->img.width;
	env->image_y = env->img.height;
	env->iter = 20;
	return (*env);
}
