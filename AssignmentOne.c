//
// Assignment One 12/6/2023. Name Phyo Aung Naing Tun.
//
#include "stdio.h"
int main(){
    int a    = 1;
    int b    = 0;
    int c    = 1;
    int d    = 0;
    int stop = 10;
    for(a = 1 ; a < stop ; a++){
        for (b = 0; b < stop - a ; b++) {
            printf(" ");
        }
        for(c = 0; c < a; c++){
            printf("* ");
        }
        for(c = 1 ; c < stop - a ; c++){
            printf(" ");
            printf(" ");
        }
        for(d = 0 ; d < a ; d++){
            printf("* ");
        }

        printf("\n");
    }


    return 0;
};
