#include <iostream>
using namespace std;

void printGrid(char grid[3][3])
{
    cout << endl;
    cout << "   0   1   2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void initializeGrid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' ';
        }
    }
}

bool hasWon(char grid[3][3], char symbol)
{
    for (int r = 0; r < 3; r++)
    {
        if (grid[r][0] == symbol && grid[r][1] == symbol && grid[r][2] == symbol)
        {
            return true;
        }
    }

    for (int c = 0; c < 3; c++)
    {
        if (grid[0][c] == symbol && grid[1][c] == symbol && grid[2][c] == symbol)
        {
            return true;
        }
    }

    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
    {
        return true;
    }

    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
    {
        return true;
    }

    return false;
}

bool isGridFull(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char grid[3][3], char currentPlayer)
{
    int x, y;

    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your move." << endl;
        cout << "Row: ";
        cin >> x;
        cout << "Column: ";
        cin >> y;

        if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            cout << "Invalid coordinates. Try again." << endl << endl;
            continue;
        }

        if (grid[x][y] != ' ')
        {
            cout << "Cell already occupied. Try again." << endl << endl;
            continue;
        }

        grid[x][y] = currentPlayer;
        break;
    }
}

void playTicTacToe()
{
    char grid[3][3];
    initializeGrid(grid);

    char currentPlayer = 'X';
    cout << "TIC TAC TOE GAME" << endl;
    cout << "Player X vs Player O" << endl;
    cout << "Enter row and column numbers (0-2)" << endl;

    printGrid(grid);

    while (true)
    {
        playerMove(grid, currentPlayer);
        printGrid(grid);

        if (hasWon(grid, currentPlayer))
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isGridFull(grid))
        {
            cout << "The game is a draw." << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game over." << endl;
}

int main()
{
    playTicTacToe();
    return 0;
}
