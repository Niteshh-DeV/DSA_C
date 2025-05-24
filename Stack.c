#include<stdio.h>
#include<stdlib.h>
#define max 3
int top = -1 , stack [max] ;
void push();
void pop();
void display();
int main()
{

    int choice ;

    while(1)
    {
        printf("Enter Your Choice : \n");
        printf("1. Push \n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : push();
                    break ;
            case 2 : pop();
                    break ;
            case 3 : display();
                    break;
            case 4 : exit(0);
                    break;
            default : printf("\n Wrong Chioce\n");
                    exit(0);
        }
    }
 
}

void push()
{
    int val ;
    if (top == max -1)
    {
        printf("\n Stack is Full");
    }
    else
    {
        printf("\n Enter the Element :");
        scanf("%d",&val);
        top = top + 1 ;
        stack[top] = val ;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n Stack is Empty");
    }
    else
    {
        printf("\n Deleted Element is : %d\n",stack[top]);
        top = top - 1 ;
    }
}

void display ()
{
    int i ;
    if (top == -1)
    {
        printf("\n Stack is Empty\n");
    }
    else
    {
        for ( i = top ; i >= 0 ; i--)
        {
            printf("\n %d\n",stack[i]);
        }
    }
}