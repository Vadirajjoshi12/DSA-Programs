#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top=0;

void push(int item){
    if(top == SIZE){
        printf("Stack Overflow\n");
    } else {
        stack[top] = item;
        top = top+1;
        printf("%d Pushed\n",item);
    }
}

void pop(){
    if(top == 0){
        printf("Stack Underflow\n");
    } else {
        top = top - 1;
        printf("%d popped\n", stack[top]); 
    }
}

void display(){
    if(top == 0){
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for(int i = top - 1; i >= 0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int ch,item;
    for(;;){
        printf("\nSTACK MENU\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter item to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; 
            default:
                printf("Invalid choice\n");
        }
    }
}
