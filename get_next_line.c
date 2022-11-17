/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:18:52 by maguimar          #+#    #+#             */
/*   Updated: 2022/11/17 15:05:58 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

}

//find n stash
char	*find_and_stash(int fd)
{
	char buf[BUFFER_SIZE + 1];
	char *stash;
	int bytes_readen;

	bytes_readen = read(fd, buf, BUFFER_SIZE + 1);

	stash = ft_strjoin(stash, buf);
}

// find new line
int	find_new_line(char *str, char c)
{
	int	i;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

//get the result


//free the result
