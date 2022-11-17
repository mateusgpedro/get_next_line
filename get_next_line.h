/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:19:34 by maguimar          #+#    #+#             */
/*   Updated: 2022/11/17 14:28:52 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

/*--  UTILS  --*/
char	*ft_strjoin(char const *s1, char const *s2);

#endif
