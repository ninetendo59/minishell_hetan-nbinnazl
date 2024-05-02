/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:42:46 by hetan             #+#    #+#             */
/*   Updated: 2024/01/03 02:55:59 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> 
//required for write()
# include <stdlib.h>
//required for size_t, malloc, free (iForgor)

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
//create struct based on extras

t_list	*ft_lstnew(void *content);
//bonus , add a new member
t_list	*ft_lstlast(t_list *lst);
//bonus , show value of last person
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//bonus, almost same as strmapi but with list and structure

char	*ft_strdup(const char *str);
//just duplicate a str, almost same as memcpy but slightly different k..
char	*ft_strchr(const char *str, int c);
//just looking for a character from a string given.
char	*ft_strrchr(const char *str, int c);
//looking for last occured character
char	*ft_strnstr(const char *hay, const char *need, size_t size);
//looking for a string from a string by given a specific size onto the haystack
char	*ft_strjoin(char const *s1, const char *s2);
//same as cat but just need to create a new memory....
char	*ft_substr(const char *s, unsigned int start, size_t len);
//submissive string? jk it is just perform substring extraction
char	*ft_strtrim(char const *s1, char const *set);
//basically just trim the set from the s1, then return back the trimmed char...
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//strmapi? mapping? no... is just.. create new string with modded char 
char	*ft_itoa(int n);
// convert from integer into ascii, basically hard job
char	**ft_split(char const *s, char c);
//split?! yeah, split string when meet the condition c

int		ft_strncmp(const char *s1, const char *s2, size_t n);
// compare 2 strings with given size.
int		ft_isprint(int c);
//check if it is printable ascii charcter....
int		ft_isdigit(int c);
// check if it is ascii digit, if not then... k
int		ft_isascii(int c);
//check is it ascii, if not ascii, k den
int		ft_isalpha(int c);
// check is it alphabet.
int		ft_isalnum(int c);
//check is it alphanumeric, yes or no, will return base on on and off binary
int		ft_toupper(int c);
//convert lower to UPPER
int		ft_tolower(int c);
//convert UPPER to lower
int		ft_memcmp(const void *s1, const void *s2, size_t num);
//comparing blocks of memory between s1 and s2, if same then return eggsey
int		ft_atoi(const char *str);
//convert ascii numbers 0-9 into integer number
int		ft_lstsize(t_list *lst);
//bonus, just strlen the list from structure

size_t	ft_strlen(const char *str);
//bascially calculate how many characters in a string
size_t	ft_strlcat(char *dest, const char *src, size_t size);
//strlen string been cat btw src and dest with given size to be cat
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
//strlen how much string is being copied to dest with given size

void	*ft_memcpy(void *dest, const void *src, size_t n);
//duplicate a block of memory from a source to a destination
void	ft_bzero(void *str, size_t n);
//emptied out all possible filled memory blocks.
void	*ft_calloc(size_t count, size_t size);
//malloc but simplified. basically no need to put steward formulae
void	*ft_memset(void *name, int c, size_t size);
//do new memory block w given size and c is the filler of each mem block
void	*ft_memmove(void *dest, const void *src, size_t num);
//moving a block of memory from source to destination with a specific size
void	*ft_memchr(const void *str, int c, size_t size);
//looking for a char in a block of memory of a string
void	ft_putchar_fd(char c, int fd);
//print out characters to fd
void	ft_putstr_fd(char *s, int fd);
//print out string to fd
void	ft_putnbr_fd(int n, int fd);
//convert integer become printable ascii number to fd
void	ft_putendl_fd(char *s, int fd);
//print end line after string with fd, basically to a specific path
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
//string iteration

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//bonus, squid game remove one people
void	ft_lstadd_front(t_list **lst, t_list *new);
//bonus, just add a list infront, basically unethical sea(synonym) cut up queue
void	ft_lstclear(t_list **lst, void (*del)(void *));
//bonus, just clear rubbish from my structure listssss
void	ft_lstadd_back(t_list **lst, t_list *new);
//bonus, add at the back of the list from struct (ethical homie)
void	ft_lstiter(t_list *lst, void (*f)(void *));
//bonus , iterate with structure

#endif