/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:16:20 by afelicia          #+#    #+#             */
/*   Updated: 2023/03/07 14:37:10 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	color_converter(const char *str)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 0;
	result = 0;
	while(str[i])//A4
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10;
		else
			printf("bad color input");
		i++;
		result = result * 16 + n;
	}
	return (result);
}

int	main()
{
	char *str = "FF2E00";
	int	result = color_converter(str);
	printf("%d", result);
}
