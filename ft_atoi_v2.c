/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:23:18 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/20 19:03:35 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_atoi_v2(const char *nptr, int *out)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!*nptr)
		return (0);
	while (*nptr)
	{
		if (!ft_isdigit((unsigned char)*nptr))
			return (0);
		res = res * 10 + (*nptr - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && (sign * res) < INT_MIN))
			return (0);
		nptr++;
	}
	*out = (int)(res * sign);
	return (1);
}
