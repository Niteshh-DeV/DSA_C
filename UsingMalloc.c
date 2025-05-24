#include<stdio.h>
#include<stdlib.h>
int main ()

{

    int *ptr, n1, n2 ;

    printf("Enter The Size :");
    scanf("%d",&n1);

    ptr = (int *) malloc(n1 * sizeof(int));

    printf("\n Address is given as :\n ");

    for ( int i =0 ; i< n1 ; i++)
    {
        printf("%p\n",ptr+i);
    }

    //Using Realloc

    printf("Enter The new memory Size : \n");
    scanf("%d",&n2);

    ptr = realloc(ptr, n2 * sizeof(int));
    for ( int i = 0 ; i < n2 ; i++)
    {
        printf("%p \n",ptr+i);
    }

    free(ptr);
    return 0; 
}