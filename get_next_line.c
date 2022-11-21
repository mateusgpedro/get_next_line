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
	char static *saved;
	char *result;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (!ft_strchr(saved, '\n'))
		saved = read_and_stash(fd);
	result = get_line(saved);
	saved = clear_found_line(saved);
	return(result);
}

char static	*read_and_stash(int fd)
{
	int		bytes_readen;
	char	*stash;
	char	buf[BUFFER_SIZE + 1];

	bytes_readen = read(fd, buf, BUFFER_SIZE);
	if(bytes_readen < 0)
		return (NULL);
	stash = ft_strjoin(stash, buf);
	free(buf);
	return (stash);
}

int static	*find_newline(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
		if (str[i] == c)
			return (i);
	return (i);
}

char static *get_line(char *saved)
{
	int i;
	int	pos;
	char *result;

	i = 0;
	pos = find_newline(saved);
	result = malloc(sizeof(char) * pos + 1 + 1);
	while(i < pos)
	{
		result[i] = saved[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char static *clear_found_line(char *saved)
{
	int	i;
	int	pos;
	char *new_saved;
	int len = ft_strlen(*saved);

	i = 0;
	pos = find_newline(saved, '\n') + 1;

	new_saved = malloc(sizeof(char) * (len - pos));
	while (saved[pos])
	{
		new_saved[i] = saved[pos];
		i++;
		pos++;
	}
	new_saved[i] = '\0';
	free(*saved);
	return (new_saved);
}

int	main()
{
	int fd;
	char *path = "teste.txt";
	fd = open(path, O_RDONLY);
}
