#include "stdio.h"

void registration();
void add_datas(char name[20], char email[20], char password[20]);
 struct Db{
    char username[20];
    char email_address[20];
    char user_password[20];
    int phone;

};
struct Db datas[3];

int main(){




    registration();
    return 0;
};

void registration(){
    char r_username[20];
    char r_email[20];
    char r_password[20];
    int r_phone = 0;

    printf("Enter username : ");
    scanf(" %[^\n]",&r_username[0]);
    printf("Enter email : ");
    scanf(" %[^\n]",&r_email[0]);
    printf("Enter password : ");
    scanf(" %[^\n]",&r_password[0]);
    printf("Enter phone : ");
    scanf("%d",&r_phone);





    add_datas(r_username, r_email, r_password);
    for (int i = 0; i < 3; i++) {
        printf("%s\n",datas[i].username);
        printf("%s\n",datas[i].email_address);
        printf("%s\n",datas[i].user_password);
    }



};

void add_datas(char name[20], char email[20], char password[20]){
    for (int i = 0; i < 3; i++) {
        for(int x = 0; x < 20; x++){
            if(name[x] == "\0"){
                break;
            } else{
                datas[i].username[x] = name[x];
            }

    };
        for(int x = 0; x < 20; x++){
            if(email[x] == "\0"){
                break;
            } else{
                datas[i].email_address[x] = email[x];
            }

        };
        for(int x = 0; x < 20; x++){
            if(password[x] == "\0"){
                break;
            } else{
                datas[i].user_password[x] = password[x];
            }

        };


    }

};