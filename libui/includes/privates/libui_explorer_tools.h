/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_explorer_tools.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:32:26 by alerandy          #+#    #+#             */
/*   Updated: 2019/08/11 16:33:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_EXPLORER_TOOLS_H
# define LIBUI_EXPLORER_TOOLS_H

typedef struct s_ui_univers	t_ui_univers;
typedef struct s_ui_folder		t_ui_folder;

void	set_explorer_event(t_ui_univers *univers, t_ui_folder *folder);

#endif
