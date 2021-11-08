/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:16:20 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/08 19:43:40 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static void	add_extra(char *line, char *buffer, long long bytes)
{
	
}

static void	buffer_to_line(char *buffer)
{
	long long	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	
	
}

char	*get_next_line(int fd)
{
	long long	bytes;
	char	buffer[BUFFER_SIZE + 1];
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
	}
	
}
/*char	*get_next_line(int fd)
{
	static char		*bufstr;
	static char		*str;
	unsigned int	i;
	unsigned int	j;
	static char		*strfin;
	static char		*overbuff;

	i = 0;
	j = 0;
	if (overbuff != NULL)
	{
		strfin = ft_strjoin(strfin, overbuff);
		free (overbuff);
	}
	if (fd < 0 || buff <= 0)
		return (NULL);
	while (fd)
	{
		bufstr = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (!bufstr)
			return (NULL);
		read(fd, bufstr, BUFFER_SIZE);
		while (bufstr[i] != '\n' && bufstr[i] != '\0')
			i++;
		if (!str)
			str = ft_strdup(bufstr);
		ft_strjoin(str, bufstr);
		free (bufstr);
	}
	while (str[j] != '\n')
		j++;
	strfin = ft_substr(str, 0, j);
	if (j != ft_strlen(str))
		overbuff = ft_substr(str, j + 1, ft_strlen(str) - j);
	free (str);
	return (strfin);
}
*/
