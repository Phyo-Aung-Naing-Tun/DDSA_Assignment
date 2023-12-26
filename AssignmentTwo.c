

#include "stdio.h"

int adding(int x , int y);
int sub(int x , int y);
int multi(int x , int y);
int divi(int x , int y);

int main(){

    int a = 0;
    int b = 0;
    int action ;
    printf("Please enter  a number : ");
    scanf("%d", &a);
    printf("Please enter your second number : ");
    scanf("%d", &b);
    printf("Please enter 1 to adding, 2 for subtraction, 3 for multiplication, 4 for divisioni : ");
    scanf("%d", &action);
    if(action == 1){
        printf("Your Answer is %d", adding(a , b));
    } else if(action == 2){
        printf("Your Answer is %d", sub(a, b));
    } else if(action == 3){
        printf("Your Answer is %d", multi(a ,b));
    } else if(action == 4){
        printf("Your Answer is %d", divi(a, b));
    }

    return 0;
}
int adding(int x , int y){
    return x + y;
}
int sub(int x , int y){
    return x - y;
}
int multi(int x , int y){
    return x * y;
}
int divi(int x , int y){
    return x / y;
}
