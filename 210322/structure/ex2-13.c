#include <stdio.h>
#include <string.h>

struct employee{
    char name[10];
    int year;
    int pay;
};

void main(){
    struct employee Lee;
    struct employee *Sptr=&Lee;
    strcpy(Sptr->name, "이순신");
    Sptr->year=2015;
    Sptr->pay=5900;

    printf(" name : %s \n", Sptr->name);
    printf(" year : %d \n", Sptr->year);
    printf(" pay : %d \n", Sptr->pay);
}