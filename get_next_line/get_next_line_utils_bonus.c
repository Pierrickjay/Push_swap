/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:02:18 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 14:24:35 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*creatit(char *str)
{
	int		i;
	char	*newone;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newone = malloc(sizeof(char) * (i + 2));
	if (!newone)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		newone[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newone[i] = '\n';
		i++;
	}
	newone[i] = '\0';
	return (newone);
}

int	ft_strlen_int(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*savetheend(char *str)
{
	char	*newstr;
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i])
	{
		newstr = malloc(sizeof(char) * (ft_strlen_int(str) - i + 1));
		if (!newstr)
			return (NULL);
		i++;
		a = -1;
		while (str[i])
			newstr[++a] = str[i++];
		newstr[++a] = '\0';
		free(str);
		return (newstr);
	}
	free(str);
	return (NULL);
}
