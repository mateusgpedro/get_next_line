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

static int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}


static char *read_n_stash(int fd, char *stashed)
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

static char *get_line(char *stashed)
{
    int i;
    char *line;

    i = 0;
    if (!stashed[i])
        return (NULL);
    while (stashed[i] && stashed[i] != '\n')
        i++;
    line = ft_calloc((BUFFER_SIZE + 1 + 1), sizeof(char));
    i = 0;
    while (stashed[i] && stashed[i] != '\n')
        line[i++] = stashed[i];
    if (stashed[i] == '\n')
        line[i] = '\n';
    return (line);
}

static char *clear_returned_line(char *stashed)
{
    int i;
    int j;
    char *res;

    i = 0;
    while (stashed[i] && stashed[i] != '\n')
        i++;
    if (!stashed[i])
    {
        free(save);
        return (NULL);
    }
    res = ft_calloc((ft_strlen(stashed) - i)), sizeof(char));
    i++;
    if (!res)
        return (NULL);
    while (stashed[i])
        res[j++] = stashed[i];
    free(stashed);
    return (res);
}

char	*get_next_line(int fd)
{
    char *result;
    static char *stashed;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stashed = read_n_stash(fd, stashed);
    if (!stashed)
        return (NULL);
    result = get_line(stashed);
    stashed = clear_returned_line(stashed);
    return (result);
}
