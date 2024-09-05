#include "minishell.h"

int	ft_b_env(t_env *env)
{
	while (env && env->next != NULL)
	{
		ft_putendl(env->value);
		env = env->next;
	}
	if (env)
		ft_putendl(env->value);
	return (0);
}

// int	main(int i, char **c, char **env)
// {
// 	int	result = 0;

// 	t_meta	dat;
// 	ini_list(&dat);
// 	ft_init_env(&dat, env);

// 	if (i > 1)
// 	{
// 		if (ft_strcmp(c[1], "env") == 0)
//         {
//             c++;
// 			result = ft_b_env(dat.env);
// 			printf("%d", result);
//         }
// 	}
// 	return (result);
// }
