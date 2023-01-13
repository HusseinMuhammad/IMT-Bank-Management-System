/*
*Name : Hussein Muhammad Ahmad AlBaqry
*Embedded System Track 
*Group 4
*New Adminstrative Capital Branch
*/

// IMT Bank System Main Interface 

#include <stdio.h>
#include "config.h"
#include <time.h>
#include "stdlib.h"
#include "string.h"
uint8 flag = 1;
uint8 flag_Admin = 1;
uint16 OP;
uint8 user_name[10];
uint8 user_pass[10];

int main() 
{
time_t tm;   // a data type from the C ISO library define to store system's time value
time(&tm);
	
	client_Acc *Head = NULL;
	
	while (flag)
	{
		 printf("\t*********   Welcome to IMT Bank System   *********\n");
		 printf("\n\t\t\t%s\n", ctime(&tm));
		 printf("\t\tPlease Select Which Operation to process with \n");
		printf("1-Admin\n\t2-Client\n\t\t3-Exit System\n");
		scanf("%hu", &OP);
		flag_Admin = 1;
		if (OP == 1) // admin_ Window
		{ 
			printf("Please enter Admin User Name\t\t");
			scanf("%s",user_name);
			printf("Please enter Admin Pass word\t\t");
			scanf("%s",user_pass);
			if (strcmp(user_name,"admin") == 0 && strcmp(user_pass,"111990") == 0)   // (*user_pass == 111990)
			{ 
			system("cls");
			while (flag_Admin)
			{	 
				uint16 ch;
				uint32 ID;
				printf("Welcome to Admin Interface\n");
				printf("========================================\n");
				printf("1-Create New Account\n");
				printf("\t2-Open Existing Account\n");
				printf("\t\t3-Exit System\n");
				scanf("%hu", &ch);
				system("cls");
				switch (ch) 
				{
					case 1:
						Create_Account(&Head);
						break;
					case 2:
						printf("Please Enter Your Account ID ");
						scanf("%lu", &ID);
						Search_Admin(Head, ID);
						break;
					case 3:
						flag_Admin = 0;
						break;
				}
			}
			}
				else {printf("*\n**\n***\n---> Wrong User Name or Password... Please Try Again\n***\n**\n*\n\n");}
		} 
			else if (OP == 2) // Client_Window
			{	system("cls");
				uint32 ID_User;
				
				printf("Welcome Our Dear Client, Nice to see you! \n");
				printf("======================================================\n");
				printf("Please Enter Your Account ID ");
				scanf("%lu", &ID_User);
				Search(Head, ID_User);
			}
			else  // System_Exit
			{
				flag = 0;
			}
	}

	return 0;
}
