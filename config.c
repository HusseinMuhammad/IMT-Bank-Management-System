/*
*Name : Hussein Muhammad Ahmad AlBaqry
*Embedded System Track 
*Group 4
*New Adminstrative Capital Branch
*/

// Implementation file (Functions implementation)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "std_types.h"
#include "config.h"

/*-----------------------------------********************Admin Interface*********************--------------------------------------------*/

/*
 * Function : Create New Client account (Node) And Append It to List To Make Linked list 
 * Operands : Head : takes The Start of the list (Head) to Know the end of list to append New one
 */

void Create_Account(client_Acc **head_ref) {
    client_Acc *new = (client_Acc *)malloc(sizeof(client_Acc));
    if (new != NULL) {
        Data(new);
        client_Acc *current = *head_ref;
        if (*head_ref == NULL) {
            *head_ref = new;
        } else {
            while (current->Next != NULL) {
                current = current->Next;
            }
            current->Next = new;
        }
    } else {
        printf("Records are Full");
    }
}


/*
 * Function : The Data that will be Entered Each Time Create New client (Node)
 * Operands : temp : The New client account (Node) That created to Enter Data
 */

void Data(client_Acc *temp) {
    uint8 x = 0;
    srand(time(NULL));
    while (x < 3)
		{
			printf("Kindly Provide Full Name (at least first 4 names) -:\n ");
			scanf(" %[^\n]", temp->Name);
			for (uint8 i = 0; temp->Name[i] != '\0'; i++)
				{	if (temp->Name[i] == ' ')
						{
							x++;
						}
				}
		}
    printf("Please Enter Address -: \n");
    scanf(" %[^\n]", temp->Address);
    while (strlen(temp->ID) < 14) {
        printf("Kindly Provide ID Consisting of 14 Digits -: ");
        scanf("%s", temp->ID);
    }
    printf("Please Enter age ");
    scanf("%hu", &temp->age);
    if (temp->age < 21) {
        while (strlen(temp->Guardian_ID) < 14) {
            printf("Kindly provide Guardian_ID Consisting of 14 Digits -: ");
            scanf("%s", temp->Guardian_ID);
        }
    }
    temp->Account_Status = 'A';
    temp->Balance = 1000;
    temp->Bank_ACC_ID = rand() + 10000000000;
    temp->Pass = rand() + 10000;
    temp->Next = NULL;
    PrintN(temp);
}

/*
 * Function : To Print The Client_Bank_ID  and The Client_Password
 * Operands : Nod : The New client (Node) That created to Print The User_Bank_ID  and The Client_Password 
 */
void PrintN(client_Acc *Nod) {
    printf("\n\n********************************************************\n");
    printf("********         Client_Bank_ID  = %lu      ********\n",
           Nod->Bank_ACC_ID);
    printf("********         Client_Password = %lu           ********\n",
           Nod->Pass);
    printf("********************************************************\n\n\n");
}



/*
 * Function : To Search In Data Of Client account what user_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Operands : head : The first Address of My data to go search in list on what Client_account i want 
 *              ID   : the Client Account ID that i want to open it 
 */
void Search_Admin(client_Acc *head_ref, uint32 ID) {
    client_Acc *curr = head_ref;
    uint16 sw;
    uint16 lo = 1;
    while (curr != NULL) {
        if (curr->Bank_ACC_ID == ID) {
            while (lo) {
                printf("\n\n        Name is %s \n", curr->Name);
                printf("        Your ID is %s \n\n", curr->ID);
                printf("\nPlease Choese What Process You Want\n");
                printf("1-Make Transaction\n");
                printf("2-Change Account Status\n");
                printf("3-Get Cash\n");
                printf("4-Deposit in Account\n");
                printf("5-Return to main Menu\n");
                scanf("%hu", &sw);
                switch (sw) {
                    case 1:
                        admin_Transaction(curr, head_ref);
                        break;
                    case 2:
                        Change_Account_Status(curr);
                        break;
                    case 3:
                        Get_Cash(curr);
                        break;
                    case 4:
                        Deposit_in_Account(curr);
                        break;
                    case 5:
                        lo = 0;
                        break;
                }
            }
        } else {
            printf("\t\t\tNot found in our Records!...\n"
			"\t----------------*******--*******--*******----------------\n");
        }
        if (lo == 0) {
            break;
        }
        curr = curr->Next;
    }
}

/*
 * Function : That Function responsible for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With
 * Operands : Curr : The current User 
 *               Head : The first Address To Search on The List with the account id that i want to transfer money to him return
 */
