/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:17:46 by lberne            #+#    #+#             */
/*   Updated: 2024/07/15 12:54:48 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("malloc error :(");
	exit(EXIT_FAILURE);
}

void	display_instructions(void)
{
	ft_printf("\n \033[47m                                \033[0m\n");
	ft_printf(" \033[4;37mUse the following commands :\033[0m   \033[47m \033[0m\n");
	ft_printf(" \033[1;96m./fractol mandelbrot\033[0m           \033[47m \033[0m\n");
	ft_printf(" \033[1;37mOR                             \033[47m \033[0m\n");
	ft_printf(" \033[1;95m./fractol julia [x] [y]\033[0m        \033[47m \033[0m\n");
	ft_printf(" \033[4;37mSome interesting examples :\033[0m    \033[47m \033[0m\n");
	ft_printf(" \033[1;93m[0.3][0.5]      [0.285][0.01]\033[0m  \033[47m \033[0m\n");
	ft_printf(" \033[1;93m[-1.476][0]     [-0.12][-0.77]\033[0m \033[47m \033[0m\n");
	ft_printf(" \033[47m                                \033[0m\n\n");
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		fractal.name = "mandelbrot";
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = "julia";
		fractal.julia_x = ft_ato_float(av[2]);
		fractal.julia_y = ft_ato_float(av[3]);
	}
	else
	{
		display_instructions();
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
