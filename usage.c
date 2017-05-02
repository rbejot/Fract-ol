/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:35:33 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:36:08 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instruction(t_env *env)
{
	if (env->fractype == 1)
		mlx_string_put(env->mlx, env->win, 5, 10, 0x00FFFFFF, "MANDELBROT");
	else if (env->fractype == 2)
	{
		mlx_string_put(env->mlx, env->win, 5, 10, 0x00FFFFFF, "JULIA");
		mlx_string_put(env->mlx, env->win, 5, 70, 0x00FFFFFF,
				"SPACE to change parameters");
	}
	else if (env->fractype == 3)
		mlx_string_put(env->mlx, env->win, 5, 10, 0x00FFFFFF, "KAWAIII");
	else if (env->fractype == 4)
		mlx_string_put(env->mlx, env->win, 5, 10, 0x00FFFFFF, "GLYNN");
	mlx_string_put(env->mlx, env->win, 5, 30, 0x00FFFFFF,
			"1 - 4 to change fractal");
	mlx_string_put(env->mlx, env->win, 5, 50, 0x00FFFFFF, "RETURN to reset");
	mlx_string_put(env->mlx, env->win, 400, 10, 0x00FFFFFF,
			"ARROW KEY to move");
	mlx_string_put(env->mlx, env->win, 400, 30, 0x00FFFFFF,
			"LEFT CLIC to iterate");
	mlx_string_put(env->mlx, env->win, 400, 50, 0x00FFFFFF,
			"RIGHT CLIC to change color");
	mlx_string_put(env->mlx, env->win, 400, 70, 0x00FFFFFF, "SCROLL to zoom");
}

void	usage(int warning)
{
	if (warning == 1)
	{
		ft_putchar('\n');
		ft_putendl("Please retry with ONE of the folowing parameters :");
		ft_putendl("           M for Mandelbrot");
		ft_putendl("           J for Julia");
		ft_putendl("           K for Kawai <3");
		ft_putendl("           G for Glynn");
		ft_putchar('\n');
		exit(1);
	}
}
