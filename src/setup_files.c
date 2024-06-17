/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:33:37 by discallow         #+#    #+#             */
/*   Updated: 2024/06/17 04:53:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_strcmp2(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (i);
	while ((str1[i] || str2[i]) && str1[i] == str2[i])
		i++;
	if (str1[i] == '\n' && str2[i] == '\0')
		i--;
	return (str1[i] - str2[i]);
}

static int	setup_here_doc(char **av)
{
	char	*line;
	int		fd;

	fd = open("/tmp/here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(0);
		if (!line || (ft_strcmp2(line, av[2]) == 0))
		{
			free(line);
			break ;
		}
		else
		{
			write(fd, line, ft_strlen(line));
			free(line);
		}
	}
	close (fd);
	return (fd);
}

static int	setup_file(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	return (fd);
}

void	pipex(t_pipes **exec, int ac, char **av, char **envp)
{
	int	fd;
	int	fd2;

	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		fd = setup_here_doc(av);
		fd = open("/tmp/here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		fd = setup_file(av);
		if (fd == -1)
			return ;
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	if (fd == -1 || fd2 == -1)
	{
		perror("Error opening file");
		close(fd);
		return ;
	}
	(*exec)[0].fd = fd;
	(*exec)[1].fd = fd2;
	execute_pipes(exec, ac, envp, av);
}
