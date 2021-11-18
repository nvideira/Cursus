/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:12:28 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/18 18:37:36 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_storage(char **storage)
{
	unsigned int	i;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	if ((*storage)[i] == '\n' && (*storage)[i + 1] == '\0')
		return (1);
	else
		return (0);
}

char	*buffer_to_str(char *buffer, char *string, char **storage)
{	
	unsigned int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	string = ft_strljoin(string, buffer, i + 1);
	if (buffer[i] == '\n' && buffer[i + 1] != '\0')
	{
		*storage = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	}
	return (string);
}

char	*read_to_buffer(int fd, char *buffer, char *string, char **storage)
{
	int		rd_check;

	if (BUFFER_SIZE < 1)
		return (NULL);
	rd_check = 1;
	while (rd_check > 0 && !ft_strchr(buffer, '\n'))
	{
		rd_check = read(fd, buffer, BUFFER_SIZE);
		string = buffer_to_str(buffer, string, storage);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char		*string;
	static char	*storage;
	char		buffer[BUFFER_SIZE + 1];

	string = "";
	buffer[BUFFER_SIZE] = '\0';
	if (fd < 0)
		return (NULL);
	if (storage)
	{
		string = buffer_to_str(storage, string, &storage);
		if (ft_strchr(storage, '\n'))
		{
			if (check_storage(&storage))
				free(storage);
			return (string);
		}
	}
	if (!ft_strchr(storage, '\n'))
		string = read_to_buffer(fd, buffer, string, &storage);
	return (string);
}

int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
}
