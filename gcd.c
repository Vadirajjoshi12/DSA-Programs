#include <stdio.h>
#include <stdlib.h>

int gcd(int a , int b){
    if(a==b) return a;
    else if(a>b) return gcd(a-b,b);
    return gcd(b,a);
}

int main(){
    int a,b;
    printf("Enter Value of a: ");
    scanf("%d",&a);
    printf("Enter value of b: ");
    scanf("%d",&b);

    printf("\n GCD of %d and %d:%d ",a,b,gcd(a,b));
    return 0;
}
