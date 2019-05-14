/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_events.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:36:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/13 16:09:50 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_EVENTS_H
# define LIBUI_EVENTS_H

# include "libui_kcode.h"
# include "libui_mouse.h"
# include "libui_window.h"

# define UID_DROP_EVENT             0
# define UIQ_QUIT_EVENT             0

# define UI_EVENT_QUIT              0x100
# define UI_EVENT_WINDOW            0x200
# define UI_EVENT_KEYDOWN           0x300
# define UI_EVENT_KEYUP             0x301
# define UI_EVENT_MOUSEMOTION       0x400
# define UI_EVENT_MOUSEBUTTONDOWN   0x401
# define UI_EVENT_MOUSEBUTTONUP     0x402
# define UI_EVENT_MOUSEWHEEL        0x403
# define UI_EVENT_DROPFILE          0x1000
# define UI_EVENT_DROPTEXT          0x1001
# define UI_EVENT_DROPBEGIN         0x1002
# define UI_EVENT_DROPCOMPLETE      0x1003

#endif
