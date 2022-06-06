/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:59:11 by sloghmar          #+#    #+#             */
/*   Updated: 2022/03/28 14:14:15 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

//Description : Écrire une fonction qui retourne une ligne lue
//				depuis un descripteur de fichier.
//nbchar = nombre de char lu.
//str = nouvelle chaine de cha.
//buffer = chaine de caractere qui a ete lu.

char	*get_next_line(int fd)
{
	char	*str;
	int		nbchar;
	char	*buffer;

	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	str = NULL;
	nbchar = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (nbchar > 0)
		str = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (nbchar > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
		nbchar = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		str = ft_strjoin (str, "\n");
	free(buffer);
	return (str);
}
/*
int main()
{
	int fd;
	fd = open("/Users/sloghmar/desktop/getnexttext", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
