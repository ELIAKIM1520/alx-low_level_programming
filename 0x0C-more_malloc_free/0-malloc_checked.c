#include <stdio.h>
#include <stdlib.h>

void* malloc_checked(size_t size)
{
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("malloc failed! Terminating process with status value 98.\n");
        exit(98);
    }
    return ptr;
}

int main()
{
    // Example usage of malloc_checked
    int* arr = malloc_checked(10 * sizeof(int));
    
    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}

