/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/03/29 01:13:28 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void current_dir(void)
{
    char *cwd;
    
    cwd = malloc(sizeof(*cwd) * (BUFFER_SIZE + 1));
    if (!cwd)
        return ;
    write(1, "MINISHELL:", strlen("MINISHELL:"));
    if (getcwd(cwd, BUFFER_SIZE + 1) != NULL)
        write(1, cwd, strlen(cwd));
    else
    {
        perror("getcwd() error");
        free(cwd);
        return ;
    }
    write(1, "$>", 2);
    free(cwd);
}

// void ctrl_c(int sig)
// {
//     write(1, "\n", 1);
//     current_dir(NULL);
// }

// void check_sig(char *cmd)
// {
//     signal(SIGINT, ctrl_c);
//     signal(SIGQUIT, SIG_IGN);
//     return ;
// }

int main(void)
{
    char *cmd;
    ssize_t len;

    cmd = malloc(sizeof(*cmd) * (BUFFER_SIZE + 1));
    if (!cmd)
        exit(1);
    len = 0;
    check_sig();
    len = 0;
    while (1)
    {
        current_dir();
        len = read(STDIN_FILENO, cmd, BUFFER_SIZE);
        if (len <= 0)
        {
            free(cmd);
            exit(0);
        }
        *(cmd + len) = '\0';
        // shell_cmd(cmd);
    }
    exit(0);
}