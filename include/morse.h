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
