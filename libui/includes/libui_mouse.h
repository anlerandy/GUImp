/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_mouse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:22:20 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/15 14:43:24 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_MOUSE_H
# define LIBUI_MOUSE_H

# define UIM_MOTION          0

# define UIM_WHEEL_NORMAL    0
# define UIM_WHEEL_FLIPPED   1

# define UIM_BUTTON_LEFT     1
# define UIM_BUTTON_MIDDLE   2
# define UIM_BUTTON_RIGHT    3
# define UIM_BUTTON_X1       4
# define UIM_BUTTON_X2       5

# define UIM_BUTTON_LMASK    0b00001
# define UIM_BUTTON_MMASK    0b00010
# define UIM_BUTTON_RMASK    0b00100
# define UIM_BUTTON_X1MASK   0b01000
# define UIM_BUTTON_X2MASK   0b10000

#endif
