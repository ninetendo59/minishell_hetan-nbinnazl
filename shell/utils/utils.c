#include "minishell.h"

static int	ft_extract_line(char **stock, char **line)
{
	*line = ft_get_line(*stock);
	if (!*line)
		return (-1);
	*stock = ft_stock_trim(*stock);
	return (1);
}

void	ft_skip_whitespace(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}

int	ft_syntax_error(t_meta *minishell, char *token_str)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putstr_fd(token_str, 2);
	ft_putendl_fd("'", 2);
	minishell->ret = 258;
	return (0);
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*stock;
	char		buf[BUFFER_SIZE + 1];
	int			read_len;

	stock = NULL;
	read_len = 1;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	while (!ft_newline_check(stock, read_len))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
		{
			if (read_len)
				return (-1);
			return (0);
		}
		buf[read_len] = '\0';
		stock = ft_buff_join(stock, buf);
		if (!stock)
			return (-1);
	}
	if (ft_newline_check(stock, read_len) == 2)
		return (*line = stock, stock = NULL, -2);
	return (ft_extract_line(&stock, line));
}
