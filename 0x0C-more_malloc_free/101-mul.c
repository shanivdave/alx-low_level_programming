#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * is_digit - checks for digits
 * @c: input character to check for digit
 * Return: 0 failure, 1 success
 */
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
printf("Error\n");
return (98);
}
/**
 * multiply - multiplies 2 #'s, prints result, must be 2 #'s
 * @num1: factor # 1 (1st number)
 * @num2: factor # 2 (2nd number)
 * Return: 0 fail, 1 success
 */
int *multiply(char *num1, char *num2)
/**
 * main - multiply 2 input #'s and print result or print Error
 * @argc: input count of args
 * @argv: input array of string args
 * Return: 0, Success
 */
int main(int argc, char **argv)
{
char *num1, *num2;
if (argc != 3)
{
printf("Error\n");
exit(98);
num1 = argv[1], num2 = argv[2];
else
{num1 = argv[2], num2 = argv[1];
}
sum_result = multiply(num1 * num2);
if (sum_result == NULL)
exit(98);
print_me(sum_result);
return (0);
}
