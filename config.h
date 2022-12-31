/*
*Name : Hussein Muhammad Ahmad AlBaqry
*Embedded System Track 
*Group 4
*New Adminstrative Capital Branch
*/

// Header file ( Functions Prototypes - Macros - Declarating global variable)



#ifndef CONFIG_H_
#define CONFIG_H_	
#include "std_types.h"

/*-----------------------------------********************Standard Bank Account Template*********************--------------------------------------------*/

typedef struct client_Acc {
	
    uint8 Name[60];
    uint8 ID[20];
    uint8 Address[70];
    uint16 age;
    uint8 Guardian_ID[20];
    uint32 Balance;
    uint8 Account_Status;
    uint32 Bank_ACC_ID;
    uint32 Pass;

    struct client_Acc *Next;

} client_Acc;

/*-----------------------------------********************Admin Interface*********************--------------------------------------------*/


/*@brief:
 * Function Create a New Client & Append it to our list(DataBase) Linked List 
 * Operand : Head: takes The Start of the list to Know the end of  the list to append New one in sequence
 */
void Create_Account(client_Acc **head_ref);

/*@brief:
 * Function : The Data that will be provided Each Time while Creating a New client (Node)
 * Operand  : temp : The New client (Node) That created to Enter Data
 */
void Data(client_Acc *temp);

/*
 * Function : To Print The client_Bank_ID  and The client_Password
 * Operand  : Nod : The New client (Node) That created to Print The client_Bank_ID  and The client_Password
 */
void PrintN(client_Acc *Nod);

/*@brief:
 * Function : To Search In Data Of client account what client_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Operand  : head : The first Address of My data to go search in list on what client_account i want 
 *            ID   : the client Account ID to be opened
 */
void Search_Admin(client_Acc *head_ref, uint32 ID);

/*@brief:
 * Function : for Transaction Between Two Accounts The Current Account and The Account That I Want to Make Transaction With
 * Operand  : Curr : The current client 
 *            Head : The first Address To Search on The List with the account id that i want to transfer money to him
 */
void admin_Transaction(client_Acc *curr, client_Acc *head);

/*@brief:
 * Function : for changing the Account status to ("Active","Closed","Restricted") 
 * Operand  : Curr : The current client to change its account status 
 */
void Change_Account_Status(client_Acc *curr);

/*@brief:
 * Function : for Withdrawing money from my account(Balance)
 * Operand  : Curr : the current client account to Withdraw money from
 */
void Get_Cash(client_Acc *curr);

/*@brief:
 * Function : for Depositing on my account adding to My Balance
 * Operand  : Curr : the current client account to be Deposited with money 
 */
void Deposit_in_Account(client_Acc *curr);

/*-----------------------------------********************Client Interface*********************--------------------------------------------*/

/*
 * Function   : To Search the Data Of client account what client_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Operands   : head : The first Address of My data to go search in the list of which client_account I want 
 *              ID   : the Account ID that I want to open
 */
 
void Search(client_Acc *head_ref, uint32 ID);


/*
 * Function   : for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With
 * Operands   : Curr : The current client 
 *              Head : The first Address To Search on The List with the account ID that I want to transfer money to
 */
void make_Transaction (client_Acc *curr, client_Acc *head);


/*
 * Function   : That function make me change My Password Account
 * Operands   : Curr : The current client account to change its Password
 */
void Change_Password(client_Acc *curr);


/*
 * Function   : for Withdrawing money from my account
 * Operands   : Curr : the current client account to Withdraw money from
 */
void Get_Cash(client_Acc *curr);


/*
 * Function   : for Depositing my account increasing My Balance
 * Operands   : Curr : the current client account to be Deposited
 */
void Deposit_Acc(client_Acc *curr);



#endif