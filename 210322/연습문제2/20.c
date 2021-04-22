#include <stdio.h>

void passByPtr(int* p1, int* p2);

int main(){
    int num1 = 50, num2 = 60;
    printf("Before passByPtr num1 = %d and num2 = %d\n", num1, num2);
    passByPtr(&num1, &num2);
    printf("After passByPtr num1 = %d and num2 = %d\n", num1, num2);

    return 0;
}

void passByPtr(int* p1, int* p2){
    int tmp=0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

}