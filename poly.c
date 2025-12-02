#include<stdio.h>
#include<stdlib.h>

struct node{
    int co, po;
    struct node *addr;
};
typedef struct node * NODE;

NODE inserted(NODE start , int co , int po){
    NODE temp , cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if(start == NULL)
        return temp;
    cur = start;

    while(cur->addr != NULL)
        cur = cur->addr;

    cur->addr = temp;
    return start;
}

void display(NODE start){
    NODE temp;

    if(start == NULL)
        printf("\nPolynomial empty\n");
    else{
        temp = start;
        while(temp->addr != NULL){
            printf("%d*^%d+", temp->co, temp->po);
            temp = temp->addr;
        }
        printf("%d*^%d\n", temp->co, temp->po);
    }
}

NODE addterm(NODE res , int co , int po){
    NODE temp , cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if(res == NULL)
        return temp;
    
    cur = res;

    while(cur != NULL){
        if(cur->po == po){
            cur->co = cur->co + co;
            return res;
        }
        cur = cur->addr;
    }

    res = inserted(res, co, po);   // fixed insertend
    return res;
}

NODE multiply(NODE poly1 , NODE poly2){
    NODE p1, p2, res = NULL;

    for(p1 = poly1 ; p1 != NULL ; p1 = p1->addr)
        for(p2 = poly2; p2 != NULL ; p2 = p2->addr)
            res = addterm(res , p1->co * p2->co , p1->po + p2->po);

    return res;
}

int main(){
    NODE poly1 = NULL , poly2 = NULL , poly;
    int n , i , co , po;

    printf("Read no. of terms of 1st polynomial: ");
    scanf("%d",&n);

    for(i = 1 ; i <= n ; i++){
        printf("Read CO & PO of %d term: ", i);   // fixed printf
        scanf("%d %d",&co , &po);
        poly1 = inserted(poly1, co, po);          // fixed insertend
    }

    printf("First Polynomial: \n");
    display(poly1);

    printf("Read no. of terms of 2nd polynomial: ");
    scanf("%d",&n);

    for(i = 1 ; i <= n ; i++){
        printf("Read CO & PO of %d term: ", i);   // fixed printf
        scanf("%d %d",&co , &po);
        poly2 = inserted(poly2, co, po);          // fixed insertend
    }

    printf("Second Polynomial: \n");
    display(poly2);

    poly = multiply(poly1 , poly2);

    printf("\nResultant polynomial:\n");
    display(poly);

    return 0;
}