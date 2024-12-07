#include "get_next_line.h"

char	*read_data(int fd, char *buffer)
{
	char	*str;
	int		read_status;

	read_status = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!str)
			return (NULL)
		read_status = read(fd, str, BUFFER_SIZE);
		if (read_status <= 0)
		{
			free(str);
			return (buffer);
		}
		buffer = ft_strjoin(buffer, str);
		free(str);
	}
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	if (buffer[i] == '\n' && i < ft_strlen(buffer))
	{
		i++;
		str = malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
		if (!str)
			return (NULL);
		j = 0;
		while (i < ft_strlen(buffer))
		{
			str[j++] = buffer[i++];
		}
		return (str);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_status;

	if (fd <= 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);

	line = ft_extract_line(buffer);
	if (!line)
	{
		buffer = read_data(fd, buffer);
		if (!buffer)
			return (NULL);
		line = ft_extract_line(buffer);
	}
	buffer = update_buffer(buffer)
	return (line);
}