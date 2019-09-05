#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morse.h"

#define BUF_LEN 300


int main() {

	char *mystr = "abcdefghijklmnopqrstuvwxyz0123456789.:123,;?='/!-_\"()$&@";
	char mor[BUF_LEN];
	char str[BUF_LEN];
	char out[BUF_LEN];
	memset(out, 0, BUF_LEN);
	memset(mor, 0, BUF_LEN);
	memset(str, 0, BUF_LEN);

	printf("base string:\n%s\n", mystr);

	//TO LOWCASE
	str2lowcase(mystr, out, BUF_LEN);
	
	//TO MORSE STRING
	str_to_morse_str(out , mor, BUF_LEN);
	printf("\nget morse code string:\n%s\n" , mor);


	//TO NORMAL STRING
	morse_str_to_str(mor, str, BUF_LEN);
	printf("\nget decode string:\n%s\n", str);
  
	return 0;
}

