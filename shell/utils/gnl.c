#include "minishell.h"

char	*sh_free_storage(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

char	*sh_store_data(char *storage)
{
	char	*new;
	char	*strchr_nl;
	size_t	line_len;
	size_t	stor_len;

	strchr_nl = gnl_strchr(storage, '\n');
	if (!strchr_nl)
	{
		new = NULL;
		return (sh_free_storage(&storage));
	}
	else
		line_len = (size_t)(strchr_nl - storage) + 1;
	if (!*(storage + line_len))
		return (sh_free_storage (&storage));
	stor_len = ft_strlen(storage) - line_len;
	new = gnl_substr(storage, line_len, stor_len);
	sh_free_storage(&storage);
	if (!new)
		return (NULL);
	return (new);
}

char	*sh_get_line(char *storage)
{
	char	*line;
	char	*strchr_nl;
	size_t	line_len;

	strchr_nl = gnl_strchr(storage, '\n');
	line_len = (size_t)(strchr_nl - storage) + 1;
	line = gnl_substr(storage, 0, line_len);
	if (!line)
		return (NULL);
	return (line);
}

char	*sh_get_fd(char *storage, int fd, int *ret)
{
	char	*buffer;
	int		rd;

	buffer = malloc (sizeof(*buffer) * ((long int)BUFFER_SIZE + 1));
	if (!buffer)
		return (*ret = -1, sh_free_storage (&storage));
	*buffer = '\0';
	rd = 1;
	while (rd > 0 && !(gnl_strchr(buffer, '\n')))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd > 0)
		{
			*(buffer + rd) = '\0';
			storage = gnl_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (rd < 0)
		return (*ret = -1, sh_free_storage (&storage));
	return (storage);
}

// int	ft_newline_check(char *stock, int read_size)
// {
// 	printf("%d", read_size);
// 	if (read_size == 0)
// 	{
// 		if (stock[0] == '\0')
// 			return (2);
// 		else
// 			return (0);
// 	}
// 	printf("%s\n", stock);
// 	while (*stock)
// 	{
// 		if (*stock == '\n')
// 			return (1);
// 		stock++;
// 	}
// 	return (0);
// }

// char	*ft_buff_join(char *stock, char *buff)
// {
// 	int		stock_len;
// 	int		buff_len;
// 	char	*new;

// 	stock_len = 0;
// 	buff_len = ft_strlen(buff);
// 	if (stock)
// 		stock_len = ft_strlen(stock);
// 	new = malloc(stock_len + buff_len + 1);
// 	if (!new)
// 		return (ft_memdel(stock), NULL);
// 	if (stock)
// 	{
// 		ft_memcpy(new, stock, stock_len);
// 		ft_memdel(stock);
// 	}
// 	ft_memcpy(new + stock_len, buff, buff_len + 1);
// 	return (new);
// }

// char	*ft_stock_trim(char *stock)
// {
// 	int		i;
// 	char	*trimmed;

// 	i = 0;
// 	while (stock[i] != '\n' && stock[i] != '\0')
// 		i++;
// 	if (stock[i] == '\0')
// 		return (ft_memdel(stock));
// 	trimmed = ft_strdup(stock + i + 1);
// 	ft_memdel(stock);
// 	return (trimmed);
// }

// char	*ft_get_line(char *stock)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	while (stock[i] && stock[i] != '\n')
// 		i++;
// 	line = malloc(i + 1);
// 	if (!line)
// 		return (NULL);
// 	ft_memcpy(line, stock, i);
// 	line[i] = '\0';
// 	return (line);
// }
