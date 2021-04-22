#include <stdio.h>

int sum(n);
int main(){

    int num;

    printf("Enter num : ");
    scanf("%d", &num);
    printf("Total sum is %d", sum(num));

}

int sum(n){
    if (n<=1) return 1;
    else return n+sum(n-1);
}