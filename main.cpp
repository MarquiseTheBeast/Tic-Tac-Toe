#include <iostream>
#include <string>

#include "Board.h"
#include "Board.cpp"

using namespace std;

// Player turns
enum Turn
{
    P1_PLAYER,
    P2_PLAYER,
    AI
};

// Player letters
struct PlayerLetter
{
    const char P1_LETTER = 'X';
    const char P2_LETTER = 'O';
};

// Game
void Game(bool bIsTwoPlayerGame)
{
    // Object class
    TicTacToeBoard TheBoard;

    // Player letters
    PlayerLetter PLAYER_LETTER;

    // Used to check who turn it is
    // Will start with P1 by default
    Turn WhoTurn = P1_PLAYER;

    bool bGameOver = false;   // Checks if the game is over
    bool bGameRunning = true; // Game is running

    while (bGameRunning)
    {
        try
        {
            // Player 1 or Player 2 turn
            if (WhoTurn == P1_PLAYER || WhoTurn == P2_PLAYER)
            {
                // Print game board with available boxes
                cout << "\n";
                TheBoard.PrintBoard();
                TheBoard.BoxesAvailable();
                cout << "Boxes Remaining: " << TheBoard.BoxesRemaining() << endl;

                char letter;

                // Check who turn it is and set their letter
                if (WhoTurn == P1_PLAYER)
                {
                    cout << "\nP1 Turn" << endl;
                    letter = PLAYER_LETTER.P1_LETTER;
                }
                else if (WhoTurn == P2_PLAYER)
                {
                    cout << "\nP2 Turn" << endl;
                    letter = PLAYER_LETTER.P2_LETTER;
                }

                // Player will choose their box to set
                TheBoard.SetBox(letter);

                // Check if all boxes are used or if there is 3 marks in a row. If true, the games ends
                bGameOver = TheBoard.bCheckBoxesForThreeMarks(bIsTwoPlayerGame);

                if (bGameOver)
                {
                    bGameRunning = false;
                }
                else
                {
                    // Check if the game is two player mode. If not, turn is AI
                    if (bIsTwoPlayerGame && WhoTurn == P1_PLAYER)
                    {
                        WhoTurn = P2_PLAYER;
                    }
                    else if (bIsTwoPlayerGame && WhoTurn == P2_PLAYER)
                    {
                        WhoTurn = P1_PLAYER;
                    }
                    else
                    {
                        WhoTurn = AI;
                    }
                }
            }

            // AI Turn
            else if (WhoTurn == AI)
            {
                // AI will use 'O'
                char letter = PLAYER_LETTER.P2_LETTER;

                cout << "\nAI Turn" << endl;

                TheBoard.AI_SetBox(letter);

                // Check if all boxes are used or if there is 3 marks in a row. If true, the games ends
                bGameOver = TheBoard.bCheckBoxesForThreeMarks(bIsTwoPlayerGame);

                if (bGameOver)
                {
                    bGameRunning = false;
                }
                else
                {
                    WhoTurn = P1_PLAYER;
                }
            }

            // Error if turn is out of range
            else
            {
                throw runtime_error{"Turn out of range"};
            }
        }
        catch (runtime_error &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int main()
{
    bool bRunning = true;
    bool bIsTwoPlayerGame;

    cout << "\nWelcome!" << endl;

    while (bRunning)
    {
        try
        {
            char selection;

            // Player will select the mode with the selected letter input
            cout << "\nA. P1 vs P2" << endl; // Player 1 vs Player 2
            cout << "B. P1 vs AI" << endl;   // Player vs AI
            cout << "C. Rules" << endl;      // Print game rules
            cout << "D. Quit" << endl;       // Exit program

            cout << "\nEnter letter: ";
            cin >> selection;

            switch (selection)
            {
            // Player 1 vs Player 2
            case 'a':
            case 'A':
                cout << "\nP1 vs P2" << endl;

                bIsTwoPlayerGame = true;
                Game(bIsTwoPlayerGame);
                break;

            // Player 1 vs AI
            case 'b':
            case 'B':
                cout << "\nP1 vs AI" << endl;

                bIsTwoPlayerGame = false;
                Game(bIsTwoPlayerGame);
                break;

            // Print game rules
            case 'c':
            case 'C':
                cout << "\nThere are 9 empty boxes." << endl;
                cout << "Each player fills a box with their designed letter on each turn." << endl;
                cout << "Player selects a box by entering a row and column number between 0 and 2." << endl;
                cout << "Whoever has 3 marks in a row (up, down, across, or diagonally) wins the game." << endl;
                cout << "If all 9 boxes are filled and there are no 3 marks in a row, the game ends with a tie." << endl;
                break;

            // Exit program
            case 'd':
            case 'D':
                bRunning = false;
                break;

            // Prints if invalid input or selection was detected
            default:
                throw "\nInvalid input or selection\n";
                break;
            }
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }

    return 0;
}