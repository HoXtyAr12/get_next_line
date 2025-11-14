/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielbenetrix <gabrielbenetrix@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:00 by you               #+#    #+#             */
/*   Updated: 2025/11/07 11:45:43 by gabrielbene      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_append_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
    	free(stash);
    	stash = NULL;
    	return (NULL);
	}
	line = extract_line_from_stash(stash);
	stash = trim_stash_after_line(stash);
	return (line);
}

char	*read_and_append_to_stash(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	if (!stash)
		stash = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*extract_line_from_stash(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (stash[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*trim_stash_after_line(char *stash)
{
	int		i;
	int		j;
	char	*reste;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	reste = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!reste)
	{
		free(reste);
		return (NULL);
	}
	j = 0;
	i++;
	while (stash[i])
		reste[j++] = stash[i++];
	reste[j] = '\0';
	free(stash);
	return (reste);
}






