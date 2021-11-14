/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:15 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/14 22:38:54 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*save_lines(char *content_read, char *ret_str, char **store)
{
	unsigned int	i;
	size_t			cr_len;

	i = 0;
	cr_len = ft_strlen(content_read);
	while (content_read[i] != '\n' && content_read[i] != '\0')
		i++;
	if (ret_str == NULL)
		ret_str = ft_substr(content_read, 0, i + 1);
	else
		ret_str = ft_strljoin(ret_str, content_read, i + 1);
	if (content_read[i] == '\n' && content_read[i + 1] != '\0')
	{
		*store = ft_substr(content_read, i + 1, cr_len - i);
		printf("stored string: %s\n", *store);
	}
	//printf("ret_str at end of save_lines:\n%s\n", ret_str);
	printf("store at end of save_lines: %s\n", *store);
	return (ret_str);
}

char	*get_next_line(int fd)
{
	static char	*ret_str;
	char		*content_read;
	static char	*store;
	long long	read_check;

	printf("--------\ndoes store exist? %s\n", store);
	if (read(fd, 0, 0) == -1 || fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	content_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content_read)
		return (NULL);
	read_check = read(fd, content_read, BUFFER_SIZE);
	content_read[read_check] = '\0';
	//printf("verification:\n%s-------------\n", content_read);
	if (store && read_check > 0)
	{
		ret_str = ft_strljoin(ret_str, store, ft_strlen(store));
		printf("stored string at recall: %s\n", store);
		free (store);
	//	printf("stored string after free: %s\n", store);
	}
	ret_str = save_lines(content_read, ret_str, &store);
	while (read_check > 0 && !ft_strchr(content_read, '\n'))
	{
		read_check = read(fd, content_read, BUFFER_SIZE);
		ret_str = save_lines(content_read, ret_str, &store);
	}
	free (content_read);
	return (ret_str);
}

int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	printf("->first call\n%s\n", get_next_line(fd));
	printf("->second call\n%s\n", get_next_line(fd));
	printf("->third call\n%s\n", get_next_line(fd));
	printf("->fourth call\n%s\n", get_next_line(fd));
}
