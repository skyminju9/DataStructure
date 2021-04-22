#include <stdio.h>

long int fact(int);

void main(){
    int n, result;
    printf("Enter integer: ");
    scanf("%d", &n);
    result=fact(n);
    printf("%d factorial is %ld\n", n, result);

}

long int fact(int n){
    int value;
    if(n<=1){
        printf("fact(1) func call\n");
        printf("fact(1) res 1 return\n");
        return 1;
    }
    else{
        printf("fact(%d) func call\n", n);
        value=(n*fact(n-1));
        printf("fact(%d) res %ld return\n", n, value);
        return value;
    }
}