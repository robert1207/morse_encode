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

#include "morse.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_LEN 10
char num[][5] = {
	{'-','-','-','-','-'},//0
	{'.','-','-','-','-'},//1
	{'.','.','-','-','-'},//2
	{'.','.','.','-','-'},//3
	{'.','.','.','.','-'},//4
	{'.','.','.','.','.'},//5
	{'-','.','.','.','.'},//6
	{'-','-','.','.','.'},//7
	{'-','-','-','.','.'},//8
	{'-','-','-','-','.'} //9
};


#define MARK_LEN 17
char mark[][8] = {
	{'.', '-', '.', '-', '.', '-', '*', '.'},//.	0
	{'-', '-', '-', '.', '.', '.', '*', ':'},//:
	{'-', '-', '.', '.', '-', '-', '*', ','},//,
	{'-', '.', '-', '.', '-', '.', '*', ';'},//;
	{'.', '.', '-', '-', '.', '.', '*', '?'},//?
	{'-', '.', '.', '.', '-', '*', '*', '='},//=
	{'.', '-', '-', '-', '-', '.', '*', '\''},//'
	{'-', '.', '.', '-', '.', '*', '*', '/'},///
	{'-', '.', '-', '.', '-', '-', '*', '!'},//!
	{'-', '.', '.', '.', '.', '-', '*', '-'},//-
	{'.', '.', '-', '-', '.', '-', '*', '_'},//_
	{'.', '-', '.', '.', '-', '.', '*', '"'},//"
	{'-', '.', '-', '-', '.', '*', '*', '('},//(
	{'-', '.', '-', '-', '.', '-', '*', ')'},//)
	{'.', '.', '.', '-', '.', '.', '-', '$'},//$
	{'.', '-', '.', '.', '.', '*', '*', '&'},//&
	{'.', '-', '-', '.', '-', '.', '*', '@'} //@	16
};

#define CHARACTER 26
char a2[][4] = {
{'.','-','*','*'},//A
{'-','.','.','.'},//B
{'-','.','-','.'},//C
{'-','.','.','*'},//D
{'.','*','*','*'},//E
{'.','.','-','.'},//F
{'-','-','.','*'},//G
{'.','.','.','.'},//H
{'.','.','*','*'},//I
{'.','-','-','-'},//J
{'-','.','-','*'},//K
{'.','-','.','.'},//L
{'-','-','*','*'},//M
{'-','.','*','*'},//N
{'-','-','-','*'},//O
{'.','-','-','.'},//P
{'-','-','.','-'},//Q
{'.','-','.','*'},//R
{'.','.','.','*'},//S
{'-','*','*','*'},//T
{'.','.','-','*'},//U
{'.','.','.','-'},//V
{'.','-','-','*'},//W
{'-','.','.','-'},//X
{'-','.','-','-'},//Y
{'-','-','.','.'} //Z
};

Morse_t *new_morse() {
	Morse_t *ret;
	ret = (Morse_t*)malloc(sizeof(Morse_t));
	memset(ret->c, 0, 9);
	return ret;
}


/*
 *	MARK
 */
bool mark2morse(char n, Morse_t *morse) {
	int a = 0;

	for (; a < MARK_LEN; a++) {
		if (mark[a][7] == n) {
			morse->c[0] = mark[a][0];
			morse->c[1] = mark[a][1];
			morse->c[2] = mark[a][2];
			morse->c[3] = mark[a][3];
			morse->c[4] = mark[a][4];
			morse->c[5] = mark[a][5];
			morse->c[6] = mark[a][6];
			return true;
		}
	}
	return false;
}

bool morse2mark(Morse_t *morse, char *n) {
	int a = 0;
	for (; a < MARK_LEN; a++) {
		if (mark[a][0] == morse->c[0] &&
			mark[a][1] == morse->c[1] &&
			mark[a][2] == morse->c[2] &&
			mark[a][3] == morse->c[3] &&
			mark[a][4] == morse->c[4] &&
			mark[a][5] == morse->c[5] &&
			mark[a][6] == morse->c[6] ) {

			*n = mark[a][7];
			return true;
		}
	}
	return false;
}

/*
 *	NUMBER
 */
bool num2morse(char n, Morse_t *morse) {
	int pos = n - 48;

	if (pos <= 9 && pos >= 0) {
		morse->c[0] = num[pos][0];
		morse->c[1] = num[pos][1];
		morse->c[2] = num[pos][2];
		morse->c[3] = num[pos][3];
		morse->c[4] = num[pos][4];  
		return true;
	} 
	return false;
}

