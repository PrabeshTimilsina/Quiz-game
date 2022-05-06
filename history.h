/** @file history.h
 * @brief This header file contains the questions of history topic.
 * @author Prabesh Timilsina.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define RED   "\x1B[31m" 
#define RESET "\x1B[0m"

/** @brief function history.
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
void history()
{
    char name[50];
    int score=0;
    printf("\nPlease enter name:");
    scanf("%[^\n]%*c",name);// Taking User's name as input.
    system("cls");
    printf("\n\t\t\tSo you have choosen History.");
        printf("\n\n***********************************************************************************************\n");
    printf("There are seven questions, Each question carries 5 marks and there is no negative marking.\n");
    printf("Remember you only have 2 minutes to answers the questions.  Marks will be deducted if you take more time.\n");
    printf("\t\tPress any key to start the quiz:\n");
    getch();
    system("cls");

    int i;
    bool arr[7]={0}; // An array of boolean whose initial value are 0.
    int A[7]; // An integer array.
    time_t t;
    srand((unsigned)time(&t));

    for(i=0; i<7; i++) // Loop for creating random numbers without repeating.
    {
    int r = rand()%7; // creates a random number fron 0 to 6
    if(!arr[r])
    A[i]= r; // If r has not already been saved in integer array then saves it in the array.
    else
    i--;
    arr[r]=1;
    }

    int msec=0, trigger=120000; // integer parameters used for calculating time.
    clock_t before= clock(), difference; //function clock_t clock(void) returns the number of clock ticks elapsed since the program was launched.

    for(i=0; i<7; i++)// running the loop until 7 questions have been asked
    {
        if(msec<trigger){ // running the loop until time is up
        switch(A[i])
        {
            case 0:
    printf("\n\nThe Oldest civilization of the world is_____\n");
    printf("Options:\n A.The Aztecs\t B.The Harappa\n");
    printf("C.The Mesopotamian\tD.The Ancient Egyptian\n");
   
   if (toupper(getch())=='C')
    {
        printf("C. Correct answer!!");
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
    printf("\n\nThe First World war began in which year ?\n");
    printf("Options:\n A.1910\t B.1919\n");
    printf("C.1940\t D.1914\n");
    
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

    case 2:
    printf("\n\nThe oldest dynasty still ruling in which country ?\n");
    printf("Options:\n A.Iran\t B.Japan\n");
    printf("C.Austria\t D.England\n");
   
   if (toupper(getch())=='B')
    {
        printf("B.. Correct answer!!");
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
    printf("\n\n______was the first black republic in the world\n");
    printf("Options:\n A.Mali\t B.Haiti\n");
    printf("C.Egypt\t D.Kenya\n");
   
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

    case 4:
    printf("\n\nWho was the last king of Nepal?\n");
    printf("Options:\nA.Birendra Shah\t B.Gyanendra Shah\n");
    printf("C.Prithivi narayan Shah\t D.Ram Shah\n");
    
    
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
    printf("\n\nThe Malla king Jaya Sthiti organized the first official _____ in Nepal.\n");
    printf("Options:\nA.Religion\t B.Wars\n");
    printf("C.King\t D.Laws\n");
   
   if (toupper(getch())=='D')
    {
        printf("D. Correct answer!!\n");
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
    printf("\n\nFirst Kirati King?\n");
    printf("Options:\nA.Gasti\t B.Yalamber\n");
    printf("C.Mandev\t D.Prabesh\n");
    
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
    
        }
    }
     difference=clock()- before;
     // Calculating the time escaped every time the itiration is carried out.
    msec=difference*1000/ CLOCKS_PER_SEC;//To get the number of milliseconds used by the CPU, we need to divide it by CLOCKS_PER_SEC.
    
}
if(msec>trigger) // reducing the score if the user takes any extra time.
    {
        printf("\n\nYou took more time. 5 marks is deducted from your score.");
        score=score-5;
    }

     printf("\n\n\t\tTime taken %ds.",msec/1000);
    printf("\n***********************************************\n");
    printf("\tCongratulation!! %s. Your Score is %d", name, score);

    time_t ti;
    time(&ti); // time function for current time.
    FILE *fp;  // a file pointer fp.
    fp=fopen("Records.txt", "a"); // opeaning a file Records.txt under append mode to add data.
    if(fp==NULL)
    {
        printf("ERROR!");
        exit(1);
    }
    // Storing player name, date, time, score, time taken to complete the quiz in a file.
    printf("\nHistory Quiz saved at %s",ctime(&ti));
	fprintf(fp,"\n\nHistory\nName=%s\n", name);
	fprintf(fp,"Date and time=%s",ctime(&ti));
	fprintf(fp,"score=%d\n",score);
    fprintf(fp, "Time taken=%ds.", msec/1000);

    fclose(fp); // closing the file.
    
    // calling the menu function if the user wants to take the quiz again.
    char c;
    getch();
    system("cls");
    printf("\tWanna play again??[yes(Y)/no(ANY)]");
     if (toupper(getch())=='Y')
     {
         menu(); // calling the menu function from quiz.c 
     }
     else{
         exit(0);
     }

}