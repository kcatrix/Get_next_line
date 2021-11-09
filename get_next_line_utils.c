/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:45:01 by kcatrix           #+#    #+#             */
/*   Updated: 2021/11/09 13:59:05 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) & s[i]);
	return (0);
}

int	ft_strlenmodif(const char *str)
{
	int	i;
	int	j;
	int cond;

	cond = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			j = 1;
			cond = 1;
		}
		if (cond != 0)
		{
			i++;
			j++;
		}
		i++;
	}
	return (j);
}

int	ft_strlen_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = '\0';
	return (i);
}