/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_kcode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:03:56 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/13 15:17:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_KCODE_H
# define LIBUI_KCODE_H

# include "libui_scode.h"

# define UIK_SCODE_MASK           (1<<30)
# define UI_SCODE_TO_KCODE(X)     (X | UIK_SCODE_MASK)

# define UIK_UNKNOWN              '\0'

# define UIK_RETURN               '\r'
# define UIK_ESCAPE               '\033'
# define UIK_BACKSPACE            '\b'
# define UIK_TAB                  '\t'
# define UIK_SPACE                ' '
# define UIK_EXCLAIM              '!'
# define UIK_QUOTEDBL             '"'
# define UIK_HASH                 '#'
# define UIK_PERCENT              '%'
# define UIK_DOLLAR               '$'
# define UIK_AMPERSAND            '&'
# define UIK_QUOTE                '\''
# define UIK_LEFTPAREN            '('
# define UIK_RIGHTPAREN           ')'
# define UIK_ASTERISK             '*'
# define UIK_PLUS                 '+'
# define UIK_COMMA                ','
# define UIK_MINUS                '-'
# define UIK_PERIOD               '.'
# define UIK_SLASH                '/'
# define UIK_0                    '0'
# define UIK_1                    '1'
# define UIK_2                    '2'
# define UIK_3                    '3'
# define UIK_4                    '4'
# define UIK_5                    '5'
# define UIK_6                    '6'
# define UIK_7                    '7'
# define UIK_8                    '8'
# define UIK_9                    '9'
# define UIK_COLON                ':'
# define UIK_SEMICOLON            ';'
# define UIK_LESS                 '<'
# define UIK_EQUALS               '='
# define UIK_GREATER              '>'
# define UIK_QUESTION             '?'
# define UIK_AT                   '@'
# define UIK_LEFTBRACKET          '['
# define UIK_BACKSLASH            '\\'
# define UIK_RIGHTBRACKET         ']'
# define UIK_CARET                '^'
# define UIK_UNDERSCORE           '_'
# define UIK_BACKQUOTE            '`'
# define UIK_A                    'a'
# define UIK_B                    'b'
# define UIK_C                    'c'
# define UIK_D                    'd'
# define UIK_E                    'e'
# define UIK_F                    'f'
# define UIK_G                    'g'
# define UIK_H                    'h'
# define UIK_I                    'i'
# define UIK_J                    'j'
# define UIK_K                    'k'
# define UIK_L                    'l'
# define UIK_M                    'm'
# define UIK_N                    'n'
# define UIK_O                    'o'
# define UIK_P                    'p'
# define UIK_Q                    'q'
# define UIK_R                    'r'
# define UIK_S                    's'
# define UIK_T                    't'
# define UIK_U                    'u'
# define UIK_V                    'v'
# define UIK_W                    'w'
# define UIK_X                    'x'
# define UIK_Y                    'y'
# define UIK_Z                    'z'

# define UIK_CAPSLOCK              UIK_SCODE_MASK(UI_SCODE_CAPSLOCK)

# define UIK_F1                    UIK_SCODE_MASK(UI_SCODE_F1)
# define UIK_F2                    UIK_SCODE_MASK(UI_SCODE_F2)
# define UIK_F3                    UIK_SCODE_MASK(UI_SCODE_F3)
# define UIK_F4                    UIK_SCODE_MASK(UI_SCODE_F4)
# define UIK_F5                    UIK_SCODE_MASK(UI_SCODE_F5)
# define UIK_F6                    UIK_SCODE_MASK(UI_SCODE_F6)
# define UIK_F7                    UIK_SCODE_MASK(UI_SCODE_F7)
# define UIK_F8                    UIK_SCODE_MASK(UI_SCODE_F8)
# define UIK_F9                    UIK_SCODE_MASK(UI_SCODE_F9)
# define UIK_F10                   UIK_SCODE_MASK(UI_SCODE_F10)
# define UIK_F11                   UIK_SCODE_MASK(UI_SCODE_F11)
# define UIK_F12                   UIK_SCODE_MASK(UI_SCODE_F12)

