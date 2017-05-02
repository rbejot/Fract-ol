/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:51:03 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:28:59 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_image(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->mlx, env->img.width, env->img.height);
	env->img.img = mlx_get_data_addr(env->img.img_ptr, &env->img.bits_per_pix,
			&env->img.sz_line, &env->img.endian);
}

void	window(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->img.width, env->img.height,
			"Fract'ol");
}
