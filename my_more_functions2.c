#include "shell.h"
/**
 * _erratoi - converts a string to an integerrrr
 * @s: the string to be converted fdjgk
 *
 * Return: 0 if no numbers in string, converted 55dkdf  number otherwise
 *         -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;  /* Skips the optional plus sign */

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');

if (result > INT_MAX)
return (-1);
}
else
{
return (-1);  /* Invalid character encountered*/
}
}

return (result);
}

/**
 * print_error - prints an error message ker
 * @info: pointer to the parameter and return infoooo struct
 * @estr: string containing the specified error typeeeee
 */
void print_error(info_t *info, const char *estr)
{
fprintf(stderr, "%s: %d: %s: %s\n", info->fname
, info->line_count, info->argv[0], estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10) 100
 * @input: the input tt
 * @fd: the file descriptor toooo write toooo
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
FILE *output_stream = (fd == STDERR_FILENO) ? stderr : stdout;
int count = 0;

if (input < 0)
{
fputc('-', output_stream);
count++;
input = -input;
}

fprintf(output_stream, "%d", input);
count += (int)(floor(log10(abs(input))) + 1);

return (count);
}

/**
 * convert_number - converter function, a clone of itoa hhh
 * @num: number hhhh
 * @base: base
 * @flags: argument flagsssss
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char *ptr = buffer;
char sign = 0;
unsigned long n = num;
const char *array = (flags & CONVERT_LOWERCASE
) ? "0123456789abcdef" : "0123456789ABCDEF";

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

do {
*ptr++ = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*ptr++ = sign;

*ptr = '\0';

/* Reverse the string */
char *start = buffer;
char *end = ptr - 1;
while (start < end)
{
char temp = *start;
*start = *end;
*end = temp;
start++;
end--;
}

return (buffer);
}

/**
 * remove_comments - function replaces the first instance o
 * f '#' with '\0' nnggg
 * @buf: address of the string to modify  9999
 *
 * Return: Always 0
 */
void remove_comments(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}