# define UIK_PRINTSCREEN           UIK_SCODE_MASK(UI_SCODE_PRINTSCREEN)
# define UIK_SCROLLLOCK            UIK_SCODE_MASK(UI_SCODE_SCROLLLOCK)
# define UIK_PAUSE                 UIK_SCODE_MASK(UI_SCODE_PAUSE)
# define UIK_INSERT                UIK_SCODE_MASK(UI_SCODE_INSERT)
# define UIK_HOME                  UIK_SCODE_MASK(UI_SCODE_HOME)
# define UIK_PAGEUP                UIK_SCODE_MASK(UI_SCODE_PAGEUP)
# define UIK_DELETE                '\177'
# define UIK_END                   UIK_SCODE_MASK(UI_SCODE_END)
# define UIK_PAGEDOWN              UIK_SCODE_MASK(UI_SCODE_PAGEDOWN)
# define UIK_RIGHT                 UIK_SCODE_MASK(UI_SCODE_RIGHT)
# define UIK_LEFT                  UIK_SCODE_MASK(UI_SCODE_LEFT)
# define UIK_DOWN                  UIK_SCODE_MASK(UI_SCODE_DOWN)
# define UIK_UP                    UIK_SCODE_MASK(UI_SCODE_UP)

# define UIK_NUMLOCKCLEAR          UIK_SCODE_MASK(UI_SCODE_NUMLOCKCLEAR)
# define UIK_KP_DIVIDE             UIK_SCODE_MASK(UI_SCODE_KP_DIVIDE)
# define UIK_KP_MULTIPLY           UIK_SCODE_MASK(UI_SCODE_KP_MULTIPLY)
# define UIK_KP_MINUS              UIK_SCODE_MASK(UI_SCODE_KP_MINUS)
# define UIK_KP_PLUS               UIK_SCODE_MASK(UI_SCODE_KP_PLUS)
# define UIK_KP_ENTER              UIK_SCODE_MASK(UI_SCODE_KP_ENTER)
# define UIK_KP_1                  UIK_SCODE_MASK(UI_SCODE_KP_1)
# define UIK_KP_2                  UIK_SCODE_MASK(UI_SCODE_KP_2)
# define UIK_KP_3                  UIK_SCODE_MASK(UI_SCODE_KP_3)
# define UIK_KP_4                  UIK_SCODE_MASK(UI_SCODE_KP_4)
# define UIK_KP_5                  UIK_SCODE_MASK(UI_SCODE_KP_5)
# define UIK_KP_6                  UIK_SCODE_MASK(UI_SCODE_KP_6)
# define UIK_KP_7                  UIK_SCODE_MASK(UI_SCODE_KP_7)
# define UIK_KP_8                  UIK_SCODE_MASK(UI_SCODE_KP_8)
# define UIK_KP_9                  UIK_SCODE_MASK(UI_SCODE_KP_9)
# define UIK_KP_0                  UIK_SCODE_MASK(UI_SCODE_KP_0)
# define UIK_KP_PERIOD             UIK_SCODE_MASK(UI_SCODE_KP_PERIOD)

# define UIK_APPLICATION           UIK_SCODE_MASK(UI_SCODE_APPLICATION)
# define UIK_POWER                 UIK_SCODE_MASK(UI_SCODE_POWER)
# define UIK_KP_EQUALS             UIK_SCODE_MASK(UI_SCODE_KP_EQUALS)
# define UIK_F13                   UIK_SCODE_MASK(UI_SCODE_F13)
# define UIK_F14                   UIK_SCODE_MASK(UI_SCODE_F14)
# define UIK_F15                   UIK_SCODE_MASK(UI_SCODE_F15)
# define UIK_F16                   UIK_SCODE_MASK(UI_SCODE_F16)
# define UIK_F17                   UIK_SCODE_MASK(UI_SCODE_F17)
# define UIK_F18                   UIK_SCODE_MASK(UI_SCODE_F18)
# define UIK_F19                   UIK_SCODE_MASK(UI_SCODE_F19)
# define UIK_F20                   UIK_SCODE_MASK(UI_SCODE_F20)
# define UIK_F21                   UIK_SCODE_MASK(UI_SCODE_F21)
# define UIK_F22                   UIK_SCODE_MASK(UI_SCODE_F22)
# define UIK_F23                   UIK_SCODE_MASK(UI_SCODE_F23)
# define UIK_F24                   UIK_SCODE_MASK(UI_SCODE_F24)
# define UIK_EXECUTE               UIK_SCODE_MASK(UI_SCODE_EXECUTE)
# define UIK_HELP                  UIK_SCODE_MASK(UI_SCODE_HELP)
# define UIK_MENU                  UIK_SCODE_MASK(UI_SCODE_MENU)
# define UIK_SELECT                UIK_SCODE_MASK(UI_SCODE_SELECT)
# define UIK_STOP                  UIK_SCODE_MASK(UI_SCODE_STOP)
# define UIK_AGAIN                 UIK_SCODE_MASK(UI_SCODE_AGAIN)
# define UIK_UNDO                  UIK_SCODE_MASK(UI_SCODE_UNDO)
# define UIK_CUT                   UIK_SCODE_MASK(UI_SCODE_CUT)
# define UIK_COPY                  UIK_SCODE_MASK(UI_SCODE_COPY)
# define UIK_PASTE                 UIK_SCODE_MASK(UI_SCODE_PASTE)
# define UIK_FIND                  UIK_SCODE_MASK(UI_SCODE_FIND)
# define UIK_MUTE                  UIK_SCODE_MASK(UI_SCODE_MUTE)
# define UIK_VOLUMEUP              UIK_SCODE_MASK(UI_SCODE_VOLUMEUP)
# define UIK_VOLUMEDOWN            UIK_SCODE_MASK(UI_SCODE_VOLUMEDOWN)
# define UIK_KP_COMMA              UIK_SCODE_MASK(UI_SCODE_KP_COMMA)
# define UIK_KP_EQUALSAS400        UIK_SCODE_MASK(UI_SCODE_KP_EQUALSAS400)

