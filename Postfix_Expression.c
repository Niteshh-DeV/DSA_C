#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int stack[MAX];
char postfix[MAX];
int top = -1;

void pushstack(int tmp);
int evaluate(char c);
int main(){
    int i, result;
    printf("\nInsert a postfix notation : ");
    gets(postfix);
    for(i=0; postfix[i]!='\0'; i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            pushstack(postfix[i]-'0');
        }
        else{
            pushstack(evaluate(postfix[i]));
        }
    }
    printf("\nResult : %d", stack[top]);
    return 0;
}
void pushstack(int tmp){
    top++;
    stack[top] = tmp;
}
int evaluate(char c){
    int a, b;
    a = stack[top];
    top--;
    b = stack[top];
    top--;
    int ans;
    switch(c){
        case '+':
            ans = b + a;
            break;
        case '-':
            ans = b - a;
            break;
        case '*':
            ans = b * a;
            break;
        case '/':
            ans = b / a;
            break;
        case '^':
            ans = b ^ a;
            break;
        default:
            ans = 0;
    }
    top++;
    stack[top] = ans;
    return ans;
}