bool morse2num(Morse_t *morse, char *n) {
	int i = 0;

	for (; i < NUM_LEN; i++) {
		if (num[i][0] == morse->c[0] &&
			num[i][1] == morse->c[1] &&
			num[i][2] == morse->c[2] &&
			num[i][3] == morse->c[3] &&
			num[i][4] == morse->c[4] ) {

			*n = (char)(i + 48);
			return true;
		}
	}
	return false;
}

/*
 *	CHARACTER
 */
bool str2morse(char m , Morse_t *morse) {
	int pos = m - 97;
	if (pos >= 0 && pos <= 25) {
	morse->c[0] = a2[pos][0];
	morse->c[1] = a2[pos][1];
	morse->c[2] = a2[pos][2];	
	morse->c[3] = a2[pos][3];
		return true;
	}
	return false;
}


bool morse2str(Morse_t *morse, char *ch) {
	int i = 0;
	for (i = 0; i < CHARACTER; i++) {
		if (a2[i][0] == morse->c[0] &&
			a2[i][1] == morse->c[1] &&
			a2[i][2] == morse->c[2] &&
			a2[i][3] == morse->c[3]) { 

			*ch =  (char)(i + 97);
			return true;
		}
	}
	return false;
}


void MorseString2String(char *morse ,char *string, int buf_len) {
	Morse_t *temp = new_morse();
	int a = 0;
	int b = 0;
	int c = 0;
	int len = 0;
	char ch = '*';
	memset(temp->c, '*', 8);
	len = strlen(morse);

	for ( ; a < len; a ++) {
		if (c > buf_len) {
			printf("the string buffer is too little\n");
			return;
		}

		if (morse[a] != SEPARATOR && morse[a] != FAKE_SPACE)
			temp->c[b++] = morse[a];
		else if (morse[a] == SEPARATOR && morse[a-1] != FAKE_SPACE) {//get one charactor
			if (true == morse2str(temp, &ch) && b < 5) {
				string[c++] = ch;
			} else if (true == morse2mark(temp, &ch)) {
				string[c++] = ch;
			} else if (true == morse2num(temp, &ch)) {
				string[c++] = ch;
			} else {
				printf("has morse that not be decoded !\n");
			}

			//clean
			b = 0;
			memset(temp->c, '*' ,8);
		} else if (morse[a] == FAKE_SPACE) { //have a space
			string[c++] = ' ';
		}
	} 
}

void String2MorseString(char *string ,char *morse, int buf_len) {
	int a = 0;
	int b = 0;
	int len = strlen(string);
	Morse_t * temp = new_morse();

	for (; a < len; a ++ ) {
		if (buf_len < 8 || b >= buf_len) {
			printf("morse buffer is too litte\n");
			break;
		}

		if (string[a] != ' ') {
			//if is a num 
			if (string[a] >= '0' && string[a] <= '9') {
				if (true == num2morse(string[a], temp)) {
					morse[b++] = temp->c[0];
					morse[b++] = temp->c[1];
					morse[b++] = temp->c[2];
					morse[b++] = temp->c[3];
					morse[b++] = temp->c[4];
				} else {
					printf("encode on mumber error \n");
					return ;
				}
			}
			//if is a character
			else if (string[a] >= 97 && string[a] <= 122) {
				if (true == str2morse(string[a], temp)) {
				morse[b++] = temp->c[0];
				if (temp->c[1] != '*')
					morse[b++] = temp->c[1];
				if (temp->c[2] != '*')
					morse[b++] = temp->c[2];
				if (temp->c[3] != '*')
					morse[b++] = temp->c[3];
				} else {
					printf("encode on str error \n");
					return ;
				}
			}
			//if is a mark
			else if (string[a] <= 127) {
				if (true == mark2morse(string[a], temp)) {
				morse[b++] = temp->c[0]; 
				morse[b++] = temp->c[1];
				morse[b++] = temp->c[2];
				morse[b++] = temp->c[3];
				morse[b++] = temp->c[4];
				if (temp->c[5] != '*')
					morse[b++] = temp->c[5];
				if (temp->c[6] != '*')
					morse[b++] = temp->c[6];
				} else {
					printf("encode on mark error \n");
					return ;
				}
			} else {
				printf("out of the morse character \n");
				return ;
			}

			//clean
			memset(temp->c, 0 , 8);

			morse[b++] = SEPARATOR;
		
		} else if (string[a] == ' ') { //have a space and add / to instead
			morse[b++] = FAKE_SPACE;
			morse[b++] = SEPARATOR;
		}
	}

}

void str2lowcase(char *str, char *out, int buf_len) {
	int len = strlen(str);
	int a = 0;

	if (len >= buf_len) {
		printf("buf is to low\n");
		return;
	}

	for (;a < len; a++) {
		if (str[a] >= 'A' && str[a] <= 'Z') {
			out[a] = str[a] + 32;
		} else {
			out[a] = str[a];
		}
	}
}
