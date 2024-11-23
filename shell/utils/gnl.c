#include "minishell.h"

int	ft_newline_check(char *stock, int read_size)
{
	if (read_size == 0)
	{
		if (stock[0] == '\0')
			return (2);
		else
			return (0);
	}
	while (*stock && stock != NULL)
	{
		if (*stock == '\n')
			return (1);
		stock++;
	}
	return (0);
}

char	*ft_buff_join(char *stock, char *buff)
{
	int		stock_len;
	int		buff_len;
	char	*new;

	stock_len = 0;
	buff_len = ft_strlen(buff);
	if (stock)
		stock_len = ft_strlen(stock);
	new = malloc(stock_len + buff_len + 1);
	if (!new)
		return (ft_memdel(stock), NULL);
	if (stock)
	{
		ft_memcpy(new, stock, stock_len);
		ft_memdel(stock);
	}
	ft_memcpy(new + stock_len, buff, buff_len + 1);
	return (new);
}

char	*ft_stock_trim(char *stock)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\0')
		return (ft_memdel(stock));
	trimmed = ft_strdup(stock + i + 1);
	ft_memdel(stock);
	return (trimmed);
}

char	*ft_get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stock, i);
	line[i] = '\0';
	return (line);
}
