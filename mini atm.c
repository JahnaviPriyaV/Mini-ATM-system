#include<stdio.h>
#include<string.h>
struct account{
    int accno;
    char name[50];
    int pin;
    float balance;
};
struct account user;
int accountcreated= 0;
void createaccount();
void deposit();
void withdraw();
void checkbalance();
int main(){
    int choice;
    while(1){
        printf("\n----WELCOME-----\n");
        printf("\nmeet your needs//----\n");
        printf("1.Create account\n");
        printf("2.Deposite money\n");
        printf("3.Withdraw Money:\n");
        printf("4.Check balance:\n");
        printf("5.exit!!\n");
        printf("now enter your respective need:");
        scanf("%d",&choice);
    switch(choice){
        case 1:createaccount();
        break;
        case 2:deposit();
        break;
        case 3:withdraw();
        break;
        case 4:checkbalance();
        break;
        case 5:printf("thankyou!!");
        break;
        default:printf("invalid choice\n");
    }
    }
}
void createaccount(){
    printf("\nEnter Account number:\n");
    scanf("%d",&user.accno);
    printf("Enter name:\n");
    scanf("%s",&user.name);
    printf("Enter pin:\n");
    scanf("%d",&user.pin);
    printf("Enter initial deposite\n");
    scanf("%f",&user.balance);
accountcreated=1;
printf("Account created successfully!!!");
}
void deposit(){
        float amount;
        if(accountcreated==0){
            printf("\nFirst create account\n");
            return;
        }
        printf("Enter amount to deposit:\n");
        scanf("%f",&amount);
        if(amount<=0){
            printf("Invalid account!\n");
             return;
        }
        user.balance +=amount;
        printf("Deposit successful! new balance =%.2f",user.balance);
}
void withdraw(){
    float amount;
    int enteredpin;
   if(accountcreated==0){
    printf("create account first!!");
    return;
   }
   
   printf("enter PIN\n");
   scanf("%d",&enteredpin);
   if(enteredpin!=user.pin){
    printf("wrong pin\n");
    return;
   }
   printf("enter the amount to withdraw:");
   scanf("%f",&amount);
   if(amount>user.balance){
    printf("\nInsufficient balance!!");
   }
   user.balance-=amount;
   printf("withdraw successful!,the remaining balance:%.2f\n",user.balance);
}
void checkbalance(){
    if(accountcreated==0){
    printf("create account first!!");
    return;}
    int enteredpin;
    printf("enter PIN:\n");
    scanf("%d",&enteredpin);
    if(enteredpin!=user.pin){
        printf("wrong pin\n");
        return;
    }
    printf("Account holder:%s\n",user.name);
    printf("Balance=%.2f\n",user.balance);
 }
