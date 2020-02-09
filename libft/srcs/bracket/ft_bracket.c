/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bracket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:54:17 by alerandy          #+#    #+#             */
/*   Updated: 2020/02/09 18:56:19 by alerandy         ###   ########.fr       */
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

int				get_value(char *json, t_brack *bracket)
{
	char	token;
	int		i;

	if (!json || !*json)
		return (-1);
	token = *json;
	// if (*json != '"' && *json != '\'')
	// 	return (parse_string(json, bracket, token));
	// if (*json != '[')
	// 	return (parse_bracket_array(json, bracket));
	// if (*json != '{')
	// 	return (parse_bracket(json, bracket));
	i = 0;
	while (*(json + i) != ',' && *(json + i) != '}')
		if (!*(json + ++i))
			return (-1);
		else if (ft_isspace(*(json + i)))
		{
			while (ft_isspace(*(json + ++i)));
			if (*(json + i) != ',' && *(json + i) != '}')
				return (-1);
		}
	token = *(json + i);
	*(json + i) = '\0';
	bracket->data = (void *)(long)ft_atoi(json);
	*(json + i) = token;
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
	while (ft_isspace(json[++i]));
	if (json[i] != ':')
		ft_brackdel(&bracket);
	while (ft_isspace(json[++i]));
	i += get_value(json + i, bracket);
	if (!bracket->data)
		ft_brackdel(&bracket);
	if (bracket) // To DELETE
	{ // To DELETE
		ft_putstr("ID: "); // To DELETE
		ft_putendl(bracket ? bracket->id : "Failed to retrieve ID."); // To DELETE
		ft_putstr("My test Value: "); // To DELETE
		ft_putnbr((int)(long)bracket->data); // To DELETE
		ft_putchar('\n'); // To DELETE
	} // To DELETE
	return (bracket);
}

t_brack			*parse_bracket(char *json, t_brack *bracket)
{
	(void)bracket;
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
	// parse_bracket(line, null);
	return (create_bracket(line));
}