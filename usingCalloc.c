#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n1, n2;
    
    printf("Enter the size: ");
    scanf("%d", &n1);

    ptr = (int *) calloc(n1, sizeof(int));

    for (i = 0; i < n1; i++)
        printf("%p\n", ptr + i);

    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    // Reallocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));
    printf("\nAddresses of newly allocated memory:\n");

    for (i = 0; i < n2; i++)
        printf("%p\n", ptr + i);

    free(ptr);
    return 0;
}