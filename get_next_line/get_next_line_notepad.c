/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_notepad.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:19:45 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/02 22:24:24 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	*get_next_line(int fd);

	get_next_line uses the read() function to read the first line of file descriptor fd.

	Buffer Size is basically the amount of bytes it reads at a time.

	This means that it should move in that line, byte to byte (BUFFER_SIZE == 1), until it reaches "\n".
	In this process, we should allocate enough memory to store that line.
	If, for example, BUFFER_SIZE == 10, it should read the line 10 bytes at a time, so, if byte 23 is "\n",
it has to store the remaining 7 bytes to start storing the following line.

	It then returns a string, containing the line, unless there is nothing to read or an error occurs.
	In that case it should return NULL.
	The returned line should contain the "\n", if present.

	Upon being called again, it should read the following line.
	So, if called in a loop, it should keep returning the lines of fd until it reaches the end of fd.

	The function should also be able to read from stdin.

	If the same file descriptor switches to a different file before reading everything from the first fd,
the function has undefined behavior.

	It may or may not have undefined behavior when reading from a binary file.

ssize_t	read(int fd, void *buf, size_t count);
*/
