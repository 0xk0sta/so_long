/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:14:51 by acostal-          #+#    #+#             */
/*   Updated: 2021/09/14 17:49:20 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((char)c == '\t' || (char)c == '\n' || (char)c == '\v'
		|| (char)c == '\f' || (char)c == '\r' || (char)c == ' ')
		return (1);
	return (0);
}
