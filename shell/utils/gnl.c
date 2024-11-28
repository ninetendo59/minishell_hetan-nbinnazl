#include "minishell.h"

// int	ft_newline_check(char *stack, int read_size)
// {
// 	int	i;

// 	i = 0;
// 	if (read_size == 0 && stack[0] == '\0')
// 		return (2);
// 	if (read_size == 0 || stack == NULL)
// 		return (0);
// 	while (stack[i] != '\0')
// 	{
// 		if (stack[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_buff_join(char *stack, char *buf)
// {
// 	int		i;
// 	int		j;
// 	char	*new;

// 	i = 0;
// 	j = 0;
// 	while (stack != NULL && stack[i] != '\0')
// 		i++;
// 	while (buf[j] != '\0')
// 		j++;
// 	new = malloc((i + j + 1));
// 	if (!new)
// 		return (ft_memdel(stack));
// 	i = 0;
// 	j = 0;
// 	while (stack != NULL && stack[i] != '\0')
// 		new[i++] = stack[j++];
// 	j = 0;
// 	while (buf[j] != '\0')
// 		new[i++] = buf[j++];
// 	new[i] = '\0';
// 	if (stack != NULL)
// 		ft_memdel(stack);
// 	return (new);
// }

// char	*ft_trim(char *stack)
// {
// 	int		i;
// 	int		j;
// 	char	*trim;

// 	i = 0;
// 	j = 0;
// 	while (stack[i] != '\n' && stack[i] != '\0')
// 		i++;
// 	while (stack[i++] != '\0')
// 		j++;
// 	trim = malloc(j + 1);
// 	if (!trim)
// 		return (ft_memdel(stack));
// 	i = 0;
// 	j = 0;
// 	while (stack[i] != '\n' && stack[i] != '\0')
// 		i++;
// 	if (stack[i] == '\0')
// 		i--;
// 	i++;
// 	while (stack[i] != '\0')
// 		trim[j++] = stack[i++];
// 	trim[j] = '\0';
// 	ft_memdel(stack);
// 	return (trim);
// }

// char	*ft_get_line(char *stack)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	while (stack[i] != '\n' && stack[i] != '\0')
// 		i++;
// 	line = malloc(i + 1);
// 	if (!line)
// 		return (ft_memdel(stack));
// 	i = 0;
// 	while (stack[i] != '\n' && stack[i] != '\0')
// 	{
// 		line[i] = stack[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }
