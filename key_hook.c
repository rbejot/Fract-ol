/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:08:19 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:35:01 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_move(int keycode, t_env *env)
{
	if (keycode == RIGHT)
	{
		env->x1 += (env->x2 - env->x1) / env->image_x * 10;
		env->x2 += (env->x2 - env->x1) / env->image_x * 10;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (keycode == LEFT)
	{
		env->x1 -= (env->x2 - env->x1) / env->image_x * 10;
		env->x2 -= (env->x2 - env->x1) / env->image_x * 10;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}

void	key_move_bis(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		env->y1 -= (env->y2 - env->y1) / env->image_y * 10;
		env->y2 -= (env->x2 - env->x1) / env->image_y * 10;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (keycode == DOWN)
	{
		env->y1 += (env->y2 - env->y1) / env->image_y * 10;
		env->y2 += (env->x2 - env->x1) / env->image_y * 10;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}

void	key_tools(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == RETURN)
	{
		init_value(env);
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}

void	key_change_frac(int keycode, t_env *env)
{
	if (keycode == N1)
	{
		if (env->fractype != 1)
		{
			env->fractype = 1;
			init_value(env);
		}
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (keycode == N2)
	{
		if (env->fractype != 2)
		{
			env->fractype = 2;
			init_value(env);
		}
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}

void	key_change_fracbis(int keycode, t_env *env)
{
	if (keycode == N3)
	{
		if (env->fractype != 3)
		{
			env->fractype = 3;
			init_value(env);
		}
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (keycode == N4)
	{
		if (env->fractype != 4)
		{
			env->fractype = 4;
			init_value(env);
		}
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}
