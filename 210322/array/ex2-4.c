#include <stdio.h>

void main(){
    char str[20]="Data Structure!";
    printf("문자 배열 str[]: ");
    for (int i=0; str[i]; i++){
        printf("%c", str[i]);
    }
    printf("\n");

}