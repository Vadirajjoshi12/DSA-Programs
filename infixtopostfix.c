#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20

struct stack{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item){
    s->data[++(s->top)] = item;
}

char pop(STACK *s){
    return s->data[(s->top)--];
}

int preceed(char symbol){
    switch(symbol){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

void infixtopostfix(STACK *s, char infix[]){
    char postfix[SIZE];
    int i=0, j=0;
    char ch;
    while((ch=infix[i++])!='\0'){
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch=='('){
            push(s,ch);
        }
        else if(ch==')'){
            while(s->top!=-1 && s->data[s->top]!='('){
                postfix[j++] = pop(s);
            }
            pop(s);
        }
        else{
            while(s->top!=-1 && preceed(s->data[s->top])>=preceed(ch)){
                postfix[j++] = pop(s);
            }
            push(s,ch);
        }
    }
    while(s->top!=-1){
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main(){
    char infix[20];
    STACK s;
    s.top = -1;
    printf("Read Infix Function: ");
    scanf("%s", infix);
    infixtopostfix(&s,infix);
    return 0;
}