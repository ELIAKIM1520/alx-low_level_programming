#include "search_algos.h"

/**
  * linear_search - linear search
  * @array: pointer to first element in search array
  * @size: size of array
  * @value: value to find
  * Return: index where found or -1
  */

int linear_search(int *array, size_t size, int value)
{
    unsigned int counter;

    if (array == NULL)
        {
            return (-1);
        }

    for (counter = 0; counter < size; counter++)
    {
        printf("Value checked array[%d] = [%d]\n", counter, array[counter]);
        if (value == array[counter]) 
        {
            return counter;
        }
    }
    return (-1);
}