# define UIK_ALTERASE              UIK_SCODE_MASK(UI_SCODE_ALTERASE)
# define UIK_SYSREQ                UIK_SCODE_MASK(UI_SCODE_SYSREQ)
# define UIK_CANCEL                UIK_SCODE_MASK(UI_SCODE_CANCEL)
# define UIK_CLEAR                 UIK_SCODE_MASK(UI_SCODE_CLEAR)
# define UIK_PRIOR                 UIK_SCODE_MASK(UI_SCODE_PRIOR)
# define UIK_RETURN2               UIK_SCODE_MASK(UI_SCODE_RETURN2)
# define UIK_SEPARATOR             UIK_SCODE_MASK(UI_SCODE_SEPARATOR)
# define UIK_OUT                   UIK_SCODE_MASK(UI_SCODE_OUT)
# define UIK_OPER                  UIK_SCODE_MASK(UI_SCODE_OPER)
# define UIK_CLEARAGAIN            UIK_SCODE_MASK(UI_SCODE_CLEARAGAIN)
# define UIK_CRSEL                 UIK_SCODE_MASK(UI_SCODE_CRSEL)
# define UIK_EXSEL                 UIK_SCODE_MASK(UI_SCODE_EXSEL)

# define UIK_KP_00                 UIK_SCODE_MASK(UI_SCODE_KP_00)
# define UIK_KP_000                UIK_SCODE_MASK(UI_SCODE_KP_000)
# define UIK_THOUSANDSSEPARATOR    UIK_SCODE_MASK(UI_SCODE_THOUSANDSSEPARATOR)
# define UIK_DECIMALSEPARATOR      UIK_SCODE_MASK(UI_SCODE_DECIMALSEPARATOR)
# define UIK_CURRENCYUNIT          UIK_SCODE_MASK(UI_SCODE_CURRENCYUNIT)
# define UIK_CURRENCYSUBUNIT       UIK_SCODE_MASK(UI_SCODE_CURRENCYSUBUNIT)
# define UIK_KP_LEFTPAREN          UIK_SCODE_MASK(UI_SCODE_KP_LEFTPAREN)
# define UIK_KP_RIGHTPAREN         UIK_SCODE_MASK(UI_SCODE_KP_RIGHTPAREN)
# define UIK_KP_LEFTBRACE          UIK_SCODE_MASK(UI_SCODE_KP_LEFTBRACE)
# define UIK_KP_RIGHTBRACE         UIK_SCODE_MASK(UI_SCODE_KP_RIGHTBRACE)
# define UIK_KP_TAB                UIK_SCODE_MASK(UI_SCODE_KP_TAB)
# define UIK_KP_BACKSPACE          UIK_SCODE_MASK(UI_SCODE_KP_BACKSPACE)
# define UIK_KP_A                  UIK_SCODE_MASK(UI_SCODE_KP_A)
# define UIK_KP_B                  UIK_SCODE_MASK(UI_SCODE_KP_B)
# define UIK_KP_C                  UIK_SCODE_MASK(UI_SCODE_KP_C)
# define UIK_KP_D                  UIK_SCODE_MASK(UI_SCODE_KP_D)
# define UIK_KP_E                  UIK_SCODE_MASK(UI_SCODE_KP_E)
# define UIK_KP_F                  UIK_SCODE_MASK(UI_SCODE_KP_F)
# define UIK_KP_XOR                UIK_SCODE_MASK(UI_SCODE_KP_XOR)
# define UIK_KP_POWER              UIK_SCODE_MASK(UI_SCODE_KP_POWER)
# define UIK_KP_PERCENT            UIK_SCODE_MASK(UI_SCODE_KP_PERCENT)
# define UIK_KP_LESS               UIK_SCODE_MASK(UI_SCODE_KP_LESS)
# define UIK_KP_GREATER            UIK_SCODE_MASK(UI_SCODE_KP_GREATER)
# define UIK_KP_AMPERSAND          UIK_SCODE_MASK(UI_SCODE_KP_AMPERSAND)
# define UIK_KP_DBLAMPERSAND       UIK_SCODE_MASK(UI_SCODE_KP_DBLAMPERSAND)
# define UIK_KP_VERTICALBAR        UIK_SCODE_MASK(UI_SCODE_KP_VERTICALBAR)
# define UIK_KP_DBLVERTICALBAR     UIK_SCODE_MASK(UI_SCODE_KP_DBLVERTICALBAR)
# define UIK_KP_COLON              UIK_SCODE_MASK(UI_SCODE_KP_COLON)
# define UIK_KP_HASH               UIK_SCODE_MASK(UI_SCODE_KP_HASH)
# define UIK_KP_SPACE              UIK_SCODE_MASK(UI_SCODE_KP_SPACE)
# define UIK_KP_AT                 UIK_SCODE_MASK(UI_SCODE_KP_AT)
# define UIK_KP_EXCLAM             UIK_SCODE_MASK(UI_SCODE_KP_EXCLAM)
# define UIK_KP_MEMSTORE           UIK_SCODE_MASK(UI_SCODE_KP_MEMSTORE)
# define UIK_KP_MEMRECALL          UIK_SCODE_MASK(UI_SCODE_KP_MEMRECALL)
# define UIK_KP_MEMCLEAR           UIK_SCODE_MASK(UI_SCODE_KP_MEMCLEAR)
# define UIK_KP_MEMADD             UIK_SCODE_MASK(UI_SCODE_KP_MEMADD)
# define UIK_KP_MEMSUBTRACT        UIK_SCODE_MASK(UI_SCODE_KP_MEMSUBTRACT)
# define UIK_KP_MEMMULTIPLY        UIK_SCODE_MASK(UI_SCODE_KP_MEMMULTIPLY)
# define UIK_KP_MEMDIVIDE          UIK_SCODE_MASK(UI_SCODE_KP_MEMDIVIDE)
# define UIK_KP_PLUSMINUS          UIK_SCODE_MASK(UI_SCODE_KP_PLUSMINUS)
# define UIK_KP_CLEAR              UIK_SCODE_MASK(UI_SCODE_KP_CLEAR)
# define UIK_KP_CLEARENTRY         UIK_SCODE_MASK(UI_SCODE_KP_CLEARENTRY)
# define UIK_KP_BINARY             UIK_SCODE_MASK(UI_SCODE_KP_BINARY)
# define UIK_KP_OCTAL              UIK_SCODE_MASK(UI_SCODE_KP_OCTAL)
# define UIK_KP_DECIMAL            UIK_SCODE_MASK(UI_SCODE_KP_DECIMAL)
# define UIK_KP_HEXADECIMAL        UIK_SCODE_MASK(UI_SCODE_KP_HEXADECIMAL)

