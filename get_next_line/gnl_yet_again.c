/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_yet_again.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:52:20 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/26 17:44:13 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_those_lines(int fd, char *storage)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*strider;
	char	*aragorn;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		if (storage != NULL)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	buffer[bytes] = '\0';
	strider = ft_strdup(buffer);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		aragorn = ft_strjoin(strider, buffer);
		free(strider);
		strider = ft_strdup(aragorn);
		free(aragorn);
	}
	return (strider);
}

char	*add_update_storage(char *storage)
{
	int		i;
	char	*return_of_the_string;
	char	*wick;

	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	return_of_the_string = ft_substr(storage, 0, i + 1);
	if (ft_strlen(storage) != i)
	{
		wick = ft_substr(storage, i + 1, ft_strlen(storage));
		free(storage);
		storage = ft_strdup(wick);
		free(wick);
	}
	return (return_of_the_string);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*aragorn;
	char		*strider;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (storage)
	{
		aragorn = add_update_storage(storage);
		if (ft_strchr(aragorn, '\n'))
			return (aragorn);
	}
	strider = read_those_lines(fd, storage);
}
