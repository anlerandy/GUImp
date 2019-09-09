/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_default.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:38:43 by alerandy          #+#    #+#             */
/*   Updated: 2019/09/09 12:53:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_DEFAULT_H
# define EVENT_DEFAULT_H

# include "libui.h"

void	callback_quit(t_ui_univers **uni, void *dummy, t_ui_event_data event);
void	callback_close(t_ui_univers **uni, void *dummy, t_ui_event_data event);
void	callback_click(t_ui_univers **uni, void *data, t_ui_event_data event);

#endif
