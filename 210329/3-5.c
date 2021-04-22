#include <stdio.h>
typedef struct {
    int row;
    int col;
    int value;
} term;

void smTranspose(term a[], term b[]);

int main(){
    int i=0, j=0;
    term A[11] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    term B[11] = {{1, 2, 5}, {2 ,4, 6}, {2, 5, 7}, {3, 10, 3}};

    smTranspose(A, B);

    for(int i = 0; i<11; i++){
        printf("%d %d %d \n", A[i].row, A[i].col, A[i].value);;
    }
    printf("\n\n");

    for(int i=0; i<11; i++){
        printf("%d %d %d \n", B[i].row, B[i].col, B[i].value);

    }
    printf("\n\n");
}

void smTranspose(term a[], term b[]){
    int m, n, v, i, j, p;
    m = a[0].row;
    n = a[0].col;
    v = a[0].value;
    b[0].row=n;
    b[0].col=m;
    b[0].value=v;
    if(v>0){
        p=1;
        for(i=0; i<n; i++){
            for(j=1; j<=v; j++){
                if(a[j].col==i){
                    b[p].row=a[j].col;
                    b[p].col=a[j].row;
                    b[p].value=a[j].value;
                    p++;
                }
            }
        }
    }
}