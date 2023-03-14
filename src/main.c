/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:47:05 by afelicia          #+#    #+#             */
/*   Updated: 2023/03/07 15:21:26 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int mouse_event(int buttom, int x, int y, void *param)
{
    // Whenever the event is triggered, print the value of button to console.
    printf("%d", buttom);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	int	x = 0;
	int y = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "nada");
	
	while(x <= 1000 && y <= 1000)
	{	
		mlx_pixel_put(mlx, win, x, y, 0xFF5733);
		x++;
		y++;
	}

	mlx_mouse_hook(win, &mouse_event, 0);
	
	mlx_loop(mlx);
}


