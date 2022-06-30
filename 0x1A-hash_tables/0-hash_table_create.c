#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - C function to create a hash table
 * @size: size of hash table, unsigned long int type
 * Return: returns a pointer to newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table = NULL;
	hash_node_t **array = NULL;
	unsigned long int count;

	h_table = malloc(sizeof(hash_table_t));
	if (!h_table)
		return (NULL);

	h_table->size = size;
	array = malloc(sizeof(hash_node_t *) * size);
	if (!array)
		return (NULL);

	for (count = 0; count < size; count++)
		array[count] = NULL;

	h_table->array = array;
	return (h_table);
}
