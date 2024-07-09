/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:19:08 by lberne            #+#    #+#             */
/*   Updated: 2024/07/05 16:33:03 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; 	 // mlx_new_window()
	//Image
	t_img	img;

	//Hooks member variables //TODO
	double	escape_value; // hypotenuse
	int		iterations_defintion; // value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct	s_complex
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex;

#define WIDTH	800
#define	HEIGHT	800

#define BLACK       		0x000000
#define WHITE      			0xFFFFFF
#define RED         		0xFF0000
#define GREEN       		0x00FF00
#define BLUE        		0x0000FF
#define MAGENTA_BURST   	0xFF00FF
#define LIME_SHOCK      	0xCCFF00
#define NEON_ORANGE     	0xFF6600 
#define PSYCHEDELIC_PURPLE 	0x660066
#define AQUA_DREAM      	0x33CCCC
#define HOT_PINK        	0xFF66B2
#define ELECTRIC_BLUE   	0x0066FF
#define LAVA_RED        	0xFF3300
#define	NEON_PINK			0xFF10F0

void	malloc_error(void);
void	display_instructions(void);
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
int	close_handler(t_fractal *fractal);
int	key_handler(int keysym, t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
//int	julia_track(int x, int y, t_fractal *fractal);

#endif