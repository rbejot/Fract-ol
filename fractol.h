/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 22:17:41 by rbejot            #+#    #+#             */
/*   Updated: 2016/05/02 22:50:10 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define Z 6
# define X 7
# define W 13
# define S 1
# define A 0
# define D 2
# define SPACE 49
# define RETURN 36
# define C 8
# define V 9
# define N1 18
# define N2 19
# define N3 20
# define N4 21
# define N5 23

# define ZOOM 4
# define DEZOOM 5
# define L_CLIC 1
# define R_CLIC 2

# define WIDTH 700
# define HEIGHT 700

typedef	struct	s_img
{
	void		*img_ptr;
	char		*img;
	int			width;
	int			height;
	int			bits_per_pix;
	int			sz_line;
	int			endian;

}				t_img;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			fractype;
	t_img		img;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			image_x;
	int			image_y;
	int			iter;
	double		zoom_y;
	double		zoom_x;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	int			x;
	int			y;
	int			h;
	int			blue;
	int			green;
	int			red;
	double		xs;
	int			change_julia;
	double		tmp;
}				t_env;

int				expose_hook(t_env *env);
t_env			init_value(t_env *env);
t_env			init_env(t_env *env, int ac, char **av);
void			usage(int warning);
int				check_frac_type(int ac, char **av);
int				key_press(int keycode, t_env *env);
int				mouse_event(int button, int x, int y, t_env *env);
void			mandelbrot(t_env *env);
void			display(t_env *env, int blue, int green, int red);
void			window(t_env *env);
t_env			init_mandel(t_env *env);
int				mandel(t_env *env);
void			new_image(t_env *env);
t_env			init_julia(t_env *env);
void			julia(t_env *env);
t_env			init_kawai(t_env *env);
void			kawai(t_env *env);
t_env			init_glynn(t_env *env);
void			glynn(t_env *env);
void			print_instruction(t_env *env);
int				motion_notify(int x, int y, t_env *env);
void			key_move(int keycode, t_env *env);
void			key_move_bis(int keycode, t_env *env);
void			key_tools(int keycode, t_env *env);
void			key_change_frac(int keycode, t_env *env);
void			key_change_fracbis(int keycode, t_env *env);

#endif
