#include "huffman.h"

/**
 * symbol_create - creates a symbol_t data structure
 *
 * @data: char of data to be stored in structure
 * @freq: size_t associated frequency
 *
 * Return: pointer to created structure, or NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbol;

	new_symbol = malloc(sizeof(symbol_t));
	if (new_symbol == NULL)
		return (NULL);

	new_symbol->data = data;
	new_symbol->freq = freq;

	return (new_symbol);
}
