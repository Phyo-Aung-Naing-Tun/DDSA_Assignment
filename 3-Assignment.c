//
// Created by Lenovo on 12/26/2023.
// Register ,Login and Login

#include "stdio.h"
#include "stdlib.h"


//Global variables declare
int g_user_count = 0;
int g_true_email_index ;//only to check the password under the correct email
int g_login_successful_user_id ; //to show user infos
int g_isLogin = 0;

//Function declare
void registration();
void login();
int check_loginInfo(char char_arr[20],char type[10]);
void menu();
void see_int_output(int variable);
void  see_char_output(char variable[50]);
void check_allUsers_in_db(int user_count);
void copy_two_charArray(char char_in_db[50] , char r_char[50]);
int compare_two_charArray(char char_in_db[20] , char l_char[20]);
int size_of_charArray(char charArray[20]);
void show_userInfos(int index);
void go_to_profile();
void logOut();

//structure declare

struct db{
    int id;
    char name[20];
    char email[20];
    char phone[20];
    char address[50];
    int post_code;
    char password[20];

};
struct db users[5];

int main(){

    menu();
    return 0;
}

void menu(){
    int x = 0;
    printf("######## Welcome to My System ########\n\n ");
    while(1){
        printf("Plz enter 1 to login\n");
        printf("Plz enter 2 to register\n");
        printf("Plz enter 3 to see your profile\n");
        printf("Plz enter 4 to exit\n\n");
        scanf("%d",&x);
        if(x == 1){
            login();
        }else if(x == 2){
            registration();
        } else if(x == 3){
            go_to_profile();
        } else{
            exit(1);
        };
    };
}

void login(){
    printf("######## Login ########\n\n");
    char l_email[20];
    char l_password[20];

    printf("Enter your email : ");
    scanf(" %[^\n]",&l_email[0]);

    printf("Enter your password : ");
    scanf(" %[^\n]",&l_password[0]);

    int email_result = check_loginInfo(l_email,"email");
    int password_result = check_loginInfo(l_password,"password");
    if(email_result && password_result){
        g_isLogin = 1;
        printf("Successfully login.Now you can see your infos\n\n");


    }else{
        printf("Login Fail Plz Try Again!\n\n");
    }
}

int check_loginInfo(char char_arr[20],char type[10]){
    int isTrue = 0;
    for ( int i = 0; i < g_user_count; i++) {
        if(type == "email"){
            int result = compare_two_charArray(users[i].email,char_arr );
            if(result){
                isTrue = 1;
                g_true_email_index = i;
                break;
            }
        }

    }
    if(type == "password"){
        int result = compare_two_charArray(users[g_true_email_index].password,char_arr );
        if(result){
            isTrue = 1;
            g_login_successful_user_id = users[g_true_email_index].id;
        }
    }
    return isTrue ;
}

void registration(){
    int r_id = 0;
    char r_name[20];
    char r_email[20];
    char r_phone[20] ;
    char r_address[50];
    int r_post_code = 0;
    char r_password[20];

    printf("############ Please Register ##########\n\n");
    printf("Enter your name : ");
    scanf(" %[^\n]",&r_name[0]);

    printf("Enter your email : ");
    scanf(" %[^\n]",&r_email[0]);

    printf("Enter your phone no : ");
    scanf(" %[^\n]",&r_phone[0]);

    printf("Enter your address : ");
    scanf(" %[^\n]",&r_address[0]);

    printf("Enter your post code : ");
    scanf("%d",&r_post_code);

    printf("Enter your password : ");
    scanf(" %[^\n]",&r_password[0]);


    //Adding User data to Db;
    users[g_user_count].id = r_id;
    users[g_user_count].id = g_user_count;
    copy_two_charArray(users[g_user_count].name,r_name);
    copy_two_charArray(users[g_user_count].email,r_email);
    copy_two_charArray(users[g_user_count].phone,r_phone);
    copy_two_charArray(users[g_user_count].address,r_address);
    copy_two_charArray(users[g_user_count].password,r_password);
    users[g_user_count].post_code = r_post_code;

    g_user_count++;
}

void go_to_profile(){
    if(g_isLogin == 1){
        int is_logout = 0;
        printf("######## Your Profile ########\n\n");
        show_userInfos(g_login_successful_user_id);
        printf("Plz enter 1 to logout : ");
        scanf("%d",&is_logout);
        if(is_logout){
            logOut();
        }

    } else{
        printf("You need to login to see your infos!\n\n");
    }
}

void logOut(){
    g_isLogin = 0;
}

void copy_two_charArray(char char_in_db[50] , char r_char[50]){
    for (int i = 0; i < 50; i++) {
        if(r_char[i] == '\0'){
            break;
        }
        char_in_db[i] = r_char[i];
    }
}
int compare_two_charArray(char char_in_db[20] , char l_char[20]){
    int count = 0;
    int size_one = size_of_charArray(l_char);
    int size_two = size_of_charArray(char_in_db);
    if(size_one == size_two){
        for (int i = 0; i < size_one; i++) {
            if(char_in_db[i] == l_char[i]){
                count++;
            }
        }
    }
    if(count == size_one){
        return 1;

    } else{
        return 0;
    }
}
int size_of_charArray(char charArray[20]){
    int char_count = 0;
    for (int i = 0; i < 20; i++) {
        if(charArray[i] == '\0'){
            break;
        } else{
            char_count++;
        }
    }
    return char_count;
}
void show_userInfos(int index){
    printf("Your id => %d\n",users[index].id);
    printf("Your name => %s\n",users[index].name);
    printf("Your email => %s\n",users[index].email);
    printf("Your phone no => %s\n",users[index].phone);
    printf("Your address => %s\n",users[index].address);
    printf("Your post code => %d\n",users[index].post_code);
    printf("Your password => %s\n\n",users[index].password);

}


//for checking datas
void see_int_output(int variable){
    printf("%d\n",variable);
}
void see_char_output(char variable[50]){
    printf("%s\n",variable);
}
void check_allUsers_in_db(int user_count){
    for (int i = 0; i < user_count; i++) {
        see_int_output(users[i].id);
        see_char_output(users[i].name);
        see_char_output(users[i].email);
        see_char_output(users[i].phone);
        see_char_output(users[i].address);
        see_int_output(users[i].post_code);
        see_char_output(users[i].password);
        printf("\n\n");
    }
}