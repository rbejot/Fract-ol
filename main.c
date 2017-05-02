/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:50:05 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:14:51 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		init_value(t_env *env)
{
	if (env->fractype == 1)
		init_mandel(env);
	else if (env->fractype == 2)
		init_julia(env);
	else if (env->fractype == 3)
		init_kawai(env);
	else if (env->fractype == 4)
		init_glynn(env);
	return (*env);
}

int			check_frac_type(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		usage(1);
	if (av[1][0] == 'M' && av[1][1] == '\0')
		return (1);
	else if (av[1][0] == 'J' && av[1][1] == '\0')
		return (2);
	else if (av[1][0] == 'K' && av[1][1] == '\0')
		return (3);
	else if (av[1][0] == 'G' && av[1][1] == '\0')
		return (4);
	else
		usage(1);
	return (0);
}

t_env		init_env(t_env *env, int ac, char **av)
{
	env->img.width = WIDTH;
	env->img.height = HEIGHT;
	env->fractype = check_frac_type(ac, av);
	init_value(env);
	return (*env);
}

int			main(int ac, char **av)
{
	t_env	*env;

	env = (t_env*)ft_memalloc(sizeof(t_env));
	init_env(env, ac, av);
	window(env);
	new_image(env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_press, env);
	mlx_mouse_hook(env->win, mouse_event, env);
	mlx_hook(env->win, 6, (1L >> 0), &motion_notify, env);
	mlx_loop(env->mlx);
	return (0);
}