void admin_Transaction(client_Acc *curr, client_Acc *head) 
{
    client_Acc *Tran = head;
    uint32 ID_Transaction;
    uint32 Money_Trans;
	
    if (curr->Account_Status == 'A') 
	{
        printf("\nKindly Provide Bank Account ID Consisting of 10 Digits -: ");
        scanf("%lu", &ID_Transaction);
        while (Tran != NULL) 
		{
            if (Tran->Bank_ACC_ID == ID_Transaction) 
			{
                if (Tran->Account_Status == 'A') 
				{
                    printf(
                        "\n\tPlease enter Balance to be transfered to "
                        "this account ");
                    scanf("%lu", &Money_Trans);
                    if (curr->Balance > Money_Trans)
						{
                        curr->Balance = curr->Balance - Money_Trans;
                        Tran->Balance = Tran->Balance + Money_Trans;
                        printf(
                            "\n\n---------           Transaction accomplished successfully   "
                            "     --------- \n");
                        printf("---------     The Balance Transacted  is %lu \n",
                               Money_Trans);
                        printf("---------     Your Balance Now is %lu \n",
                               curr->Balance);
                        printf(
                            "---------     The Balance Of Account you send "
                            "Money Now is %lu \n\n\n",
                            Tran->Balance);
                    } else 
					{
                        printf(
                            "\n Transaction has Failed, Please Checke Your "
                            "Balance \n");
                        break;
                    }
                    break;
                } else 
				{
                    printf(
                        "\n*****   The Account_Status is '%c' make sure The "
                        "Account you "
                        "want to send the money is 'A'ctive   *****\n",
                        Tran->Account_Status);
                    break;
                }
            }
            Tran = Tran->Next;
        }
    } 
	else 
	{
        printf(
            "\n\nThe Bank Account_Status Is '%c' Please Make sure your Account "
            "Is 'A'ctive\n",
            curr->Account_Status);
    }
}


/*
 * Function : the function that i can change the Account status to ("Active","Closed","Restricted") 
 * Operands : Curr : The current user to change account status 
 */
 
void Change_Account_Status(client_Acc *curr) 
{
    uint16 Status;
    printf("Please Select What Account Status\n");
    printf("1-Set Account to Active State \n");
    printf("2-Set Account to Restricted State \n");
    printf("3-Set Account to Closed \n");
    scanf("%hu", &Status);
    switch (Status) 
	{
        case 1:
            curr->Account_Status = 'A';
            printf("\n*****\t   Accunt Status is Active   \t*****\n");
            break;
        case 2:
            curr->Account_Status = 'R';
            printf("\n*****\t   Accunt Status is Restricted   \t*****\n");
            break;
        case 3:
            curr->Account_Status = 'C';
            printf("\n*****\t   Accunt Status is Closed  \t*****\n");
            break;
    }
}

/*
 * Function : That function make me Withdraw money from my account
 * Operands : Curr : the current user account that i want to Withdraw money
 */
void Get_Cash(client_Acc *curr)
 {
    uint32 Cash;
    printf("\nPlease Enter Cash to get -: ");
    scanf("%lu", &Cash);
    if (curr->Balance > Cash) 
	{
         printf("\n       ---------------------------------------\n");
        printf("-------    Your Cash Before operation %lu    --------\n",
               curr->Balance);
        printf("       ---------------------------------------\n\n");
        curr->Balance = curr->Balance - Cash;
        printf("\n       ---------------------------------------\n");
        printf("-------    Your Cash After operation %lu    --------\n",
               curr->Balance);
        printf("       ---------------------------------------\n\n");
    } 
	else 
	{
        printf("\tFailed !... Please check Your Balance\n");
		printf("----------------*******************************************************----------------\n");
    }
}


/*
 * Function : That function make me Deposit on my account and increment My Balance of money 
 * Operands : Curr : the current user account that i want to Deposit 
 */
void Deposit_in_Account(client_Acc *curr) {
    uint32 Dep;
    printf("\nPlease Enter Your Deposit -: ");
    scanf("%lu", &Dep);
        printf("\n      ---------------------------------------\n");
    printf("-------    Your Cash Before Deposit %lu    -------\n",
           curr->Balance);
    printf("      ---------------------------------------\n");
    curr->Balance = curr->Balance + Dep;
    printf("\n      ---------------------------------------\n");
    printf("-------    Your Cash After Deposit %lu    -------\n",
           curr->Balance);
    printf("      ---------------------------------------\n");
}

/*-----------------------------------********************Client Interface*********************--------------------------------------------*/

/*
 * Function : To Search In Data Of User account what user_account I want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Operands : head : The first Address of My data to go search in list on what user_account I want 
 *            ID   : the Account ID that I want to open it 
 */
