/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:47:05 by afelicia          #+#    #+#             */
/*   Updated: 2023/03/14 18:16:25 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>

int	mouse_event(int button, int x, int y, void *param);
typedef struct s_param
{
	void *mlx;
	void *win;
}	t_param;

int	main()
{
	void *mlx;
	void *win;
	int x = 0;
	int y = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "nadaxd");

	while(x <= 1000 && y <= 1000)
	{
		mlx_pixel_put(mlx, win, x, y, 0xFF5733);
		x++;
		y++;
	}

	t_param param = {mlx, win};
	mlx_mouse_hook(win, &mouse_event, &param);

	mlx_loop(mlx);
}

int	mouse_event(int button, int x, int y, void *param)
{
	void *mlx = ((t_param*)param)->mlx;
	void *win = ((t_param*)param)->win;
	int	radius = 20;
	
	int i = x - radius;
	int j = y - radius;
	while(i < x)
	{
		while(j < y + radius)
		{
			if(sqrt((i - x) * (i - x) + (j - y) * (j - y)) <= radius)
				mlx_pixel_put(mlx, win, i, j, 0xFF5733);
			j++;
		}
		i++;
	}

	printf("%d", button);
	return(0);
}
