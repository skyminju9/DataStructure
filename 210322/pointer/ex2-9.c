#include <stdio.h>

void main(){
    int i;
    char string1[20]="Dreams come true!", string2[20], *ptr1, *ptr2;

    ptr1=string1; //포인터에 배열의 시작 주소를 지정 
    printf("\n string1 address = %u \t ptr1 = %u", string1, ptr1); //string1의 주소와 ptr1의 값을 출력 - 포인터 ptr1이 string1을 가리키고 있음
    printf("\n string1 = %s \n ptr1=%s", string1, ptr1); //string1에 저장된 문자열과 ptr1이 가리키는 stirng1을 출력
    printf("\n\n %s", ptr1+7); //&string1[0]=ptr1 &string1[1]=ptr1+1 ... ptr1+7=string1[7]
    ptr2=&string1[7]; //ptr2에 stirng1[7]을 가리킴 
    printf("\n %s \n\n", ptr2); //ptr2가 가리키는 문자열 출력 -- come true! 출력

    for (i=16; i>=0; i--){
        putchar(*(ptr1+i)); //문자열을 거꾸로 출력 

    }
    for (i=0; i<20; i++){
        string2[i]=*(ptr1+i); //string1에 저장된 문자들을 포인터를 이용해 string2에 복사함 
    }

    printf("\n\n string1=%s", string1);
    printf("\n string2=%s", string2);

    *ptr1='P';
    *(ptr1+1)='e';
    *(ptr1+2)='a';
    *(ptr1+3)='c';
    *(ptr1+4)='e';
    printf("\n\n string1=%s\n", string1);
    

}