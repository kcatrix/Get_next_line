/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:17:55 by kcatrix           #+#    #+#             */
/*   Updated: 2021/11/22 11:20:08 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*end(char **stock)
{
	char	*line;

	line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	return (line);
}

char	*after(char	**stock, int i)
{
	char	*tmpafter;
	char	*save;

	tmpafter = ft_substr(*stock, 0, i + 1);
	if (ft_strlen(*stock + i + 1) > 0)
	{	
		save = ft_strdup(*stock + i + 1);
		free(*stock);
		*stock = ft_strdup(save);
		free(save);
	}
	else
	{
		free(*stock);
		*stock = NULL;
	}
	return (tmpafter);
}

int	compteur_sot(char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	int			nb_char;
	char		buff[BUFFER_SIZE + 1];
	static char	*stock;

	nb_char = 1;
	if (stock)
	{
		if (compteur_sot(stock) != -1)
			return (after(&stock, compteur_sot(stock)));
	}
	while (nb_char > 0)
	{
		nb_char = read(fd, buff, BUFFER_SIZE);
		if (fd < 0 || (nb_char <= 0 && !stock))
			return (NULL);
		buff[nb_char] = '\0';
		stock = ft_strjoin(stock, buff);
		if (compteur_sot(stock) >= 0)
			return (after(&stock, compteur_sot(stock)));
	}
	return (end(&stock));
}
