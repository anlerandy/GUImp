/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_kcode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:03:56 by gsmith            #+#    #+#             */
/*   Updated: 2020/02/02 19:51:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_KCODE_H
# define LIBUI_KCODE_H

# include "libui_scode.h"

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

# define UIK_CAPSLOCK             1073741881

# define UIK_F1                   1073741882
# define UIK_F2                   1073741883
# define UIK_F3                   1073741884
# define UIK_F4                   1073741885
# define UIK_F5                   1073741886
# define UIK_F6                   1073741887
# define UIK_F7                   1073741888
# define UIK_F8                   1073741889
# define UIK_F9                   1073741890
# define UIK_F10                  1073741891
# define UIK_F11                  1073741892
# define UIK_F12                  1073741893

# define UIK_PRINTSCREEN          1073741894
# define UIK_SCROLLLOCK           1073741895
# define UIK_PAUSE                1073741896
# define UIK_INSERT               1073741897
# define UIK_HOME                 1073741898
# define UIK_PAGEUP               1073741899
# define UIK_DELETE               '\177'

# define UIK_END                  1073741901
# define UIK_PAGEDOWN             1073741902
# define UIK_RIGHT                1073741903
# define UIK_LEFT                 1073741904
# define UIK_DOWN                 1073741905
# define UIK_UP                   1073741906

# define UIK_NUMLOCKCLEAR         1073741907
# define UIK_KP_DIVIDE            1073741908
# define UIK_KP_MULTIPLY          1073741909
# define UIK_KP_MINUS             1073741910
# define UIK_KP_PLUS              1073741911
# define UIK_KP_ENTER             1073741912
# define UIK_KP_1                 1073741913
# define UIK_KP_2                 1073741914
# define UIK_KP_3                 1073741915
# define UIK_KP_4                 1073741916
# define UIK_KP_5                 1073741917
# define UIK_KP_6                 1073741918
# define UIK_KP_7                 1073741919
# define UIK_KP_8                 1073741920
# define UIK_KP_9                 1073741921
# define UIK_KP_0                 1073741922
# define UIK_KP_PERIOD            1073741923

# define UIK_APPLICATION          1073741925
# define UIK_POWER                1073741926
# define UIK_KP_EQUALS            1073741927
# define UIK_F13                  1073741928
# define UIK_F14                  1073741929
# define UIK_F15                  1073741930
# define UIK_F16                  1073741931
# define UIK_F17                  1073741932
# define UIK_F18                  1073741933
# define UIK_F19                  1073741934
# define UIK_F20                  1073741935
# define UIK_F21                  1073741936
# define UIK_F22                  1073741937
# define UIK_F23                  1073741938
# define UIK_F24                  1073741939
# define UIK_EXECUTE              1073741940
# define UIK_HELP                 1073741941
# define UIK_MENU                 1073741942
# define UIK_SELECT               1073741943
# define UIK_STOP                 1073741944
# define UIK_AGAIN                1073741945
# define UIK_UNDO                 1073741946
# define UIK_CUT                  1073741947
# define UIK_COPY                 1073741948
# define UIK_PASTE                1073741949
# define UIK_FIND                 1073741950
# define UIK_MUTE                 1073741951
# define UIK_VOLUMEUP             1073741952
# define UIK_VOLUMEDOWN           1073741953
# define UIK_KP_COMMA             1073741957
# define UIK_KP_EQUALSAS400       1073741958

# define UIK_ALTERASE             1073741977
# define UIK_SYSREQ               1073741978
# define UIK_CANCEL               1073741979
# define UIK_CLEAR                1073741980
# define UIK_PRIOR                1073741981
# define UIK_RETURN2              1073741982
# define UIK_SEPARATOR            1073741983
# define UIK_OUT                  1073741984
# define UIK_OPER                 1073741985
# define UIK_CLEARAGAIN           1073741986
# define UIK_CRSEL                1073741987
# define UIK_EXSEL                1073741988

# define UIK_KP_00                1073742000
# define UIK_KP_000               1073742001
# define UIK_THOUSANDSSEPARATOR   1073742002
# define UIK_DECIMALSEPARATOR     1073742003
# define UIK_CURRENCYUNIT         1073742004
# define UIK_CURRENCYSUBUNIT      1073742005
# define UIK_KP_LEFTPAREN         1073742006
# define UIK_KP_RIGHTPAREN        1073742007
# define UIK_KP_LEFTBRACE         1073742008
# define UIK_KP_RIGHTBRACE        1073742009
# define UIK_KP_TAB               1073742010
# define UIK_KP_BACKSPACE         1073742011
# define UIK_KP_A                 1073742012
# define UIK_KP_B                 1073742013
# define UIK_KP_C                 1073742014
# define UIK_KP_D                 1073742015
# define UIK_KP_E                 1073742016
# define UIK_KP_F                 1073742017
# define UIK_KP_XOR               1073742018
# define UIK_KP_POWER             1073742019
# define UIK_KP_PERCENT           1073742020
# define UIK_KP_LESS              1073742021
# define UIK_KP_GREATER           1073742022
# define UIK_KP_AMPERSAND         1073742023
# define UIK_KP_DBLAMPERSAND      1073742024
# define UIK_KP_VERTICALBAR       1073742025
# define UIK_KP_DBLVERTICALBAR    1073742026
# define UIK_KP_COLON             1073742027
# define UIK_KP_HASH              1073742028
# define UIK_KP_SPACE             1073742029
# define UIK_KP_AT                1073742030
# define UIK_KP_EXCLAM            1073742031
# define UIK_KP_MEMSTORE          1073742032
# define UIK_KP_MEMRECALL         1073742033
# define UIK_KP_MEMCLEAR          1073742034
# define UIK_KP_MEMADD            1073742035
# define UIK_KP_MEMSUBTRACT       1073742036
# define UIK_KP_MEMMULTIPLY       1073742037
# define UIK_KP_MEMDIVIDE         1073742038
# define UIK_KP_PLUSMINUS         1073742039
# define UIK_KP_CLEAR             1073742040
# define UIK_KP_CLEARENTRY        1073742041
# define UIK_KP_BINARY            1073742042
# define UIK_KP_OCTAL             1073742043
# define UIK_KP_DECIMAL           1073742044
# define UIK_KP_HEXADECIMAL       1073742045

# define UIK_LCTRL                1073742048
# define UIK_LSHIFT               1073742049
# define UIK_LALT                 1073742050
# define UIK_LGUI                 1073742051
# define UIK_RCTRL                1073742052
# define UIK_RSHIFT               1073742053
# define UIK_RALT                 1073742054
# define UIK_RGUI                 1073742055

# define UIK_MODE                 1073742081

# define UIK_AUDIONEXT            1073742082
# define UIK_AUDIOPREV            1073742083
# define UIK_AUDIOSTOP            1073742084
# define UIK_AUDIOPLAY            1073742085
# define UIK_AUDIOMUTE            1073742086
# define UIK_MEDIASELECT          1073742087
# define UIK_WWW                  1073742088
# define UIK_MAIL                 1073742089
# define UIK_CALCULATOR           1073742090
# define UIK_COMPUTER             1073742091
# define UIK_AC_SEARCH            1073742092
# define UIK_AC_HOME              1073742093
# define UIK_AC_BACK              1073742094
# define UIK_AC_FORWARD           1073742095
# define UIK_AC_STOP              1073742096
# define UIK_AC_REFRESH           1073742097
# define UIK_AC_BOOKMARKS         1073742098

# define UIK_BRIGHTNESSDOWN       1073742099
# define UIK_BRIGHTNESSUP         1073742100
# define UIK_DISPLAYSWITCH        1073742101
# define UIK_KBDILLUMTOGGLE       1073742102
# define UIK_KBDILLUMDOWN         1073742103
# define UIK_KBDILLUMUP           1073742104
# define UIK_EJECT                1073742105
# define UIK_SLEEP                1073742106
# define UIK_APP1                 1073742107
# define UIK_APP2                 1073742108

# define UIK_AUDIOREWIND          1073742109
# define UIK_AUDIOFASTFORWARD     1073742110

# define UIKMOD_NONE              0x0000
# define UIKMOD_LSHIFT            0x0001
# define UIKMOD_RSHIFT            0x0002
# define UIKMOD_LCTRL             0x0040
# define UIKMOD_RCTRL             0x0080
# define UIKMOD_LALT              0x0100
# define UIKMOD_RALT              0x0200
# define UIKMOD_LGUI              0x0400
# define UIKMOD_RGUI              0x0800
# define UIKMOD_NUM               0x1000
# define UIKMOD_CAPS              0x2000
# define UIKMOD_MODE              0x4000
# define UIKMOD_RESERVED          0x8000

# define UIKMOD_SHIFT             0x0003
# define UIKMOD_CTRL              0x00C0
# define UIKMOD_ALT               0x0300
# define UIKMOD_GUI               0x0C00

#endif
