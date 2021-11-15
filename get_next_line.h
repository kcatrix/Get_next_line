#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		compteur_sot(char *stock);
char	*after(char	**stock, int i);
char 	*end(char **stock);
int		main();

#endif