void Search(client_Acc *head_ref, uint32 ID)
 {
	
    client_Acc *curr = head_ref;
    uint16 sw;
    uint16 lo = 1;
    while (curr != NULL) {
        if (curr->Bank_ACC_ID == ID) {
            while (lo) {
                printf("\n\n        Name is %s \n", curr->Name);
                printf("        Your ID is %s \n\n", curr->ID);
                printf("\nPlease Choose What Operation You Want\n");
                printf("1-Make Transaction\n");
                printf("2-Change Account Password\n");
                printf("3-Get Cash\n");
                printf("4-Deposit in Account\n");
                printf("5-Return to main Menu\n");
                scanf("%hu", &sw);
                switch (sw) {
                    case 1:
                        make_Transaction(curr, head_ref);
                        break;
                    case 2:
                        Change_Password(curr);
                        break;
                    case 3:
                        Get_Cash(curr);
                        break;
                    case 4:
                        Deposit_Acc(curr);
                        break;
                    case 5:
                        lo = 0;
                        break;
                }
            }
        } else {
            printf("\t\t\tNot found in our Records!...\n"
			"\t----------------*******--*******--*******----------------\n");
        }
        if (lo == 0) {
            break;
        }
        curr = curr->Next;
    }
}
/*
 * Function : for Transacting Between Two Account The Current Account and The Account That I Want to Make the make_Transaction With 
 * Operands : Curr : The current User 
 *            Head : The first Address To Search on The List with the account ID that I want to transfer money to
 */
void make_Transaction(client_Acc *curr, client_Acc *head) {
    client_Acc *Tran = head;
    uint32 ID_Transaction;
    uint32 Money_Trans;
    if (curr->Account_Status == 'A') {
        printf("\nPlease Enter Bank Account ID Consisting of 10 Digits -: ");
        scanf("%lu", &ID_Transaction);
        while (Tran != NULL) {
            if (Tran->Bank_ACC_ID == ID_Transaction) {
                if (Tran->Account_Status == 'A') {
                    printf(
                        "\nPlease enter balance to be transfered to "
                        "this account ");
                    scanf("%lu", &Money_Trans);
                    if (curr->Balance > Money_Trans) {
                        curr->Balance = curr->Balance - Money_Trans;
                        Tran->Balance = Tran->Balance + Money_Trans;
                        printf(
                            "\n\n---------           Transaction Accomplished Successfully    "
                            "     --------- \n");
                        printf("---------     The Money Transacted  is %lu \n",
                               Money_Trans);
                        printf("---------     Your New Balance Now is %lu \n",
                               curr->Balance);
                        printf(
                            "---------     The Balance Of Account you send "
                            "Money Now is %lu \n\n\n",
                            Tran->Balance);
                    } else {
                        printf(
                            "\nTransaction has failed Please Checke Your "
                            "Money \n");
                        break;
                    }
                    break;
                } else {
                    printf(
                        "*****   The Account_Status is '%c' make sure The "
                        "Account you "
                        "want to send money is 'A'ctive   *****\n",
                        Tran->Account_Status);
                    break;
                }
            }
            Tran = Tran->Next;
        }
    } else {
        printf(
            "\n\nThe Bank Account_Status Is '%c' Please Make sure your Account "
            "Is 'A'ctive\n",
            curr->Account_Status);
    }
}
/*
 * Function : That function make me change My Password Account
 * Operands   : Curr : The current user account to change its Password 
 */
void Change_Password(client_Acc *curr) {
    uint32 pass;
    // uint32 new_pass;
    uint8 x = 3;
    while (x--) {
        printf("\nPlease Enter Your Current Password -: ");
        scanf("%lu", &pass);
        if (curr->Pass == pass) {
            printf("Please Enter Your New Password ");
            scanf("%lu", &curr->Pass);
            // curr->Pass = new_pass;
            printf("\n\t*****\t   Your New Password is %lu   \t*****\n\n",
                   curr->Pass);
            break;
        } else {
            printf("\n Worng Password, remainning trials : %d \n", x);
        }
    }
}

/*
 * Function : for Depositing on my account increasing My Balance of money 
 * Operands : Curr : the current user account that I want to Deposit to
 */
void Deposit_Acc(client_Acc *curr) {
    uint32 Dep;
    printf("\nPlease Enter Your Deposit -: ");
    scanf("%lu", &Dep);
    curr->Balance = curr->Balance + Dep;
    printf("   ---------------------------------------\n");
    printf("-------    Your Cash After Deposit %lu    -------\n",
           curr->Balance);
    printf("   ---------------------------------------\n");
}
	
/*******************------------------------------E.N.D--------------------------***********************/