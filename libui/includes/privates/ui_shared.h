/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:03:13 by alerandy          #+#    #+#             */
/*   Updated: 2019/07/26 01:19:59 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_SHARED_H
# define UI_SHARED_H

typedef struct s_ui_layer	t_ui_layer;

char		*get_file_name(char *path);
void		close_fd(int fd, char *error);
void		convert_color_lines(unsigned *dst, unsigned *src, unsigned width);
unsigned	merge_pixel(unsigned dst, unsigned src);
void		ui_memuset(void *b, unsigned c, size_t len);
t_ui_layer	*ttf_print_error(char *error, const char *detail);

#endif
