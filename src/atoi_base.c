/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:16:20 by afelicia          #+#    #+#             */
/*   Updated: 2023/03/06 19:40:36 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	putnbr(int n, char *base)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while(base[i])
	{
		i++;
	}
	
	if (n >= i)
		putnbr(n / i);
	n = n + base[n % i];
}

int	atoi_base(const char *str, int	str_base)
{
	int	i;
	

	while(str[i])
	{
		n = 
	}
}
