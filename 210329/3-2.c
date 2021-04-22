#include <stdio.h>
void main(){
    int i, n =0, *ptr;
    int sale[2][4]={{63, 84, 140, 130}, {157, 209, 251, 312}};

    ptr=&sale[0][0];
    for(i=0; i<8; i++){
        printf("address : %u sale %d = %d\n", ptr, i, *ptr);
        ptr++;
    }
}