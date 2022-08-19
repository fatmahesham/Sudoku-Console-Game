#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

class Sudoku
{
private:
    //char quiz[9][9], sol[9][9];
    char **quiz, **sol;

public:
    Sudoku();
    void shuffle();
    void print(char**);
    void playGame();
};


#endif // SUDOKU_H_INCLUDED
