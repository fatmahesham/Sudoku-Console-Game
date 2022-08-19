#include <iostream>
#include <cstdlib>  //for srand(), rand()
#include <ctime>    //for time for srand()
//#include <random>
#include<iomanip>   //for setw(int)
#include "Sudoku.h"

using namespace std;

int main()
{
    /*
    cout<<"1 2 3 | 4 5 6 | 7 8 9\n";
    cout<<"4 5 6 | 7 8 9 | 1 2 3\n";
    cout<<"7 8 9 | 1 2 3 | 4 5 6\n";
    cout<<"---------------------\n";
    cout<<"2 3 4 | 5 6 7 | 8 9 1\n";
    cout<<'\0' << 33<<"\n";
    int ptr[2][2]={{1,2},{3,4}};
    for(int i=0; i<2; i++)
       {
          for(int j=0; j<2; j++)
             cout <<ptr[i][j]<<" ";
          cout<<"\n";
       }
    srand(time(NULL));
    for (int j=0; j<5; j++){
     for(int i=0; i<3; i++){
        //srand(time(NULL));
        int k=rand()%3;
        cout<< k <<" ";
     }
    cout<<"\n";
    }
*/

/*
    int m=rand()%(81-10);
    int row=m/8;
    int column=m%8;
    cout<<row<<"  "<<column;
*/
/*
    int num[5];
    for(int i=0; i<5; i++)
        cin>>num[i];
    for(int i=0; i<5; i++)
        cout<<num[i];
*/

    Sudoku s;
    while(1)
    {
        char playAgain;
        s.shuffle();
        s.playGame();
        cout<<"Do you want to play again?\n"
            <<"press n for no or any other key for yes\n";
        cin>>playAgain;
        if(playAgain=='n')
            break;
    }

/*
    int c=9;
    char b=(char)c;
    cout<<c;
*/
/*
    int a,b,c;
    cin>>a>>setw(5)>>b>>setw(10)>>c;
*/
    return 0;
}
