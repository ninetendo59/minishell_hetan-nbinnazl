/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:49:15 by hetan             #+#    #+#             */
/*   Updated: 2024/01/03 03:00:02 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//buffer size when it's not declared
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//maximum fd as standard in mac is 256 and current standard is 1024
# ifndef MAX_FD
#  define MAX_FD 10240
# endif
# include <unistd.h>//read()
# include <stdlib.h>//malloc(), free()
# include <stdio.h> // tester purpose
# include <fcntl.h> // tester purpose
# include <string.h> // tester purpose
# include "libft.h"

//utilities from libft
char	*gnl_strjoin(char *dest, char *src); //joining 2 strings
char	*gnl_substr(char *s, unsigned int start, size_t len);//extract string
char	*gnl_strchr(char *str, int c); //purpose to find \n
size_t	gnl_strlcpy(char *dest, char *src, size_t size);

//gnl related
char	*get_next_line(int fd);//the main function of gnl
char	*ft_get_fd(char *storage, int fd);//read the opened fd
char	*ft_store_data(char *storage);//clean the unecessary value
char	*ft_get_line(char *storage);//extracting 
char	*free_storage(char	**storage);//free the mem of str that used by line

#endif
