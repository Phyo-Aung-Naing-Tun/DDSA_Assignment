//

#include "stdio.h"
#include "stdbool.h"

void show_marks(int marks[6], int size);
void pass_or_fail(int marks[6], int size);
void calculate_total_mark(int marks[6], int size);

int main(){
    int mgmg_marks[6] = {30, 60, 55, 66, 98,66};
    int koko_marks[6] = {50, 63, 55, 66, 68,66};
    int arr_size      = 6;

    show_marks(mgmg_marks, arr_size);
    calculate_total_mark(mgmg_marks, arr_size);
    pass_or_fail(mgmg_marks, arr_size);

    show_marks(koko_marks, arr_size);
    calculate_total_mark(koko_marks, arr_size);
    pass_or_fail(koko_marks, arr_size);


    return 0;

}

void show_marks(int marks[6], int size){
    for (int i = 0; i < size ; ++i) {
        printf("Mark %d is  %d.\n", i + 1, marks[i]);
    }
}
void pass_or_fail(int marks[6], int size){
    bool isPass = true;
    for (int i = 0; i < size; ++i) {
        if(marks[i] < 40){
            isPass = false;
            printf("Mark %d is less than 40.\n", i + 1);
        };
    }
    if(isPass) {
        printf("This Student Pass The Exam.\n\n");
    } else{
        printf("This Student Fail The Exam.\n\n");
    }
}
void calculate_total_mark(int marks[6], int size){
    int total_mark = 0;
    for (int i = 0; i < size; ++i) {
        total_mark += marks[i];
    };
    printf("Total Mark is %d.\n", total_mark);
}