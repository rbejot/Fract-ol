/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:16:27 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:17:01 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display(t_env *env, int blue, int green, int red)
{
	env->img.img[env->y * env->img.sz_line + env->x * env->img.bits_per_pix
		/ 8] = blue;
	env->img.img[env->y * env->img.sz_line + env->x * env->img.bits_per_pix /
		8 + 1] = green;
	env->img.img[env->y * env->img.sz_line + env->x * env->img.bits_per_pix /
		8 + 2] = red;
}
