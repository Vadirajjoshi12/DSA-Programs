#include<stdio.h>
#include<stdlib.h>

void heapify(int a[10] , int n){
    int i , k , v , flag = 0 , j;
    for(i=n/2 ; i>=1 ; i--){
        k = i;
        v = a[k];

        while(!flag && 2*k <= n){
            j = 2*k;
            if(j<n){
                if(a[j] < a[j+1])
                    j = j+1;
            }

            if(v>=a[j])
                flag = 1;
            else{
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
        flag = 0;
    }
}

int main(){
    int n , a[10] , i , ch;
    for(;;){
        printf("\n 1.CREATE HEAP \n 2.EXTRACT MAX \n 3.EXIT \n READ CHOICE: \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    printf("Read number of elements: ");
                    scanf("%d",&n);
                    for(i=1 ; i<=n ; i++){
                        printf("Enter %d element: ",i);
                        scanf("%d",&a[i]);
                    }
                    heapify(a,n);
                    printf("Element after constructing heap: ");
                    for(i=1 ; i<=n ; i++){
                        printf("%d\t" , a[i]);
                    }
                    break;
            
            case 2:
                    if(n>=1){
                        printf("Element deleted is : %d\n",a[1]);
                        a[1] = a[n];
                        n = n-1;
                        heapify(a,n);
                        printf("\nHeap after reconstruction: ");
                        for(i=1 ; i<=n ; i++){
                            printf("%d\t" , a[i]);
                        }
                    }
                    else{
                            printf("No elements to read");
                        }
                        break;
            default: 
                    exit(0);
                    break;
        }
    }
    return 0;
}