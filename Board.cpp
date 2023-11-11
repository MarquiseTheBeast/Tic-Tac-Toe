#include "Board.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// Prints the tic-tac-toe board
void TicTacToeBoard::PrintBoard()
{
    cout << "Row 0  -  | " << GameBoard[0][0] << " | " << GameBoard[0][1] << " | " << GameBoard[0][2] << " |" << endl;
    cout << "          -------------" << endl;
    cout << "Row 1  -  | " << GameBoard[1][0] << " | " << GameBoard[1][1] << " | " << GameBoard[1][2] << " |" << endl;
    cout << "          -------------" << endl;
    cout << "Row 2  -  | " << GameBoard[2][0] << " | " << GameBoard[2][1] << " | " << GameBoard[2][2] << " |" << endl;
}

// Check if there is any 3 marks in a row
bool TicTacToeBoard::bCheckBoxesForThreeMarks(bool bIsTwoPlayerGame)
{
    string SecondPlayer;

    // Checks if game is two player, otherwise sets the second player string to AI
    if (bIsTwoPlayerGame)
    {
        SecondPlayer = "P2";
    }
    else
    {
        SecondPlayer = "AI";
    }

    if (GameBoard[0][0] == 'X' && GameBoard[0][1] == 'X' && GameBoard[0][2] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][0] == 'O' && GameBoard[0][1] == 'O' && GameBoard[0][2] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[1][0] == 'X' && GameBoard[1][1] == 'X' && GameBoard[1][2] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[1][0] == 'O' && GameBoard[1][1] == 'O' && GameBoard[1][2] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[2][0] == 'X' && GameBoard[2][1] == 'X' && GameBoard[2][2] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[2][0] == 'O' && GameBoard[2][1] == 'O' && GameBoard[2][2] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[0][0] == 'X' && GameBoard[1][0] == 'X' && GameBoard[2][0] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][0] == 'O' && GameBoard[1][0] == 'O' && GameBoard[2][0] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[0][1] == 'X' && GameBoard[1][1] == 'X' && GameBoard[2][1] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][1] == 'O' && GameBoard[1][1] == 'O' && GameBoard[2][1] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[0][2] == 'X' && GameBoard[1][2] == 'X' && GameBoard[2][2] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][2] == 'O' && GameBoard[1][2] == 'O' && GameBoard[2][2] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[0][0] == 'X' && GameBoard[1][1] == 'X' && GameBoard[2][2] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][0] == 'O' && GameBoard[1][1] == 'O' && GameBoard[2][2] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    if (GameBoard[0][2] == 'X' && GameBoard[1][1] == 'X' && GameBoard[2][0] == 'X')
    {
        cout << "\n";
        PrintBoard();
        cout << "\nP1 wins the game" << endl;
        return true;
    }
    else if (GameBoard[0][2] == 'O' && GameBoard[1][1] == 'O' && GameBoard[2][0] == 'O')
    {
        cout << "\n";
        PrintBoard();
        cout << "\n"
             << SecondPlayer << " wins the game" << endl;
        return true;
    }

    // If all boxes are filled and no winner, game ends with tie
    if (GameBoardNumberList.size() == 0)
    {
        cout << "\n";
        PrintBoard();
        cout << "\nTie!"
             << endl;
        return true;
    }

    return false;
}

// Function to check if selected box is valid and not used
void TicTacToeBoard::SetBox(char PlayerLetter)
{
    int convertedBoxNumber;
    char Box;
    int BoxNumber;
    int row;
    int column;

    bool bSelectingBox = true;

    while (bSelectingBox)
    {
        try
        {
            // Player enters the row and column to select the box number
            cout << "Enter row: ";
            cin >> row;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw "\nInput must be a number\n";
            }

            cout << "Enter column: ";
            cin >> column;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw "\nInput must be a number\n";
            }

            // Get selected box number
            BoxNumber = GetBoxNumber(row, column);

            // Used to find and erase the number found in the vector list based on box selection
            auto EraseFoundNumber = find(GameBoardNumberList.begin(), GameBoardNumberList.end(), BoxNumber);

            if (BoxNumber == -1)
            {
                throw "\nNumber out of range\n";
            }

            // Linear seacrch to check if the selected box number is available;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Box = GameBoard[row][column];

                    // Check if box contains a player letter
                    if (Box == 'X' || Box == 'O')
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Box already used";
                    }

                    // Convert number char to int
                    convertedBoxNumber = GameBoard[i][j] - '0';

                    if (convertedBoxNumber == BoxNumber)
                    {
                        // Set the box to the player's letter
                        GameBoard[i][j] = PlayerLetter;

                        // Erase box number in vector list
                        GameBoardNumberList.erase(EraseFoundNumber);

                        if (PlayerLetter == 'O')
                        {
                            cout << "P2 selected box " << BoxNumber << endl;
                        }
                        else if (PlayerLetter == 'X')
                        {
                            cout << "P1 selected box " << BoxNumber << endl;
                        }

                        bSelectingBox = false;
                        break;
                    }
                }

                if (convertedBoxNumber == BoxNumber)
                {
                    break;
                }
            }
        }
        catch (const char *Invalid)
        {
            cout << Invalid << endl;
        }
    }
}

