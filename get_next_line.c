#include "get_next_line.h"

char 	*end(char **stock)
{
	if (compteur_sot(*stock) < 0 && (*stock))
		return (*stock);
	else if (compteur_sot(*stock) >= 0)
		return(after(stock, compteur_sot(*stock)));
	return (NULL);
}

char	*after(char	**stock, int i)
{
	char	*tmpbefore;
	char	*tmpafter;
	
	tmpafter = NULL;
	if (ft_strlen(*stock + i + 1) > 0)
		tmpafter = ft_strdup(*stock + i + 1);
	(*stock)[i + 1] = '\0';
	tmpbefore = ft_strdup(*stock);
	free(*stock);
	*stock = tmpafter;
	return (tmpbefore);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stock != NULL && compteur_sot(stock) >= 0)
		return(after(&stock, compteur_sot(stock)));
	nb_char = read(fd, buff, BUFFER_SIZE);
	if (nb_char <= 0)
			return (NULL);
	while(nb_char > 0)
	{
		buff[nb_char] = '\0';
		stock = ft_strjoin(stock, buff);
		if (compteur_sot(stock) >= 0)
			return(after(&stock, compteur_sot(stock)));
		nb_char = read(fd, buff, BUFFER_SIZE);
	}
	return(end(&stock));
}
int	main()
{
	int i;
	
	i = 0;
	int fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}