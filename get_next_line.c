/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:18:52 by maguimar          #+#    #+#             */
/*   Updated: 2022/11/21 16:49:50 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char *result;
    static char *stashed;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    saved = read_n_stash()
}

char *read_n_stash(int fd, char *stashed)
{
    int bytes_readen;
    char buf[BUFFER_SIZE + 1];
    char *tmp;

    if (ft_strchr(stashed, '\n'))
        return (stashed);
    buf = calloc((BUFFER_SIZE + 1), sizeof(char));
    bytes_readen = 42;
    while (!ft_strchr(stashed, '\n'))
    {
        bytes_readen = read(fd, buf, BUFFER_SIZE);
        if (bytes_readen < 0)
        {
            free (buf);
            return (NULL);
        }
        buffer[bytes_readen] = '\0';
        tmp = ft_strjoin(stashed, buf);
        stashed = tmp;
        free(tmp);
    }
    free(buf);
    return (stashed)
}

char *get_line(char *stashed)
{
    int i;
    char *line;

    i = 0;
    if (!stashed[i])
        return (NULL);
    while (stashed[i] && stashed[i] != '\0')
        i++;
    line = ft_calloc((BUFFER_SIZE + 1 + 1), sizeof(char));
    i = 0;
    while (stashed[i] && stashed[i] != '\0')
        line[i++] = stashed[i];
    if (stashed[i] == '\n')
        line[i] = '\0';
    return (line);
}

char *clear_returned_line(char *stashed)
{
    int i;
    int j;
    char *res;

    i = 0;
    while (stashed[i] && stashed[i] != '\0')
        i++;
    if (!stashed[i])
    {
        free(save);
        return (NULL);
    }
}