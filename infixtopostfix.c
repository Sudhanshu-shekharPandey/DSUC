#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stk[20];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
char peek(){
    return stk[top];
}
char pop(){
    if(isEmpty())
        return -1;
    char ch=stk[top];
    top--;
    return(ch);
}
void push(char oper){
    if(isFull())
        printf("Stack Full");
    else{
        top++;
        stk[top]=oper;
    }
}
int check(char ch) 
{ 
    return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'); 
} 
int pre(char ch) 
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
int covert(char* e) 
{ 
    int i, j;
    for (i=0,j=-1;e[i]; ++i) 
    { 
        if (check(e[i])) 
            e[++j] = e[i]; 
        else if (e[i]=='(') 
            push(e[i]); 
        else if (e[i]==')') 
        { 
            while (!isEmpty()&&peek()!='(') 
                e[++j] = pop(); 
            if (!isEmpty()&&peek()!='(') 
                return -1;         
            else
                pop(); }
        else
        { 
            while (!isEmpty()&&pre(e[i])<=pre(peek())) 
                e[++j]=pop(); 
            push(e[i]); 
        } 
    } 
    while (!isEmpty()) 
        e[++j]=pop(); 
    e[++j]='\0'; 
    printf("%s",e); 
} 
int main()
{
    char expr[20]; 
    printf("Enter an expression :");
    scanf("%s",expr);
    printf("\nAfter postfix conversion :");
    covert(expr); 
    return 0; 
}
