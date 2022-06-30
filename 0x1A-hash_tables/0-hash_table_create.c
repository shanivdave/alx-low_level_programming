#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_create - Creates a hash tabble
 * @size: size of the array table
 *
 * Return: pointer to table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t  *table = NULL;

	if (size < 1)
		return (NULL);

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->array = malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL)
		return (NULL);

	memset(table->array, 0, size * sizeof(hash_node_t *));
	table->size = size;

	return (table);
}
