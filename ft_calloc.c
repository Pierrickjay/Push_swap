/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:35:05 by pjay              #+#    #+#             */
/*   Updated: 2023/01/09 14:35:45 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	unsigned int	count;

	count = size * nmemb;
	if (size == SIZE_MAX || nmemb == SIZE_MAX)
		return (NULL);
	ptr = malloc(count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count);
	return ((void *)ptr);
}
