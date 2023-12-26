// Exam  Result Checker.
#include "stdio.h"
#include "stdbool.h"
void  check_result(int marks[6], int size);
int main(){

    int marks[6];
    int arr_size = 6;

    printf("######## WELCOME ########\n\n");
    for (int i = 0; i < arr_size; ++i) {
        printf("Plz Enter Your Marks %d : ", i + 1);
       scanf("%d", &marks[i]);
    };

    printf("######## YOUR RESULt ########\n");

    check_result(marks, arr_size);

    return 0;
}


void check_result(int marks[6], int size) {
    bool isPass = true;
    int total_mark = 0;

    // showing marks
    for (int i = 0; i < size; ++i) {
        printf("Marks %d is %d.\n", i + 1, marks[i]);
    }

    // to get total mark.
    for (int i = 0; i < size; ++i) {
        total_mark += marks[i];
    };
    printf("Total Mark is %d.\n", total_mark);

    //checking pass or fail.
    for (int i = 0; i < size; ++i) {
        if(marks[i] < 40){
            isPass = false;
            printf("Mark %d is less than 40.\n", i + 1);
        };
    }
    if(isPass) {
        printf("You Pass The Exam.\n\n");
    } else{
        printf("You Fail The Exam.\n\n");
    }

}
