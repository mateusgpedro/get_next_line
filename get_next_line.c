/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:18:52 by maguimar          #+#    #+#             */
/*   Updated: 2022/11/25 14:14:48 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*read_n_stash(int fd, char *stashed)
{
	int		bytes_readen;
	char	*buf;
	char	*tmp;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_readen = 42;
	while (!ft_strchr(buf, '\n') && bytes_readen > 0)
	{
		bytes_readen = read(fd, buf, BUFFER_SIZE);
		if (bytes_readen < 0)
		{
			if (stashed)
				free (stashed);
			free (buf);
			return (NULL);
		}
		buf[bytes_readen] = '\0';
		tmp = ft_strjoin(stashed, buf);
		free(stashed);
		stashed = tmp;
	}
	free(buf);
	return (stashed);
}

static char	*get_line(char *stashed)
{
	int		i;
	char	*line;

	i = 0;
	if (!stashed[i])
		return (NULL);
	while (stashed[i] && stashed[i] != '\n')
		i++;
	line = ft_calloc((i + 1 + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stashed[i] && stashed[i] != '\n')
	{
		line[i] = stashed[i];
		i++;
	}
	line[i] = stashed[i];
	return (line);
}

static char	*clear_returned_line(char *stashed)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (stashed[i] && stashed[i] != '\n')
		i++;
	if (!stashed[i])
	{
		free(stashed);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(stashed) - i), sizeof(char));
	i++;
	j = 0;
	while (stashed[i])
		res[j++] = stashed[i++];
	free(stashed);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*stashed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stashed = read_n_stash(fd, stashed);
	if (!stashed)
		return (NULL);
	result = get_line(stashed);
	stashed = clear_returned_line(stashed);
	return (result);
}
/*
int	main()
{
	char *path = "teste.txt";
	int fd = open(path, O_RDONLY);
	printf("%s", get_next_line(fd));
} */
