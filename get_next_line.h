/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulmoud <ooulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:59:59 by ooulmoud          #+#    #+#             */
/*   Updated: 2024/03/04 20:45:39 by ooulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 6
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*get_line_befor(char *str);
char	*get_next(char *str);
char	*ft_strdup(char *str);
char	*ft_allocation(char *s1, char *s2, char *s);
char	*check1(char *s1, char *s2);
void	check2(int rd, char *s1, char *s2);

#endif