#include <stdio.h>
#include <string.h>

struct employee{
    char name[10];
    int year;
    int pay;
};

void main()
{
    int i;
    struct employee Lee[4]={
        {"이진호", 2014, 4200},
        {"이한영", 2015, 3300},
        {"이상원", 2015, 3500},
        {"이상범", 2016, 2900}

    };

    for (i=0; i<4; i++){
        printf(" name : %s\n", Lee[i].name);
        printf(" year : %d\n", Lee[i].year);
        printf(" pay : %d\n", Lee[i].pay);
    }
}