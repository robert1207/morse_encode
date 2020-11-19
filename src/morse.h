/*

    morse-encode-and-decode
    Copyright (C) 2019  Joker2770
	Copyright (C) {years}  robert1207

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

Also add information on how to contact you by electronic and paper mail.

If the program is interactive, make it output a short notice like this
when it starts in an interactive mode:

    Gnomovision version 69, Copyright (C) year name of author
    Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.

The hypothetical commands `show w' and `show c' should show the appropriate
parts of the General Public License.  Of course, the commands you use may
be called something other than `show w' and `show c'; they could even be
mouse-clicks or menu items--whatever suits your program.

You should also get your employer (if you work as a programmer) or your
school, if any, to sign a "copyright disclaimer" for the program, if
necessary.  Here is a sample; alter the names:

  Yoyodyne, Inc., hereby disclaims all copyright interest in the program
  `Gnomovision' (which makes passes at compilers) written by James Hacker.

  {signature of Ty Coon}, 1 April 1989
  Ty Coon, President of Vice

This General Public License does not permit incorporating your program into
proprietary programs.  If your program is a subroutine library, you may
consider it more useful to permit linking proprietary applications with the
library.  If this is what you want to do, use the GNU Lesser General
Public License instead of this License.

*/

#ifndef MORSE_H_
#define MORSE_H_


typedef int bool;
#define false 0
#define true  1

/*
 *  FAKE_SPACE IS MARING FOR A SPACE
 */
#define FAKE_SPACE '/'

/*
 * THE CHARACTER THAT BETWEEN TWO MORSE STRING
 */
#define SEPARATOR ' '


typedef struct Morse Morse_t;
struct Morse{
	char c[9];
};



Morse_t *new_morse();

bool str2morse(char m , Morse_t *morse);
bool morse2str(Morse_t *morse, char *ch);

bool mark2morse(char n, Morse_t *morse);
bool morse2mark(Morse_t *morse, char *n);

bool num2morse(char n, Morse_t *morse);
bool morse2num(Morse_t *morse, char *n);

void MorseString2String(char *morse ,char *string, int buf_len);

void String2MorseString(char *string ,char *morse, int buf_len);

void str2lowcase(char *str, char *out, int buf_len);

#endif /* MORSE_H_ */
