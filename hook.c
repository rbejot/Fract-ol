/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:26:28 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:27:44 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *env)
{
	if (env->fractype == 1)
		mandelbrot(env);
	else if (env->fractype == 2)
		julia(env);
	else if (env->fractype == 3)
		kawai(env);
	else if (env->fractype == 4)
		glynn(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	return (0);
}

int		key_press(int keycode, t_env *env)
{
	env->change_julia = 0;
	key_tools(keycode, env);
	key_move(keycode, env);
	key_move_bis(keycode, env);
	key_change_frac(keycode, env);
	key_change_fracbis(keycode, env);
	if (keycode == SPACE)
		env->change_julia = 1;
	print_instruction(env);
	return (0);
}

int		motion_notify(int x, int y, t_env *env)
{
	if (env->fractype == 2 && env->change_julia == 1)
	{
		env->cr = (double)(x - 300) / 100;
		env->ci = (double)(y - 300) / 100;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	return (0);
}

void	mouse_zoom(t_env *env, int button, int x, int y)
{
	env->zoom_x = (x * (env->x2 - env->x1) / env->image_x) + env->x1;
	env->zoom_y = (y * (env->y2 - env->y1) / env->image_y) + env->y1;
	if (button == ZOOM)
	{
		env->x1 = env->zoom_x + (env->x1 - env->zoom_x) / 1.1;
		env->x2 = env->zoom_x + (env->x2 - env->zoom_x) / 1.1;
		env->y1 = env->zoom_y + (env->y1 - env->zoom_y) / 1.1;
		env->y2 = env->zoom_y + (env->y2 - env->zoom_y) / 1.1;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (button == DEZOOM)
	{
		env->x1 = env->zoom_x + (env->x1 - env->zoom_x) * 1.1;
		env->x2 = env->zoom_x + (env->x2 - env->zoom_x) * 1.1;
		env->y1 = env->zoom_y + (env->y1 - env->zoom_y) * 1.1;
		env->y2 = env->zoom_y + (env->y2 - env->zoom_y) * 1.1;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
}

int		mouse_event(int button, int x, int y, t_env *env)
{
	mouse_zoom(env, button, x, y);
	if (button == L_CLIC)
	{
		env->iter += 1;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	else if (button == R_CLIC)
	{
		env->blue += 10;
		env->red += 22;
		env->green += 35;
		mlx_destroy_image(env->mlx, env->img.img_ptr);
		new_image(env);
		expose_hook(env);
	}
	print_instruction(env);
	return (0);
}