# define UIK_LCTRL                 UIK_SCODE_MASK(UI_SCODE_LCTRL)
# define UIK_LSHIFT                UIK_SCODE_MASK(UI_SCODE_LSHIFT)
# define UIK_LALT                  UIK_SCODE_MASK(UI_SCODE_LALT)
# define UIK_LGUI                  UIK_SCODE_MASK(UI_SCODE_LGUI)
# define UIK_RCTRL                 UIK_SCODE_MASK(UI_SCODE_RCTRL)
# define UIK_RSHIFT                UIK_SCODE_MASK(UI_SCODE_RSHIFT)
# define UIK_RALT                  UIK_SCODE_MASK(UI_SCODE_RALT)
# define UIK_RGUI                  UIK_SCODE_MASK(UI_SCODE_RGUI)

# define UIK_MODE                  UIK_SCODE_MASK(UI_SCODE_MODE)

# define UIK_AUDIONEXT             UIK_SCODE_MASK(UI_SCODE_AUDIONEXT)
# define UIK_AUDIOPREV             UIK_SCODE_MASK(UI_SCODE_AUDIOPREV)
# define UIK_AUDIOSTOP             UIK_SCODE_MASK(UI_SCODE_AUDIOSTOP)
# define UIK_AUDIOPLAY             UIK_SCODE_MASK(UI_SCODE_AUDIOPLAY)
# define UIK_AUDIOMUTE             UIK_SCODE_MASK(UI_SCODE_AUDIOMUTE)
# define UIK_MEDIASELECT           UIK_SCODE_MASK(UI_SCODE_MEDIASELECT)
# define UIK_WWW                   UIK_SCODE_MASK(UI_SCODE_WWW)
# define UIK_MAIL                  UIK_SCODE_MASK(UI_SCODE_MAIL)
# define UIK_CALCULATOR            UIK_SCODE_MASK(UI_SCODE_CALCULATOR)
# define UIK_COMPUTER              UIK_SCODE_MASK(UI_SCODE_COMPUTER)
# define UIK_AC_SEARCH             UIK_SCODE_MASK(UI_SCODE_AC_SEARCH)
# define UIK_AC_HOME               UIK_SCODE_MASK(UI_SCODE_AC_HOME)
# define UIK_AC_BACK               UIK_SCODE_MASK(UI_SCODE_AC_BACK)
# define UIK_AC_FORWARD            UIK_SCODE_MASK(UI_SCODE_AC_FORWARD)
# define UIK_AC_STOP               UIK_SCODE_MASK(UI_SCODE_AC_STOP)
# define UIK_AC_REFRESH            UIK_SCODE_MASK(UI_SCODE_AC_REFRESH)
# define UIK_AC_BOOKMARKS          UIK_SCODE_MASK(UI_SCODE_AC_BOOKMARKS)

