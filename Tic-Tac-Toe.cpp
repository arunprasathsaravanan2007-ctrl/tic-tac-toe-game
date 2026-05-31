#include <iostream>

using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
            {
                cout << " | ";
            }
        }

        cout << endl;

        if(i < 2)
        {
            cout << "---|---|---" << endl;
        }
    }

    cout << "\n";
}

bool makeMove(int choice)
{
    char mark = choice + '0';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == mark)
            {
                board[i][j] = currentPlayer;
                return true;
            }
        }
    }

    return false;
}

bool checkWinner()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
        {
            return true;
        }

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
        {
            return true;
        }
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
    {
        return true;
    }

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
    {
        return true;
    }

    return false;
}

bool isDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void resetBoard()
{
    char value = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }

    currentPlayer = 'X';
}

int main()
{
    char playAgain;

    do
    {
        resetBoard();

        bool gameOver = false;

        while(!gameOver)
        {
            displayBoard();

            int choice;

            cout << "Player " << currentPlayer
                 << ", Enter Position (1-9): ";

            cin >> choice;

            if(choice < 1 || choice > 9)
            {
                cout << "\nInvalid Position!\n";
                continue;
            }

            if(!makeMove(choice))
            {
                cout << "\nPosition Already Taken!\n";
                continue;
            }

            if(checkWinner())
            {
                displayBoard();

                cout << "\nPlayer "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if(isDraw())
            {
                displayBoard();

                cout << "\nGame Draw!\n";

                gameOver = true;
            }
            else
            {
                if(currentPlayer == 'X')
                {
                    currentPlayer = 'O';
                }
                else
                {
                    currentPlayer = 'X';
                }
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}