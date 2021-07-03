#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void login()
{
char pass[10] = "admin";
    char password[10];
    int check;
    printf("Enter password:\n");
    scanf("%s",password);
    check=strcmp(pass,password);
   
    if(check == 0){
        printf("CORRECT!\n");
        }  
    else{
        printf("INCORRECT! TRY AGAIN!\n");
        login();
        }
}

void factorial(){
    int num;
    printf("\nEnter a number to calculate factorial:\n");
    scanf("%d",&num);
    printf("Factorial = %d",fact(num));
}
int fact(int n){
    if(n<=1)
    return 1;
   
    else
    return n*fact(n-1);
}

void fibonacci(){
    int num,i;
    printf("Enter the number of Fibonacci numbers needed:\n");
    scanf("%d",&num);
    for(i=0;i<=num;i++){
	printf("%d, ",fib(i));
	}
}
int fib(int n){
	if(n==0){
		return 0;
	}
	if(n==1) {
		return 1;
	}
	return fib(n-1)+fib(n-2);
}

int main()
{
    int choice,num1;
    login();
    printf("\n\nSelect a Program:\n\n1.Factorial\n\n2.Fibonacci\n\n");
    scanf("%d",&choice);
   
    switch(choice)
    {
        case 1:
        factorial();
        break;
       
        case 2:
        fibonacci();
        break;
    }

    return 0;
}
