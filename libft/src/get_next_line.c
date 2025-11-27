/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:40 by scuthber          #+#    #+#             */
/*   Updated: 2024/10/29 12:27:59 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_new_line(char	**buffer, char	*new_line)
{
	char	*line;
	int		line_len;
	char	*line_buffer;

	if (new_line)
	{
		line_len = new_line - *buffer + 1;
		line = ft_substr(*buffer, 0, line_len);
		line_buffer = ft_strdup(new_line + 1);
	}
	else
	{
		line = ft_strdup(*buffer);
		line_buffer = NULL;
	}
	free(*buffer);
	*buffer = line_buffer;
	return (line);
}

char	*free_buffer(char	**buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*ft_get_line(char	*new_line, int fd, char	**buffer)
{
	int			read_file;
	char		temp[BUFFER_SIZE + 1];
	char		*old_buffer;

	while (new_line == NULL)
	{
		read_file = read(fd, temp, BUFFER_SIZE);
		if (read_file < 0)
			return (free_buffer(buffer));
		if (read_file == 0)
			break ;
		temp[read_file] = '\0';
		old_buffer = *buffer;
		*buffer = ft_strjoin(*buffer, temp);
		if (!*buffer)
			return (free_buffer(&old_buffer));
		free(old_buffer);
		new_line = ft_strchr(*buffer, '\n');
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	new_line = ft_strchr(buffer, '\n');
	new_line = ft_get_line(new_line, fd, &buffer);
	if (!buffer || !*buffer)
		return (free_buffer(&buffer));
	return (ft_new_line(&buffer, new_line));
}

/*int main()
{   
    char    *fileName = "test.txt";
    int fd = open(fileName, O_RDWR);

    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }
    // char *gnl = get_next_line(fd);
    printf("File Contents: %s\n", get_next_line(fd));
    printf("File Contents: %s\n", get_next_line(fd));
    return 0;
}*/