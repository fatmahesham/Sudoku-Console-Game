#include "Sudoku.h"
#include <iostream>
#include <cstdlib>  //for srand(), rand()
#include <ctime>    //for time for srand()

using namespace std;

/*
If random numbers are generated with rand() without first calling srand(),
 your program will create the same sequence of numbers each time it runs
The rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX).
*/


Sudoku:: Sudoku()
{

    quiz=new char* [9];
    for(int i=0; i<9; i++)
        quiz[i]=new char [9];
    sol=new char* [9];
    for(int i=0; i<9; i++)
        sol[i]=new char [9];


/*
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
           quiz[i][j]=new char;
*/

//    quiz=new char [9][9];

/*

    quiz={{'1','2','3','4','5','6','7','8','9'},
              {'4','5','6','7','8','9','1','2','3'},
              {'7','8','9','1','2','3','4','5','6'},
              {'2','3','4','5','6','7','8','9','1'},
              {'5','6','7','8','9','1','2','3','4'},
              {'8','9','1','2','3','4','5','6','7'},
              {'3','4','5','6','7','8','9','1','2'},
              {'6','7','8','9','1','2','3','4','5'},
              {'9','1','2','3','4','5','6','7','8'}};
*/
    quiz[0][0]='1';
    quiz[0][1]='2';
    quiz[0][2]='3';
    quiz[0][3]='4';
    quiz[0][4]='5';
    quiz[0][5]='6';
    quiz[0][6]='7';
    quiz[0][7]='8';
    quiz[0][8]='9';

    quiz[1][0]='4';
    quiz[1][1]='5';
    quiz[1][2]='6';
    quiz[1][3]='7';
    quiz[1][4]='8';
    quiz[1][5]='9';
    quiz[1][6]='1';
    quiz[1][7]='2';
    quiz[1][8]='3';

    quiz[2][0]='7';
    quiz[2][1]='8';
    quiz[2][2]='9';
    quiz[2][3]='1';
    quiz[2][4]='2';
    quiz[2][5]='3';
    quiz[2][6]='4';
    quiz[2][7]='5';
    quiz[2][8]='6';

    quiz[3][0]='2';
    quiz[3][1]='3';
    quiz[3][2]='4';
    quiz[3][3]='5';
    quiz[3][4]='6';
    quiz[3][5]='7';
    quiz[3][6]='8';
    quiz[3][7]='9';
    quiz[3][8]='1';

    quiz[4][0]='5';
    quiz[4][1]='6';
    quiz[4][2]='7';
    quiz[4][3]='8';
    quiz[4][4]='9';
    quiz[4][5]='1';
    quiz[4][6]='2';
    quiz[4][7]='3';
    quiz[4][8]='4';

    quiz[5][0]='8';
    quiz[5][1]='9';
    quiz[5][2]='1';
    quiz[5][3]='2';
    quiz[5][4]='3';
    quiz[5][5]='4';
    quiz[5][6]='5';
    quiz[5][7]='6';
    quiz[5][8]='7';

    quiz[6][0]='3';
    quiz[6][1]='4';
    quiz[6][2]='5';
    quiz[6][3]='6';
    quiz[6][4]='7';
    quiz[6][5]='8';
    quiz[6][6]='9';
    quiz[6][7]='1';
    quiz[6][8]='2';

    quiz[7][0]='6';
    quiz[7][1]='7';
    quiz[7][2]='8';
    quiz[7][3]='9';
    quiz[7][4]='1';
    quiz[7][5]='2';
    quiz[7][6]='3';
    quiz[7][7]='4';
    quiz[7][8]='5';

    quiz[8][0]='9';
    quiz[8][1]='1';
    quiz[8][2]='2';
    quiz[8][3]='3';
    quiz[8][4]='4';
    quiz[8][5]='5';
    quiz[8][6]='6';
    quiz[8][7]='7';
    quiz[8][8]='8';
/*
    print(quiz);
    shuffle();
    print(quiz);
    print(sol);
*/
}


void Sudoku:: shuffle()
{
    srand(time(NULL));
    int offset=0; //it is added to the remainder by 3 to keep the changed rows or columns in
                  //the same block(square 3x3

    /* shuffle columns  */
    for(int i=0; i<9; i++)
    {
        int k=rand()%3;
        for(int j=0; j<9; j++)
        {
            char temp =quiz[j][i];
            quiz[j][i]=quiz[j][k+offset];
            quiz[j][k+offset]=temp;
        }
        if(i%3==2)
            offset+=3;
    }

    /* shuffle rows  */
    offset=0;
    for(int i=0; i<9; i++)
    {
        int l=rand()%3;
        for(int j=0; j<9; j++)
        {
            char temp=quiz[i][j];
            quiz[i][j]=quiz[l+offset][j];
            quiz[l+offset][j]=temp;
        }
        if(i%3==2)
            offset+=3;
    }

    /* replace every number with another */
    char num[9]={'1','2','3','4','5','6','7','8','9'};
    for(int i=0; i<9; i++)
    {
        int n=rand()%9;
        char temp=num[i];
        num[i]=num[n];
        num[n]=temp;
    }

    /* copy sol array to quiz array */
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            sol[i][j]=quiz[i][j];

}

