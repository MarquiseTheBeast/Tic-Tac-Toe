#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

class TicTacToeBoard
{
protected:
    // Vector of numbers on the game board
    vector<int> GameBoardNumberList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Tic Tac Toe game board
    char GameBoard[3][3] = 
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

public:
    // Print board
    void PrintBoard();

    // Player chooses the box they want to set
    void SetBox(char PlayerLetter);

    // AI selects its own box on turn
    void AI_SetBox(char PlayerLetter);

    // Check to see if there is 3 marks in a row
    bool bCheckBoxesForThreeMarks(bool bIsTwoPlayerGame);

    // Get box number using row and column input
    int GetBoxNumber(int row, int column);

    // Prints available box numbers in vector
    void BoxesAvailable();

    // Return the number of available boxes
    int BoxesRemaining();
};

#endif