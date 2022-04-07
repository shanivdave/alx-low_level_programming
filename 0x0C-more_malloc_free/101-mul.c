#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * adding_all_mul - sum all the addition to know the multiplication result
 * @a: number 1
 * @len_a: lenght of number 1
 * @b: number 2
 * @len_b: lenght of number 2
 * Return: Addition pointer to the total resul of the  multiplication
 */
add_t *adding_all_mul(char *a, int len_a, char *b, int len_b)
{
	add_t *result = NULL;
	int i = 0, j = 0, carry = 0;

	result = malloc(sizeof(add_t));

	result->next = NULL, result->n_dig = 0, result->len_r = len_a + len_b;

	result->n_add = malloc(sizeof(char) * result->len_r);

	for (i = 0; i < result->len_r; i++)
		result->n_add[i] = '0';

	for (i = len_a - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len_b - 1; j >= 0; j--)
		{
			carry += (a[i] - '0') * (b[j] - '0');
			carry += result->n_add[i + j + 1] - '0';

			result->n_add[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry)
			result->n_add[i + j + 1] = (carry % 10) + '0';
	}
	if (result->n_add[0] != '0')
		result->n_dig = len_a + len_b;
	else
		result->n_dig = len_a + len_b - 1;

	return (result);
}

/**
 * print_free_result - print the result of the multiplication and free all
 * @result: Addition pointer to the total resul of the  multiplication
 * Result: Nothing
 */
void print_free_result(add_t *result)
{
	int i = 0, start_n = 0;

	i = 0;
	while (i < result->n_dig)
	{
		if (start_n || result->n_add[result->len_r - result->n_dig + i] != '0')
		{
			_putchar(result->n_add[result->len_r - result->n_dig + i]);
			start_n = 1;
		}
		i++;
	}
	if (!result->n_dig || !start_n)
		_putchar('0');
	_putchar('\n');
	free(result->n_add);
	free(result);
}

/**
 * error_message - print an error message and exit with status 98
 * Return: Nothing
 */
void error_message(void)
{
	char error_msg[] = "Error";
	int i = 0;

	while (error_msg[i] != '\0')
	{
		_putchar(error_msg[i]);
		i++;
	}

	_putchar('\n');

	exit(98);
}

/**
 * main - multiply 2 long numbers
 * usage <> ./mul num1 num2
 * @ac: number of arguments
 * @av: list of arguments
 * Return: 0 on success, another number otherwise
 */
int main(int ac, char **av)
{
	char *a = NULL, *b =  NULL;
	int i = 0, len_a = 0, len_b = 0, is_a = 1, is_b = 1, len_r = 0;
	add_t *result = NULL;

	if (ac != 3)
		error_message();

	for (i = 0, a = av[1], b = av[2]; is_a == 1 || is_b == 1; i++)
	{
		if (is_a == 1 && a[i] == '\0')
			is_a = 0, len_a = i;
		if (is_b == 1 && b[i] == '\0')
			is_b = 0, len_b = i;
		if ((is_a == 1 && (a[i] < '0' || a[i] > '9')) ||
				(is_b == 1 && (b[i] < '0' || b[i] > '9')))
			error_message();
	}

	if (len_a == 0 || len_b == 0)
		error_message();

	len_r = len_a + len_b;
	if (len_a > len_b)
		a = av[2], b = av[1], len_a = len_b, len_b = len_r - len_b;

	result = adding_all_mul(a, len_a, b, len_b);

	print_free_result(result);

	return (0);
}
