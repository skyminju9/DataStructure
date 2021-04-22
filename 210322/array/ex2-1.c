#include <stdio.h>

void main(){
    char c, c_array[100];
    int i, i_array[100];
    short s, s_array[100];
    float f, f_array[100];
    long l, l_array[100];

    printf("char c size = %d, char c_array size = %4d\n", sizeof(c), sizeof(c_array));
    printf("int i size = %d, int i_array size = %4d\n", sizeof(i), sizeof(i_array));
    printf("short s size = %d, short s_array size = %4d\n", sizeof(s), sizeof(s_array));
    printf("float f size = %d, float f_array size = %4d\n", sizeof(f), sizeof(f_array));
    printf("long l size = %d, long l_array size = %4d\n", sizeof(l), sizeof(l_array));
    
    getchar(); //실행 창이 닫히지 않도록 대기 명령 
}