#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 * Return: pointer to new hash table else NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = calloc(1, sizeof(hash_table_t));

	if (!size)
		return (NULL);
	if (!hash_table)
		return (NULL);
	hash_table->size = size;
	hash_table->array = calloc(size, sizeof(hash_node_t **));
	if (!hash_table->array)
	{
		free(hash_table);
		return (NULL);
	}
	return (hash_table);
}
