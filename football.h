/** @file football.h
 * @brief This header file contains the questions of football topic.
 * @author Prabesh Timilsina.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define RED   "\x1B[31m" 
#define RESET "\x1B[0m"

/** @brief function football.
 * 
 * This is a void function with void argument.
 * This function takes user name, Ask them question, and store their score, date and time 
 * in a file.
 * 
 * @param name an array of character that stores the name of user.
 * @param score an integer variable storing the score.
 * @param i an integer variable.
 * @param arr an boolean array.
 * @param A an integer array.
 * @param msec integer variable used to calculate escaped time.
 * @param trigger an integer variable for time limit.
 */

void football()
{
    int score=0;
     char name[30];
    printf("\nPlease enter name:");
    scanf("%[^\n]%*c",name);// Taking User's name as input.
    system("cls");
    printf("\n\t\t\tSo you have choosen Football.");
        printf("\n\n*******************************************************************************************\n");
    printf("There are seven questions, Each question carries 5 marks and there is no negative marking.\n");
    printf("Remember you only have 2 minutes to answers the questions.  Marks will be deducted if you take more time.\n");
    printf("\t\tPress any key to start the quiz:\n");
    getch();
    system("cls");

    int i;
    bool arr[7]={0};
    int A[7];
    time_t t;
    srand((unsigned)time(&t));

    for(i=0; i<7; i++) // Loop for creating random numbers without repeating.
    {
    int r = rand()%7; // creates a random number fron 0 to 6
    if(!arr[r])
    A[i]= r; // If the number is not in the integer array then saves it in the array.
    else
    i--;
    arr[r]=1;
    }

    int msec=0, trigger=120000;
    clock_t before= clock(), difference; //function clock_t clock(void) returns the number of clock ticks elapsed since the program was launched.
    for(i=0; i<7; i++)
    {
        if(msec<trigger){ // running the loop until time is up
        switch(A[i])
        {
            case 0:
    printf("\n\nWhich of the following country won Football world Cup maximum times?\n");
    printf("Options:\nA.Gemany\t B.Italy\n");
    printf("C.Argentina\t D.Brazil\n");
    
   if (toupper(getch())=='D')
    {
        printf("D. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET);// Seting the color of text to red.
        getch();
        break;
    }

    case 1:
    printf("\n\nWho among the following player scored highest number of goals in Football World Cup?\n");
    printf("Options:\n A.Jurgen Klinsmann\t B.Meradona\n");
    printf("C.Miroslave Klose\t D.Pele\n");
    
   if (toupper(getch())=='C')
    {
        printf("C. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }

    case 2:
    printf("\n\nWhen was the first FIFA World Cup inaugurated?\n");
    printf("Options:\n A.1930\t B.1931\n");
    printf("C.1932\t D.1933\n");
   
   if (toupper(getch())=='A')
    {
        printf("A. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
       printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }

    case 3:
    printf("\n\nWhich of following team do not play in stripes?\n");
    printf("Options:\n A.Newcastle\t B.Southampton\n");
    printf("C.Tottenham Hotspur\t D.Lincoln City\n");
   
   if (toupper(getch())=='C')
    {
        printf("C. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }

    case 4:
    printf("\n\n When was first official international football match was played?.\n");
    printf("Options:\nA.1929\t B.1872\n");
    printf("C.1902\t D.1870\n");
  
   if (toupper(getch())=='B')
    {
        printf("B. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
       printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }

    case 5:
    printf("\n\nWho among the following achieved the first World Cup hat-trick?\n");
    printf("Options:\nA.Johino\t B.Bert Patenaude\n");
    printf("C. Lucien Laurent\t D.Pele\n");
  
   if (toupper(getch())=='B')
    {
        printf("B. Correct answer!!\n");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }

    case 6:
    printf("\n\nWhich is the governing body of Football Federations from Europe?\n");
    printf("Options:\nA.UEFA\t B.EFA\n");
    printf("C.UFA(E)\t D.FFE\n");
    
   if (toupper(getch())=='A')
    {
        printf("A. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET);
        getch();
        break;
    }
    
        }
    }
     difference=clock()- before;
    msec=difference*1000/ CLOCKS_PER_SEC;//To get the number of seconds used by the CPU, we need to divide it by CLOCKS_PER_SEC.
    
 }
 if(msec>trigger) // reducing the score if the user takes any extra time.
    {
        printf("\n\nYou took more time. 5 marks is deducted from your score.");
        score=score-5;
    }

    printf("\n\n\t\tTime taken %ds.",msec/1000);
    printf("\n\t***********************************************\n");
    printf("\tCongratulation!! %s. Your Score is %d",name, score);

    time_t ti;
    time(&ti); // time function for current time.
    FILE *fp; // a file pointer fp.
    fp=fopen("Records.txt", "a"); // opeaning a file Records.txt under append mode to add data.
    if(fp==NULL)
    {
        printf("ERROR!");
        exit(1);
    }
    // Storing player name, date, time, score, time taken to complete the quiz in a file.
    printf("\n\tFootball Quiz saved at %s",ctime(&ti));
	fprintf(fp,"\n\nFootball\nName=%s\n", name);
	fprintf(fp,"Date and time=%s",ctime(&ti));
	fprintf(fp,"Score=%d\n",score);
    fprintf(fp, "Time taken=%ds.", msec/1000);

    fclose(fp);
    
    // calling the menu function if the user wants to take the quiz again.
    char c;
    getch();
    system("cls");
    printf("\tWanna play again??[yes(Y)/no(ANY)]");
     if (toupper(getch())=='Y')
     {
         menu();
     }
     else{
         exit(0);
     }
}