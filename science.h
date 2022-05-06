/** @file science.h
 * @brief This header file contains the questions of science topic.
 * @author Prabesh Timilsina.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define RED   "\x1B[31m" 
#define RESET "\x1B[0m"

/** @brief function science.
 * 
 * This is a void function with void argument.
 * This function takes user name, Ask them question, and store their score, date and time 
 * in a file.
 * @param name an array of character that stores the name of user.
 * @param score an integer variable storing the score.
 * @param i an integer variable.
 * @param arr an boolean array.
 * @param A an integer array.
 * @param msec integer variable used to calculate escaped time.
 * @param trigger an integer variable for time limit.
 */

void science()
{
     char name[30];
    int score=0;
    printf("\nPlease enter name:");
    scanf("%[^\n]%*c",name); // Taking User's name as input.
    system("cls");
    printf("\n\t\t\tSo you have choosen Science.");
    printf("\n\n*************************************************************************************************\n");
    printf("There are seven questions, Each question carries 5 marks and there is no negative marking.\n");
    printf("Remember you only have 2 minutes to answers the questions. Marks will be deducted if you take more time.\n");
    printf("\t\tPress any key to start the quiz:\n");
    getch();
    system("cls");

    int i;
    bool arr[7]={0};
    int A[7];
    srand(time(0));

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
    printf("\n\nA man presses more weight on earth at :\n");
    printf("Options:\n A.Sitting position\t B.Standing Position\n");
    printf("C.Lying Position\t D.None of these\n");
    
   if (toupper(getch())=='B')
    {
        printf("B. Correct answer!!");
        score= score+5;
        getch();
        break;
    }
    else{
        printf(RED"Sorry wrong answer."RESET); // Seting the color of text to red.
        getch();
        break;
    }

    case 1:
    printf("\n\nThe elimination of toxic nitrogenous waste and excess water in man is by :\n");
    printf("Options:\n A.Excretion\t B.Circulation\n");
    printf("C.Reproduction\t D.Polution\n");
   
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

    case 2:
    printf("\n\nThe liquid metal is :\n");
    printf("Options:\n A.Bismuth\t B.Magnesium\n");
    printf("C.Mercury\t D.Sodium\n");
   
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

    case 3:
    printf("\n\nWhich of the following is not a primary colour :\n");
    printf("Options:\n A.Red\t B.Blue\n");
    printf("C.Green\t D.Yellow\n");
   
   if (toupper(getch())=='D')
    {
        printf("D. Correct answer!!");
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
    printf("\n\nEndothermic reactions are those in which :\n");
    printf("Options:\nA. Heat is evolved\t B. Heat is absorbed\n");
    printf("C. Temperature increases\t D. Light is produced\n");
    
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
    printf("\n\nWhich blood cells are called 'Soldiers' of the body :\n");
    printf("Options:\nA. WBC\t B. Platelets\n");
    printf("C. RBC\t D. All of the above\n");
   
   if (toupper(getch())=='A')
    {
        printf("A. Correct answer!!\n");
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
    printf("\n\nAcid present in gastric juice is :\n");
    printf("Options:\nA. Hydrochloric Acid\t B. Citric Acid\n");
    printf("C. Sulphuric Acid\t D. Acetic Acid\n");
   
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
    msec=difference*1000/ CLOCKS_PER_SEC;//To get the number of milliseconds used by the CPU, we need to divide it by CLOCKS_PER_SEC.
    

    }
    if(msec>trigger) // reducing the score if the user takes any extra time.
    {
        printf("\n\nYou took more time. 5 marks is deducted from your score.");
        score=score-5;
    }
   
    printf("\n\n\tCongratulation!! %s. Your Score is %d.\n",name, score);
    printf("\t******************************************************\n");
    printf("\t\t Time taken %ds.", msec/1000);

    
    time_t t;
    time(&t); // time function for current time.
    FILE *fp; // a file pointer fp.
    fp=fopen("Records.txt", "a"); // opeaning a file Records.txt under append mode to add data.
    if(fp==NULL)
    {
        printf("ERROR!");
        exit(1);
    }
     // Storing player name, date, time, score, time taken to complete the quiz in a file.
    printf("\n \tScience Quiz saved at %s",ctime(&t));
	fprintf(fp,"\n\nScience\nName=%s\n", name);
	fprintf(fp,"Date and time=%s",ctime(&t));
	fprintf(fp,"Score=%d\n",score);
    fprintf(fp, "Time taken=%ds.", msec/1000);

    fclose(fp);

    // calling the menu function if the user wants to take the quiz again.
    char c;
    getch();
    system("cls");
    printf("\tWanna play again??\t[yes(Y)/no(ANY)]");
     if (toupper(getch())=='Y')
     {
         menu();
     }
     else{
         exit(0);
     }
    
}