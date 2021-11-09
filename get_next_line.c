/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:45:06 by kcatrix           #+#    #+#             */
/*   Updated: 2021/11/09 14:33:30 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t count;
	char	*str;
	static char	*strrec;
	
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	count = read(fd, str, BUFFER_SIZE);
	strrec = malloc(sizeof(char *) * ft_strlenmodif(str));
	strrec = ft_strchr(str, '\n');
	printf("strrec = %s\n", strrec);
	return (str);
}
int	main()
{
	char	*str;
	int i;
	
	i = 0;
	int fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str[i] && str[i] != '\n')
		write(1, &str[i++], 1);
}