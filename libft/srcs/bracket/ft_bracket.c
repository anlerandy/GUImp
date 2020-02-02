/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bracket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:54:17 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/03 08:22:41 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int				get_id(char *json, t_brack *bracket)
{
	int		i;
	if (*json != '"' && *json != '\'')
		return (-1);
	i = 1;
	while (json[i] && (json[i] != *json || json[i - 1] == '\\'))
		++i;
	if (json[i] != *json)
		return (-1);
	if (i - 1 && !(bracket->id = ft_strndup(json + 1, i - 1)))
		return (i - 1);
	return (i);	
}

t_brack			*create_bracket(char *json)
{
	t_brack		*bracket;
	int			i;

	if (!json || !*json || *json != '{')
		return (NULL);
	i = 0;
	if (!(bracket = ft_memalloc(sizeof(t_brack))))
		return (NULL);
	while (ft_isspace(json[++i]));
	i += get_id(json + i, bracket);
	if (!bracket->id)
		ft_brackdel(&bracket);
	ft_putstr("ID: "); // To DELETE
	ft_putendl(bracket ? bracket->id : "Failed to retrieve ID."); // To DELETE
	return (bracket);
}

t_brack			*parse_bracket(char *json)
{

	if (!json || !*json || *json != '{')
		return (NULL);
	ft_putchar(json[ft_strlen(json) - 1]);
	ft_putendl("");
	return (NULL);
}

t_brack			*ft_bracket(char *path)
{
	int			fd;
	char		*line;
	char		*tmp;
	char		*buff;

	line = NULL;
	buff = NULL;
	if (!(fd = open(path, O_RDWR)))
		return (NULL);
	while (get_next_line(fd, &buff))
		if (!line)
			line = ft_strjoin(buff, "\0");
		else
		{
			tmp = line;
			line = ft_strjoin(tmp, buff);
			ft_strdel(&buff);
			ft_strdel(&tmp);
		}
	tmp = line;
	line = ft_strtrim(tmp);
	ft_strdel(&tmp);
	ft_putendl(line);
	parse_bracket(line);
	return (create_bracket(line));
}