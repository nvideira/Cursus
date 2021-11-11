/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:15 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/11 00:30:16 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void	save_lines(char *content_read, char *ret_str, char *store)
{
	unsigned int	i;
	size_t			cr_len;

	i = 0;
	cr_len = ft_strlen(content_read);
	while (content_read[i] != '\n' && content_read[i] != '\0')
		i++;
	if (ret_str == NULL)
		ret_str = ft_memmove(ret_str, content_read, i + 1);
	else
		ret_str = ft_strjoin(ret_str, content_read);
	if (content_read[i] == '\n' && content_read[i + 1] != '\0')
		store = ft_substr(content_read, i + 1, cr_len - i);
}

char	*get_next_line(int fd)
{
	static char	*ret_str;
	char		*content_read;
	static char	*store;
	long long	read_check;

	if (store)
	{
		ret_str = ft_strjoin(ret_str, store);
		free (store);
	}
	if (read(fd, 0, 0) == -1 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	content_read = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!content_read)
		return (NULL);
	read_check = read(fd, content_read, BUFFER_SIZE);
	content_read[read_check] = '\0';
	while (read_check > 0)
	{
		save_lines(content_read, ret_str, store);
	}
	free (content_read);
	return (ret_str);
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
