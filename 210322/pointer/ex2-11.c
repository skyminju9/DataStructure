#include <stdio.h>

void main(){
    char *ptrArray[2];
    char **ptrptr;
    int i;

    ptrArray[0]="Korea";
    ptrArray[1]="Seoul";

    ptrptr=ptrArray;
    
    printf("ptrArray[0] address : &ptrArray[0] = %u\n", &ptrArray[0]);
    printf("ptrArray[0] : ptrArray[0] = %u\n", ptrArray[0]);
    printf("ptrArray[0] 참조값 : *ptrArray[0] = %c\n", *ptrArray[0]);
    printf("ptrArray[0] 참조 문자열 : *ptrArray[0] = %s\n", *ptrArray);

    printf("ptrArray[1] address : &ptrArray[1] = %u\n", &ptrArray[1]);
    printf("ptrArray[1] : ptrArray[1] = %u\n", ptrArray[1]);
    printf("ptrArray[1] 참조값 : *ptrArray[1] = %c\n", *ptrArray[1]);
    printf("ptrArray[1] 참조 문자열 : *ptrArray[1] = %s\n", *(ptrArray+1));

    printf("ptrptr address : &ptrptr = %u\n", &ptrptr);
    printf("ptrptr : ptrptr = %u\n", ptrptr);
    printf("ptrptr 1차 참조값 : *ptrptr = %u\n", *ptrptr);
    printf("ptrptr 2차 참조값 : **ptrptr = %u\n", **ptrptr);
    printf("ptrptr 2차 참조 문자열 : **ptrptr = %s\n", *ptrptr);

    printf("\n\n *ptrArray[0] : ");
    for (i = 0; i<5; i++){
        printf("%c", *(ptrArray[0]+i));
    }
    printf("\n **ptrptr : ");
    for(i=0; i<5; i++){
        printf("%c", *(*(ptrptr+1)+i));
    }
}