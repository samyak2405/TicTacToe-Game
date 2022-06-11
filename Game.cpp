#include <bits/stdc++.h>
#include "coin_toss.h"
using namespace std;

class TicTacToe
{
private:
    char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row;
    int col;
    char marker = 'x';
    bool draw = false;
    string s1, s2;
    int counter = 0;

public:
    void getNames();
    void whoFirst();
    void displayBoard();
    bool gameLogic();
    bool check();
    void winner();
};

void TicTacToe::getNames()
    {
        cout << "Enter the name of the player : ";
        getline(cin, s1);
        cout << "\nEnter the name of the player : ";
        getline(cin, s2);
        cout << s1 << " is player1\n";
        cout << s2 << " is player2\n";
    }

void TicTacToe::whoFirst()
{
    int val = coinToss();
    if (val == 1)
    {
        marker = 'x';
        cout << s1 << " is playing first\n";
    }
    else
    {
        marker = '0';
        cout << s2 << " is playing first\n";
    }
}

void TicTacToe::displayBoard()
{
    cout << "     |        |      \n";
    cout << "  " << grid[0][0] << "  |    " << grid[0][1] << "   |   " << grid[0][2] << "  \n";
    cout << "_____|________|______\n";
    cout << "     |        |      \n";
    cout << "  " << grid[1][0] << "  |    " << grid[1][1] << "   |   " << grid[1][2] << "  \n";
    cout << "_____|________|______\n";
    cout << "     |        |      \n";
    cout << "  " << grid[2][0] << "  |    " << grid[2][1] << "   |   " << grid[2][2] << "  \n";
    cout << "     |        |      \n";
    cout << endl
         << endl;
    return;
}

bool TicTacToe::gameLogic()
{
    if (counter == 9)
    {
        return true;
    }
    counter++;
    int block_number;
    if (marker == 'x')
    {
        cout << s1 << " Please Enter : ";
        cin >> block_number;
        cout << endl;
    }
    if (marker == '0')
    {
        cout << s2 << " Please Enter : ";
        cin >> block_number;
        cout << endl;
    }
    if (block_number == 1)
    {
        row = 0;
        col = 0;
    }
    if (block_number == 2)
    {
        row = 0;
        col = 1;
    }
    if (block_number == 3)
    {
        row = 0;
        col = 2;
    }
    if (block_number == 4)
    {
        row = 1;
        col = 0;
    }
    if (block_number == 5)
    {
        row = 1;
        col = 1;
    }
    if (block_number == 6)
    {
        row = 1;
        col = 2;
    }
    if (block_number == 7)
    {
        row = 2;
        col = 0;
    }
    if (block_number == 8)
    {
        row = 2;
        col = 1;
    }
    if (block_number == 9)
    {
        row = 2;
        col = 2;
    }
    else if (block_number < 1 or block_number > 9)
        cout << "INVALID...!!!" << endl;
    if (marker == 'x' and grid[row][col] != 'x' and grid[row][col] != '0')
    {
        grid[row][col] = 'x';
        marker = '0';
    }

    else if (marker == '0' and grid[row][col] != 'x' and grid[row][col] != '0')
    {
        grid[row][col] = '0';
        marker = 'x';
    }

    else
    {
        cout << "There is no empty grid!" << endl;
        gameLogic();
    }
    return false;
}

bool TicTacToe::check()
{
    // If the players win either horizontally or vertically
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] and grid[i][0] == grid[i][2] or grid[0][i] == grid[1][i] and grid[0][i] == grid[2][i])
            return true;
    }
    // If the players win diagonally or reverse diagonally
    if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] or grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0])
        return true;
    // If game is not finished yet
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 'x' and grid[i][j] != '0')
                return false;
        }
    }
    // If game is tied
    draw = true;
    return false;
}

void TicTacToe::winner()
{
    if (marker == 'x' and !draw)
        cout << s2 << " wins";
    else if (marker == '0' and !draw)
        cout << s1 << " wins";
    else
        cout << "It's a draw" << endl;
}

int main()
{
    TicTacToe game1;
    // Enter the names of two players
    game1.getNames();
    // Randomly picks the player who will start first
    game1.whoFirst();
    // This loop will iterate unless anyone of the players win or the game is drawed.
    while (!game1.check())
    {
        // Displays the board
        game1.displayBoard();
        // Runs the main logic
        if (game1.gameLogic())
            break;
        game1.check();
    }
    // Tells about who is the winner or whether the game is draw
    game1.winner();
    cout << endl;
    game1.displayBoard();
    return 0;
}