void TicTacToeBoard::AI_SetBox(char PlayerLetter)
{
    int BoxNumber;
    bool bSelectingBox = true;

    try
    {
        // AI will do while loop until it places letter in a available box
        while (bSelectingBox)
        {
            // Randomize vector number
            srand(time(0));
            int size = GameBoardNumberList.size(); // Size of vector
            int RandomNumber = rand() % size;

            BoxNumber = GameBoardNumberList.at(RandomNumber);

            // Used to erase the selected box number in vector
            auto EraseNumber = find(GameBoardNumberList.begin(), GameBoardNumberList.end(), BoxNumber);

            // AI selects the randomized box number it has got and checks if the box number is not used before setting it
            switch (BoxNumber)
            {
            case 1:
                if (GameBoard[0][0] == 'X' || GameBoard[0][0] == 'O')
                {
                }
                else
                {
                    GameBoard[0][0] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 2:
                if (GameBoard[0][1] == 'X' || GameBoard[0][1] == 'O')
                {
                }
                else
                {
                    GameBoard[0][1] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 3:
                if (GameBoard[0][2] == 'X' || GameBoard[0][2] == 'O')
                {
                }
                else
                {
                    GameBoard[0][2] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 4:
                if (GameBoard[1][0] == 'X' || GameBoard[1][0] == 'O')
                {
                }
                else
                {
                    GameBoard[1][0] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 5:
                if (GameBoard[1][1] == 'X' || GameBoard[1][1] == 'O')
                {
                }
                else
                {
                    GameBoard[1][1] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 6:
                if (GameBoard[1][2] == 'X' || GameBoard[1][2] == 'O')
                {
                }
                else
                {
                    GameBoard[1][2] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 7:
                if (GameBoard[2][0] == 'X' || GameBoard[2][0] == 'O')
                {
                }
                else
                {
                    GameBoard[2][0] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 8:
                if (GameBoard[2][1] == 'X' || GameBoard[2][1] == 'O')
                {
                }
                else
                {
                    GameBoard[2][1] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            case 9:
                if (GameBoard[2][2] == 'X' || GameBoard[2][2] == 'O')
                {
                }
                else
                {
                    GameBoard[2][2] = PlayerLetter;
                    GameBoardNumberList.erase(EraseNumber);
                    bSelectingBox = false;
                }
                break;
            default:
                throw "\nAI error. Number out of range.\n";
                break;
            }
        }

        cout << "AI selected box " << BoxNumber << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

// Find number in vector list
int TicTacToeBoard::GetBoxNumber(int row, int column)
{
    int n;

    // Box number based on row and column input
    if (row == 0 && column == 0) // 1
    {
        n = 1;
    }
    else if (row == 0 && column == 1) // 2
    {
        n = 2;
    }
    else if (row == 0 && column == 2) // 3
    {
        n = 3;
    }
    else if (row == 1 && column == 0) // 4
    {
        n = 4;
    }
    else if (row == 1 && column == 1) // 5
    {
        n = 5;
    }
    else if (row == 1 && column == 2) // 6
    {
        n = 6;
    }
    else if (row == 2 && column == 0) // 7
    {
        n = 7;
    }
    else if (row == 2 && column == 1) // 8
    {
        n = 8;
    }
    else if (row == 2 && column == 2) // 9
    {
        n = 9;
    }
    else
    {
        return -1;
    }

    return n;
}

// Returns the available box numbers left on the game board
void TicTacToeBoard::BoxesAvailable()
{
    int BoxNumber;
    int size = GameBoardNumberList.size() - 1;
    int i = 0;

    cout << "\nBoxes Available: ";

    // Print out each available number in vector
    while (i != size)
    {
        cout << GameBoardNumberList.at(i) << ", ";
        i++;
    }

    cout << GameBoardNumberList.at(i) << endl;
}

// Return total number of boxes left
int TicTacToeBoard::BoxesRemaining()
{
    return GameBoardNumberList.size();
}