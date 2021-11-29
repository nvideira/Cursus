/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:18:53 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/29 01:46:17 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*throw_it(char **storage)
{
	char	*return_of_the_string;
	int		i;
	char	*intern;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	return_of_the_string = ft_substr(*storage, 0, i + 1);
	intern = NULL;
	if ((*storage)[i] == '\n' && (*storage)[i + 1] != '\0')
	{
		intern = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
		free(*storage);
		*storage = ft_strdup(intern);
		free(intern);
		intern = NULL;
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (return_of_the_string);
}

char	*morph(char **storage, char *string)
{
	int		i;
	char	*return_of_the_string;
	char	*intern;

	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	intern = ft_strljoin(string, *storage, i + 1);
	return_of_the_string = ft_strdup(intern);
	free(intern);
	intern = NULL;
	if ((*storage)[i] == '\n' && (*storage)[i + 1] != '\0')
	{
		intern = ft_substr(*storage, i + 1, ft_strlen(*storage) - i);
		free(*storage);
		*storage = ft_strdup(intern);
		free(intern);
		intern = NULL;
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (return_of_the_string);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE + 1];
	int			chomp;
	char		*string;
	char		*temp;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	string = NULL;
	if (storage)
	{
		string = throw_it(&storage);
		if (ft_strchr(string, '\n'))
			return (string);
	}
	buffer[0] = '\0';
	chomp = read(fd, buffer, BUFFER_SIZE);
	if (chomp <= 0 && !string)
	{
		if (storage != NULL)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	buffer[chomp] = '\0';
	storage = ft_strdup(buffer);
	while (chomp > 0 && !ft_strchr(buffer, '\n'))
	{
		chomp = read(fd, buffer, BUFFER_SIZE);
		buffer[chomp] = '\0';
		temp = ft_strljoin(storage, buffer, ft_strlen(buffer));
		//free(storage); --> bye leaks, but segfaults
		storage = ft_strdup(temp);
		free(temp);
	}
	temp = NULL;
	string = morph(&storage, string);
	return (string);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("big_line_with_nl.txt", O_RDONLY);
// 	printf("1->%s", get_next_line(fd));
// 	printf("2->%s", get_next_line(fd));
// 	printf("3->%s", get_next_line(fd));
// 	printf("4->%s", get_next_line(fd));
// 	printf("5->%s", get_next_line(fd));
// 	printf("6->%s", get_next_line(fd));
// 	printf("7->%s", get_next_line(fd));
// 	printf("8->%s", get_next_line(fd));
// 	printf("9->%s", get_next_line(fd));
// 	printf("10->%s", get_next_line(fd));
// }
int	main()
{
	int fd;
	char *line;

	fd = open("multiple_line_no_nl", O_RDONLY);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s|", line);
		free(line);
		if (!line)
			break ;
	}
}
	// line = get_next_line(fd);
 	// printf("%s", line);
 	// free(line);

 	// line = get_next_line(fd);
 	// printf("%s", line);
 	// free(line);
	
	// line = get_next_line(fd);
 	// printf("%s", line);
 	// free(line);

 	// line = get_next_line(fd);
 	// printf("%s", line);
 	// free(line);
//}
