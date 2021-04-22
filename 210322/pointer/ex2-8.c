#include <stdio.h>
void main(){
    int i=10, j=20;
    int *ptr;

    printf("i=%d j=%d\n", i, j);
    printf("i address = %u\n", &i);
    printf("j address = %u\n", &j);

    ptr=&i;
    printf("ptr address = %u\n", &ptr);
    printf("ptr = %d\n", ptr);
    printf("ptr 참조값 (*ptr) = %d\n", *ptr);

    ptr=&j;
    printf("ptr address = %u\n", &ptr);
    printf("ptr = %d\n", ptr);
    printf("ptr 참조값 (*ptr) = %d\n", *ptr);

    i = *ptr; //ptr의 참조값(j값)을 i에 대입했음 
    printf("i = %d\n", i);



}