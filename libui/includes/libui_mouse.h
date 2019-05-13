/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_mouse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:22:20 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/13 15:28:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_MOUSE_H
# define LIBUI_MOUSE_H

# define UIM_MOTION          0

# define UIM_WHEEL_NORMAL    0
# define UIM_WHEEL_FLIPPED   1

# define UIM_BUTTON(X)       (1 << ((X)-1))
# define UIM_BUTTON_LEFT     1
# define UIM_BUTTON_MIDDLE   2
# define UIM_BUTTON_RIGHT    3
# define UIM_BUTTON_X1       4
# define UIM_BUTTON_X2       5
# define UIM_BUTTON_LMASK    UIM_BUTTON(UIM_BUTTON_LEFT)
# define UIM_BUTTON_MMASK    UIM_BUTTON(UIM_BUTTON_MIDDLE)
# define UIM_BUTTON_RMASK    UIM_BUTTON(UIM_BUTTON_RIGHT)
# define UIM_BUTTON_X1MASK   UIM_BUTTON(UIM_BUTTON_X1)
# define UIM_BUTTON_X2MASK   UIM_BUTTON(UIM_BUTTON_X2)

#endif
