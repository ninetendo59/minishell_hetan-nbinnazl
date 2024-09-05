#include "minishell.h"

void	ft_b_exit(t_meta *minishell)
{
	minishell->exit = 1;
	ft_putendl_fd("MINISHELL: Successfully exited.", 2);
	minishell->ret = 0;
}

// int	main(int i, char **c)
// {
// 	int	result = 0;

// 	t_meta	dat;
// 	ini_list(&dat);

// 	if (i > 1)
// 	{
// 		if (ft_strcmp(c[1], "exit") == 0)
//         {
//             c++;
// 			// result = 
// 			ft_b_exit(&dat);
//         }
// 	}
// 	return (result);
// }