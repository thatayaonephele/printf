#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/***OTHER***/
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/***FLAGS***/
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4
#define F_PLUS 2
#define F_MINUS 1

/***SIZES***/
#define S_LONG 2
#define S_SHORT 1

/**
 *struct fmt - The struct object
 *@fmt:Format string composed of zero or more directives as a character string
 *@fn: The function correlating with the string output format
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 *typedef struct fmt fmt_t -The struct typedef object
 *@fmt:Format string composed of zero or more directives as a character string
 *@fm_t: The function correlating with the string output format
 */

typedef struct fmt fmt_t;

int _printf(const char *, ...);
int handle_print(const char *, int *,
va_list, char my_buff[], int, int, int, int);


/***CHARS & STRINGS***/
int display_chr(va_list, char my_buff[], int, int, int, int);
int display_percent(va_list, char my_buff[], int, int, int, int);
int display_string(va_list, char my_buff[], int, int, int, int);
