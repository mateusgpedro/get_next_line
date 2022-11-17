/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:19:31 by maguimar          #+#    #+#             */
/*   Updated: 2022/11/17 14:28:20 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * (s2_len + s1_len + 1));
	if (!new_string)
		return (NULL);
	ft_memcpy(new_string, s1, s1_len);
	ft_memcpy(new_string + s1_len, s2, s2_len + 1);
	return (new_string);
}

void static	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	if ((dest == NULL) && (src == NULL))
	{
		return (NULL);
	}
	index = 0;
	while (index < n)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}
