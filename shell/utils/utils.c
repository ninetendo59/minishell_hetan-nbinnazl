#include "minishell.h"

void	ft_skip_whitespace(const char *str, int *i)
{
	if (!str || !i)
		return ;
	// while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
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

int	ft_get_next_line(int fd, char **m_line)
{
	char		*line;
	int			ret;
	static char	*storage[BUFFER_SIZE];

	if (fd < 0 || !m_line || BUFFER_SIZE < 1)
		return (-1);
	line = *m_line;
	ret = 0;
	if (!storage[fd] || (storage[fd] && !gnl_strchr (storage[fd], '\n')))
		storage[fd] = sh_get_fd(storage[fd], fd, &ret);
	if (!storage[fd] || ret == -1)
		return (-1);
	line = sh_get_line (storage[fd]);
	if (!line)
		return (sh_free_storage (&storage[fd]), -1);
	storage[fd] = sh_store_data (storage[fd]);
	return (ret);
}
