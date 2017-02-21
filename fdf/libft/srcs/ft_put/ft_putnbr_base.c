/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:50:32 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/09 18:04:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (i);
}

static void				limite(long int n, char *base, int nb_base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= nb_base)
		limite(n / nb_base, base, nb_base);
	ft_putchar(base[(n % nb_base)]);
}

void					ft_putnbr_base_long(unsigned int nbr, char *base)
{
	unsigned int	nb_base;

	nb_base = ft_check_base(base);
	if (nb_base > 1)
	{
		if (nbr >= nb_base)
			ft_putnbr_base_long(nbr / nb_base, base);
		ft_putchar(base[(nbr % nb_base)]);
	}
}

void					ft_putnbr_base(int nbr, char *base)
{
	int						nb_base;
	long int				n;

	nb_base = ft_check_base(base);
	if (nbr == -2147483648 && nb_base > 1)
	{
		n = -2147483648;
		limite(n, base, nb_base);
	}
	else if (nb_base > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= nb_base)
			ft_putnbr_base(nbr / nb_base, base);
		ft_putchar(base[(nbr % nb_base)]);
	}
}