# define UIK_BRIGHTNESSDOWN        UIK_SCODE_MASK(UI_SCODE_BRIGHTNESSDOWN)
# define UIK_BRIGHTNESSUP          UIK_SCODE_MASK(UI_SCODE_BRIGHTNESSUP)
# define UIK_DISPLAYSWITCH         UIK_SCODE_MASK(UI_SCODE_DISPLAYSWITCH)
# define UIK_KBDILLUMTOGGLE        UIK_SCODE_MASK(UI_SCODE_KBDILLUMTOGGLE)
# define UIK_KBDILLUMDOWN          UIK_SCODE_MASK(UI_SCODE_KBDILLUMDOWN)
# define UIK_KBDILLUMUP            UIK_SCODE_MASK(UI_SCODE_KBDILLUMUP)
# define UIK_EJECT                 UIK_SCODE_MASK(UI_SCODE_EJECT)
# define UIK_SLEEP                 UIK_SCODE_MASK(UI_SCODE_SLEEP)
# define UIK_APP1                  UIK_SCODE_MASK(UI_SCODE_APP1)
# define UIK_APP2                  UIK_SCODE_MASK(UI_SCODE_APP2)

# define UIK_AUDIOREWIND           UIK_SCODE_MASK(UI_SCODE_AUDIOREWIND)
# define UIK_AUDIOFASTFORWARD      UIK_SCODE_MASK(UI_SCODE_AUDIOFASTFORWARD)

# define UIKMOD_NONE               0x0000
# define UIKMOD_LSHIFT             0x0001
# define UIKMOD_RSHIFT             0x0002
# define UIKMOD_LCTRL              0x0040
# define UIKMOD_RCTRL              0x0080
# define UIKMOD_LALT               0x0100
# define UIKMOD_RALT               0x0200
# define UIKMOD_LGUI               0x0400
# define UIKMOD_RGUI               0x0800
# define UIKMOD_NUM                0x1000
# define UIKMOD_CAPS               0x2000
# define UIKMOD_MODE               0x4000
# define UIKMOD_RESERVED           0x8000

# define UIKMOD_CTRL               (UIKMOD_LCTRL|UIKMOD_RCTRL)
# define UIKMOD_SHIFT              (UIKMOD_LSHIFT|UIKMOD_RSHIFT)
# define UIKMOD_ALT                (UIKMOD_LALT|UIKMOD_RALT)
# define UIKMOD_GUI                (UIKMOD_LGUI|UIKMOD_RGUI)

#endif
