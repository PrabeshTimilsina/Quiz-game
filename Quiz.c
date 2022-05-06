/** @file Quiz.c
 * @brief A Multiple Choice Question quiz game created in c.
 * 
 * This is the main body of the program.
 * 
 * @author    : Prabesh Timilsina.
 * Roll no    : 58
 * Department : Computer Engineering
 * 
 * Date: 2021/08/17
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//Included different header files that were creaded by me for better modularity of program.
#include "science.h"
#include "history.h"
#include "football.h"
#include "CLanguage.h"

#define RED   "\x1B[31m" //defining the value of red and reset(collors used for displaying wrong answer).
#define RESET "\x1B[0m"

/** @brief menu function.
 * This function takes user input and take them to the topic that they choosed.
 */
int menu();

/** @brief ClearRecords function.
 * This function clears the previously stored records.
 */
void ClearRecords();

void records();

/** @brief the main function.
 * 
 * This function consist of menu function which again have different other
 * functions for different questions.
 * 
 * This is just welcoming page of the program.
 * 
 * @return 0
 */
int main()
{
    system("cls");
    printf("\t\tQuiz Game\n");
    printf("\t******************************\n");
    printf("\t\tWelcome\n");
    printf("\t******************************\n\n");
    
    printf("\tpress any key to contonue.\n");
    getch();
    system("cls");
    
    menu(); // Calling the menu function
    return 0;
}

/** @brief menu function.
 * 
 * This function takes user input and take them to the topic that they choosed.
 * It uses if else statement to take the user to the desired quiz.
 * 
 * @param choice an character used to take user input.
 */
int menu()
{
    char choice;
    system("cls"); // Clearing the screen.
    printf("\n\t\t\tMenu\n");
    printf("************************************************************\n");
    printf("This game consist of different questions from different field.\n \tSo choose what topic you want to attempt.\n");
    printf("\n\tFor science press 'S'");
    printf("\n\tFor C language press 'C'");
    printf("\n\tFor History press 'H'");
    printf("\n\tFor Football press 'F'");
    printf("\n\tTo erase current records press 'E'");
    printf("\n\tTo view current records press 'R'");
    printf("\n\tIf you want to quit press'Q'\n");
    printf("Your name along with your score will be recorded for future refrence.\n\n");

    choice=toupper(getch());

    if (choice=='S')
    {
        printf("S");
        science(); // A function called from the header file science.h.
    }
    else if(choice=='C')
    {
        printf("C");
        c_lang(); // A function called from the header file CLanguage.h.
    }
    else if (choice=='H')
    {
        printf("H");
        history(); // A function called from the header file history.h.
    }
    else if(choice=='F')
    {
        printf("F");
        football(); // A function called from the header file football.h.
    }
    else if (choice=='Q')
    {
        system("cls");
        printf("\n\n\n\t\t\tGood Bye.");
        getch();
        return 0;
    }
     else if (choice=='E')
    {
        system("cls");
        ClearRecords(); // Calling function ClearRecords
        printf("\tRecords have been cleared.\n    Press any key to go to menu.");
        getch();
        menu();
    }
     else if (choice=='R')
    {
        system("cls");
        records(); // Calling function Records
        getch();
        menu();
    }
    else{
        printf("Invalid choice");
        getch();
        menu();
    }
    return 0;
}

/** @brief ClearRecords function
 * This function clears the records that were previously stored in text file.
 */
void ClearRecords(){

    fclose(fopen("Records.txt", "w")); //Opening and closing a file in write mode.
}

void records()
{
    FILE *fpointer;
    fpointer= fopen("Records.txt", "r");
    char line[200];

    while(!feof(fpointer))
    {
        fgets(line, 200, fpointer);
        puts(line);
    }
    fclose(fpointer);
}