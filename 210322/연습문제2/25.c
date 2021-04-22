#include <stdio.h>

int fibo(n);
int main(){
    int num;
    printf("Enter num to insert : ");
    scanf("%d", &num);
    
    for (int i=0; i<num; i++){
        printf("%d\n", fibo(i));
    }

}

int fibo(n){
    if (n<=1) return 1;
    else return fibo(n-2)+fibo(n-1);
}