void Sudoku:: print(char** ptr)
{
    for(int i=0; i<9; i++)
    {
          for(int j=0; j<9; j++)
          {
              cout << ptr[i][j]<<" ";
              if(j%3 == 2 && j!=8)
                cout<<"| ";
          }
          cout<<"\n";
          if(i%3 == 2 && i!=8)
            cout<<"---------------------\n";
    }
    cout <<"\n\n";
}

void Sudoku:: playGame()
{
    /* ************************************* INTRODUCTION ************************************* */
    char checkStepByStep; //or check your solution after finishing ... n for no, y for yes
    char choiceDegree;   // choice to play a game of a unique solution by pressing o or a game without
                        //a unique solution by pressing s
    int difficultyDegree;
        // A puzzle with a unique solution must have at least 17 numbers
        //every degree hide 5 numbers except the last one hide 4 numbers only
    bool unacceptableChoice=1;
    int charNum;    // charNum is the number of hidden numbers

    cout<<"RULES OF SUDOKU-GAME\n"
        <<"*********************\n"
        <<" 1- Use numbers from 1 to 9 to fill the board\n"
        <<" 2- Repetitions are prohibited for the same row, the same column and the same square\n\n\n";

    cout<<"CHOOSE THE DEGREE OF THE DIFFICULTY\n"
        <<"************************************\n"
        <<"Do you want to choose the number of hidden numbers or to play special levels\n"
        <<"Special levels are the levels that have not unique solution\n"
        <<"for first choice press o for the second choice press s\n";

    cin>>choiceDegree;
    while(unacceptableChoice)
    {
/*
        if(choiceDegree=='y')
        {
            unacceptableChoice=0;
            cout<<"Choose the level of the game (number from 1 to 13)\n";
            while (1)
            {
                cin>>difficultyDegree;
                if(difficultyDegree>13 || difficultyDegree<1 )
                    cout<<"Out Of Boud number\n"
                        <<"Please,enter another one\n";
                else
                    break;
            }
            charNum=difficultyDegree*5;
            if(difficultyDegree==13)
                charNum--;
       }
*/
       if(choiceDegree=='o')
       {
           unacceptableChoice=0;
           cout<<"Enter a number of hidden places (number from 1 to 64)\n";
           while (1)
            {
                cin>>charNum;
                if(charNum>64 || charNum<1 )
                    cout<<"Out Of Boud number\n"
                        <<"Please,enter another one\n";
                else
                    break;
            }
       }

       else if(choiceDegree=='s')
       {
           unacceptableChoice=0;
           cout<<"Enter a number of hidden places (number from 65 to 81)\n";
           while (1)
            {
                cin>>charNum;
                if(charNum<65 || charNum>81)
                    cout<<"unacceptable number needed number\n"
                        <<"Please,enter another one\n";
                else
                    break;
            }
       }
       else
           cout<<"unacceptable choice ,please enter another one\n";
    }

    if(choiceDegree!='s')
    {

        cout<<"\n\n"
            <<"TO CHECK YOUR SOLUTION\n"
            <<"************************\n"
            <<"Do you want to check your solution step by step or after finishing?\n"
            <<"For the first choice press y for the second choice press n\n";
        cin>>checkStepByStep;
    }

    cout<<"\n\n"
        <<"TO PLAY THE GAME\n"
        <<"*****************\n"
        <<" 1- Enter the number of the row, the number of the column and the chosen number "
        <<"for solution separated by spaces\n"
        <<" 2- To enter another place ,please press ENTER key\n"
        <<" 3- When you finish entering your answer press 0\n\n\n";



    /* ************************************* HIDE NUMERS ****************************************** */
    int num[81]; //indees array
    for(int j=0; j<81; j++)
        num[j]=j;

    /* shuffle the array */
    srand(time(NULL));
    for(int i=0; i<81; i++)
    {
        int n=rand()%81;
        int temp=num[i];
        num[i]=num[n];
        num[n]=temp;
    }

    /* Choose the places with the unknown values */
    int firstPlaceIndex;
                    // firstPlaceIndex is the index of the begin of the sequence we use from num array
    if(charNum!=81)
        firstPlaceIndex=rand()%(81-charNum);
    else
        firstPlaceIndex=0; //if we use the previous condition we will have error (rand()%0)


/*
    //wrong code
    for(int i=0; i<charNum; i++)
        **(quiz+m+i)='?';
*/

    int index=num[firstPlaceIndex];  //index is a number between 0 and 80
    for(int i=0; i<charNum; i++)
    {
        int row=index/9;
        int column=index%9;
        quiz[row][column]='?';
        index=num[firstPlaceIndex+i+1];
    }

    print(quiz);
    cout<<"\n\n"
        <<"ROW  COLUMN  VALUE\n";

    /* ************************************** PLAY *********************************************** */
    bool knownValue; //elements which are not '?'
    int row, column, value;
    //char userSol[9][9];  //print(userSol) gives error
    char** userSol;
    userSol=new char*[9];
    for(int i=0; i<9; i++)
        userSol[i]=new char[9];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            userSol[i][j]=quiz[i][j];

    if(choiceDegree!='s')
    {
        float rightAnsContuer=0.0; //right answers counter , it is float to get the percentage
        float rightAnsPercentage;

        /* *************** read from user ************ */
        cin>>row;
        while(row!=0)
        {
            knownValue=1;
            while(knownValue)
            {
                cin>>column;
                cin>>value;
                if (row>0 && row<10 && column>0 && column <10 && quiz[row-1][column-1]=='?')
                    break;
                else
                {
                    cout<<"You determined place with determined value or you have entered"
                        <<" unsuitable value for row or column\n";
                    cin>>row;
                }
            }
            userSol[row-1][column-1]=(char)(value+48);
             if(checkStepByStep=='y')
             {
                if(sol[row-1][column-1]==userSol[row-1][column-1])
                    cout<<"  RIGHT\n";
                else
                    cout<<"  WRONG\n";
            }
            cin>>row;
        }

        /* ***** check & calculate the success percentage **** */
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                if(quiz[i][j]=='?')
                {
                    if(sol[i][j]==userSol[i][j])
                        rightAnsContuer++;
                }
        rightAnsPercentage=rightAnsContuer/charNum*100;
        cout<<"YOUR SOL\n\n";
        print(userSol);
        cout<<"\n\n\n"
            <<"RIGHT SOLUTION\n\n";
        print(sol);
        cout<<"\n\n\n";
        if(rightAnsPercentage==100.0)
            cout<<" ** *** YOU WIN *** **\n\n\n";
        else
            cout<<" YOUR SCORE\n"
                <<"             "
                <<rightAnsPercentage
                <<"\n\n\n";
    }

    /* **************** If Special Game ******************** */
    else
    {
        bool rightAns=1, tryAgain=1;
        bool exist[9];
        char choiceTryAgain;
        for(int i=0; i<9; i++)
            exist[i]=0; //default 0 .... not exist

        while(tryAgain)
        {
            rightAns=1;
            tryAgain=0;

            /* *************** read from user ************ */
            cin>>row;
            while(row!=0)
            {
                knownValue=1;
                while(knownValue)
                {
                    cin>>column;
                    cin>>value;
                    if (row>0 && row<10 && column>0 && column <10 && quiz[row-1][column-1]=='?')
                        break;
                    else
                    {
                        cout<<"You determined place with determined value or you have entered"
                            <<" unsuitable value for row or column\n";
                        cin>>row;
                    }
                }
                userSol[row-1][column-1]=(char)(value+48);
                cin>>row;
            }

            /* ***** Check rules in rows ******* */
            for(int i=0; i<9 && rightAns==1; i++)
            {
                for(int j=0; j<9 && rightAns==1; j++)
                {
                    int index=userSol[i][j]-48;  //index for exist array
                    if(exist[index]==0)
                        exist[index]=1;
                    else
                      {rightAns=0; cout<<"i= "<<i<<" j= "<<j<<"\n";}
                }
                for(int i=0; i<9; i++)
                    exist[i]=0; //default 0 .... not exist
            }

            /* ******* Check rules in columns ******* */
            for(int i=0; i<9 && rightAns==1; i++)
            {
                for(int i=0; i<9; i++)
                    exist[i]=0; //default 0 .... not exist
                for(int j=0; j<9 && rightAns==1; j++)
                {
                    int index=userSol[j][i]-48;  //index for exist array
                    if(exist[index]==0)
                        exist[index]=1;
                    else
                        rightAns=0;
                }
            }

            /* ******* Check rules in squares ******* */
            for(int i=0; i<9 && rightAns==1; i+=3)
                for(int j=0; j<9 && rightAns==1; j+=3)
                {
                    for(int i=0; i<9; i++)
                        exist[i]=0; //default 0 .... not exist
                    for(int k=0; k<3; k++)
                        for(int l=0; l<3; l++)
                        {
                            int index=userSol[i+k][j+l]-48;
                            if(exist[index]==0)
                                exist[index]=1;
                            else
                                rightAns=0;
                        }
                }
            /* ******* Try again ******* */
            if(!rightAns)
            {
                cout<<"Wrong Answer\n"
                    <<"Do you want to try again\n"
                    <<"If yes press y ,if not press any key\n";
                cin>>choiceTryAgain;
                if(choiceTryAgain=='y')
                    tryAgain=1;

            }
            else
            {
                cout<<" **** YOU WIN ****\n"
                    <<"Do you want to try to give another sol\n"
                    <<"If yes press y ,if not press any key\n";
                cin>>choiceTryAgain;
                if(choiceTryAgain=='y')
                    tryAgain=1;
            }
        }
    }
}
