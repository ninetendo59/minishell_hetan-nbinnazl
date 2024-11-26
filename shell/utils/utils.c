#include "minishell.h"

void	ft_skip_whitespace(const char *str, int *i)
{
	if (!str || !i)
		return ;
	while ((str[*i] == ' ' || str[*i] == '\t')
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
	int			read_len;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	read_len = 1;
	while (!(ft_newline_check(stock, read_len)))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (-1);
		buf[read_len] = '\0';
		if (read_len == 0 || buf[read_len - 1] != '\n')
			ft_printf("  \b\b");
		stock = ft_buff_join(stock, buf);
		if (stock == NULL)
			return (-1);
	}
	*line = stock;
	if (ft_newline_check(stock, read_len) == 2 && *line)
		return (-2);
	*line = ft_get_line(stock);
	if ((*line) == NULL)
		return (-1);
	stock = ft_trim(stock);
	if (stock)
		return (-1);
	ft_memdel(stock);
	if (read_len != 0)
		return (1);
	else
		return (0);
}
