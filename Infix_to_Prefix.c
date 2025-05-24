#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int maxsize;
    int *array;
};

struct stack *create(int max)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->maxsize = max;
    stack->top = -1;
    stack->array = (int *)malloc(stack->maxsize * sizeof(int));
    return stack;
}

int isFull(struct stack *stack)
{
    if (stack->top == stack->maxsize - 1)
    {
        printf("stack is full\n");
    }
    return stack->top == stack->maxsize - 1;
}

int isEmpty(struct stack *stack)
{
    return stack->top == -1;
}

void push(struct stack *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int getPostfix(char *expression)
{
    int i, j;
    struct stack *stack = create(strlen(expression));
    if (!stack)
        return -1;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(stack, expression[i]);
        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++j] = pop(stack);
            push(stack, expression[i]);
        }
    }

    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';
}

void reverse(char *exp)
{
    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}

void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}

void infixToPrefix(char *exp)
{
    int size = strlen(exp);
    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}

int main()
{
    printf("The infix expression is: ");
    char expression[] = "((a/b)+c)-((d+e)*f))";
    printf("%s\n", expression);
    infixToPrefix(expression);
    printf("The prefix expression is: ");
    printf("%s\n", expression);
    return 0;
}