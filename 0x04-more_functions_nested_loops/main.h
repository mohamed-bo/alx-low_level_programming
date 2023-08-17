#ifndef main_H_
#define main_H_

int _putchar(char c);

/**
 * _isupper - checks for uppercase character.
 * @c: character to be check
 * Return: 1 if true, 0 if false
 */

int _isupper(int c);

/**
 * _isdigit - checks in input is digit
 * @c: character to be checked
 * Return: 1 if true, 0 if false
 */

int _isdigit(int c);

/**
 * mul - multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: product of a and b
 */

int mul(int a, int b);

/**
 * print_numbers - print from 0 to 9
 */

void print_numbers(void);

/**
 * print_most_numbers - print from 0 to 9, no 2 no 4
 */

void print_most_numbers(void);

/**
 * more_numbers - print from 0 to 14 ten times
 */

void more_numbers(void);

/**
 * print_line - print "_" n times
 * @n: number of "_" should be printed
 */

void print_line(int n);

/**
 * print_diagonal -  draws a diagonal line on the terminal.
 * @n: number of lines
 */

void print_diagonal(int n);

/**
 * print_square - prints a square, followed by a new line.
 * @size: size of square
 */

void print_square(int size);

/**
 * print_triangle - print traingle in specefic size
 * @size: size of triangle
 */

void print_triangle(int size);

#endif