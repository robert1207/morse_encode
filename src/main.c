/*

    morse-encode-and-decode
    Copyright (C) 2019-2020  Joker2770
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morse.h"

#define BUF_LEN 300


int main(int argc, char **argv) {

	if(argc < 2 || 0 == strcmp(*(argv+1), "-h") || 0 == strcmp(*(argv+1), "-H") || 0 == strcmp(*(argv+1), "--help"))
	{
		printf(
			"\n--list       (-l)	List morse code table."
			"\n--version    (-v)	show current version."
			"\n--encode     (-e)	Encode string. e.g.: morse-encode-and-decode -e \"Hello world!\""
			"\n--decode     (-d)	Decode Morse code. e.g.: morse-encode-and-decode -d \".- -... -.-. \""
			"\n\n");
		exit(0);
	}

	char mor[BUF_LEN] = "";
	char str[BUF_LEN] = "";
	char out[BUF_LEN] = "";

	if(0 == strcmp(*(argv+1), "-l") || 0 == strcmp(*(argv+1), "-L") || 0 == strcmp(*(argv+1), "--list")) 
	{

		char *mystr = "abcdefghijklmnopqrstuvwxyz0123456789.:,;?='/!-_\"()$&@";
		memset(out, 0, BUF_LEN);
		memset(mor, 0, BUF_LEN);
		memset(str, 0, BUF_LEN);

		//TO LOWCASE
		str2lowcase(mystr, out, BUF_LEN);
		
		char szTmpOne[4] = "";
		unsigned int i = 0;
		for(i = 0; i < strlen(mystr); i++)
		{
			memset(mor, 0, BUF_LEN);
			memset(szTmpOne, 0, sizeof(szTmpOne));
			sprintf(szTmpOne, "%c", out[i]);
			printf("\t%c\t", out[i]);
	
			//TO MORSE STRING
			String2MorseString(szTmpOne , mor, BUF_LEN);
			printf("%s\n" , mor);
		}
	}
	else if(0 == strcmp(*(argv+1), "--encode") || 0 == strcmp(*(argv+1), "-e") || 0 == strcmp(*(argv+1), "-E"))
	{
		memset(out, 0, BUF_LEN);
		memset(mor, 0, BUF_LEN);
		memset(str, 0, BUF_LEN);

		printf("base string:\n%s\n", *(argv+2));

		//TO LOWCASE
		str2lowcase(*(argv+2), out, BUF_LEN);

		//TO MORSE STRING
		String2MorseString(out , mor, BUF_LEN);
		printf("\nget morse code string:\n%s\n" , mor);
		
	}
	else if(0 == strcmp(*(argv+1), "--decode") || 0 == strcmp(*(argv+1), "-d") || 0 == strcmp(*(argv+1), "-D"))
	{
		memset(out, 0, BUF_LEN);
		memset(mor, 0, BUF_LEN);
		memset(str, 0, BUF_LEN);

		printf("base string:\n%s\n", *(argv+2));
		
		//TO NORMAL STRING
		MorseString2String(*(argv+2), str, BUF_LEN);
		printf("\nget decode string:\n%s\n", str);

	}
	
	if (0 == strcmp(*(argv+1), "--version") || 0 == strcmp(*(argv+1), "-v") || 0 == strcmp(*(argv+1), "-V"))
	{
		printf("v0.6\n");
	}

	return 0;
}

