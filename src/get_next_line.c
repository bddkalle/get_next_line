/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:44:25 by fschnorr          #+#    #+#             */
/*   Updated: 2024/12/04 10:29:30 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*_fill_stash(int fd, char *stash, char *buffer)
{
	char	*tmp;
	t_size	b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*_set_line(char *line)
{
	char	*left_stash;
	t_size	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	left_stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_stash == 0)
	{
		free (left_stash);
		left_stash = NULL;
	}
	line[i + 1] = 0;
	return (left_stash);
}

char	*get_next_line(int fd, t_gnl *gnl)
{
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(gnl->stash);
		gnl->stash = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = _fill_stash(fd, gnl->stash, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	gnl->stash = _set_line(line);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		fflush(stdout);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	printf("%s", line);
	fflush(stdout);
	free(line);
	close(fd);
	return (0);
}*/
