/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:12:28 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/22 23:37:58 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*add_update_storage(char *string, char **storage)
{
	unsigned int	i;
	char			*vivi;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	vivi = ft_strljoin(string, *storage, i + 1);
	free(string);
	string = ft_strdup(vivi);
	free(vivi);
	vivi = NULL;
	if ((*storage)[i] == '\n' && (*storage)[i + 1] != '\0')
	{
		vivi = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
		free(*storage);
		*storage = ft_strdup(vivi);
		free(vivi);
		vivi = NULL;
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (string);
}

char	*buffer_to_str(char *buffer, char *string, char **storage)
{	
	unsigned int	i;
	char			*soba;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	soba = ft_strljoin(string, buffer, i + 1);
	free(string);
	string = ft_strdup(soba);
	free(soba);
	soba = NULL;
	if (buffer[i] == '\n' && buffer[i + 1] != '\0')
	{
		soba = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
		free(buffer);
		*storage = ft_strdup(soba);
		free(soba);
		soba = NULL;
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
		buffer[rd_check] = '\0';
		string = buffer_to_str(buffer, string, storage);
	}
	if (rd_check <= 0)
	{
		if ((*storage) != NULL)
			free(*storage);
		*storage = NULL;
		//free(buffer);
		if (string)
			return (string);
		return (NULL);
	}
//	if (rd_check < 1)
//		free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*string;
	static char	*storage;
	char		*buffer;

	if (fd < 0 || fd > 1024)
		return (NULL);
	string = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	if (storage)
	{
		string = add_update_storage(string, &storage);
		if (ft_strchr(string, '\n'))
			return (string);
	}
	if (!ft_strchr(storage, '\n'))
		string = read_to_buffer(fd, buffer, string, &storage);
	return (string);
}

/*int	main(void)
{
	int	fd;

	fd = open("41_no_nl.txt", O_RDONLY);
	printf("1->%s", get_next_line(fd));
	printf("2->%s", get_next_line(fd));
	printf("3->%s", get_next_line(fd));
	printf("4->%s", get_next_line(fd));
	printf("5->%s", get_next_line(fd));
	printf("6->%s", get_next_line(fd));
	printf("7->%s", get_next_line(fd));
	printf("8->%s", get_next_line(fd));
	printf("9->%s", get_next_line(fd));
	printf("10->%s", get_next_line(fd));
}*/
