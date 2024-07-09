/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:17:46 by lberne            #+#    #+#             */
/*   Updated: 2024/07/05 16:53:34 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("malloc error :(");
	exit(EXIT_FAILURE);
}

// @$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
// 	ft_printf("\n$(On_White)-------------------------------------------------------------------------------------$(END)"
// 	ft_printf("\n$(UWhite)Use following command :$(END)                                                          \n"
// 	ft_printf("              $(BICyan)./fractol mandelbrot\n$(END)                                               "
// 	ft_printf("$(BWhite)OR\n                                                                                     "
// 	ft_printf("              $(BIPurple)./fractol julia [x] [y]$(END)\n\n                                        "
// 	ft_printf("\n$(UWhite)Some interesting examples :$(END)\n                                                    "
// 	ft_printf("$(BIYellow)\n[0,3][0,5]      [0,285][0,01]                                                        "
// 	ft_printf("[0,285][0,013]  [0,285][0,013]\n\n$(END)                                                          "
// 	ft_printf("$(On_White)-------------------------------------------------------------

void	display_instructions(void)
{	
	ft_printf("\n \033[47m                                           \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[4;37mUse following command :\033[0m                 \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[1;96m./fractol mandelbrot\033[0m                    \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[1;37mOR                                      \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[1;95m./fractol julia [x] [y]\033[0m                 \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[4;37mSome interesting examples :\033[0m             \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[1;93m[0.3][0.5]      [0.285][0.01]\033[0m           \033[47m \033[0m\n");
	ft_printf(" \033[47m \033[0m \033[1;93m[-1.476][0]     [-0.12][-0.77]\033[0m          \033[47m \033[0m\n");
	ft_printf(" \033[47m                                           \033[0m\n\n");
	// ft_printf("\nUse following command :\n\n");
	// ft_printf("              ./fractol mandelbrot\n");
	// ft_printf("OR\n");
	// ft_printf("              ./fractol julia [x] [y]\n\n");
	// ft_printf("Some interesting examples :\n\n");
	// ft_printf("[0.3][0.5]      [0.285][0.01]\n");
	// ft_printf("[0.285][0.013]  [0.285][0.013]\n\n");
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
