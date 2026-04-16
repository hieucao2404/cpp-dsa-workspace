/**
 *  Programs that deal with such positional games need a way of representing objects in a two-dimensional space. A natural way to this is with two-dimensional array, where we use two indices, say i and j, to refer to the cell in the lib.
 * The first index usually refers to a row number and the second refers to the column number
 *
 * DYNAMIC ALLOCATON OF MATRICES
 * If the dimension of a two-d array are now known in advance, it is necessary to allocate the array dinamically. This is be done by applyy the method that we discussed earlier for allocating arrays
 */

#include <cstdlib>  //System definistions
#include <iostream> // I/O definitions
using namespace std;

const int X = 1, O = -1, EMPTY = 0;

int board[3][3];
int currentPlayer;

void clearBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    currentPlayer = X; // Player X starts
}

void putMark(int i, int j)
{                                   // mark row i column j
    board[i][j] = currentPlayer;    // mark with current player
    currentPlayer = -currentPlayer; // switch players
}

bool isWin(int mark)
{
    int win = 3 * mark;
    return ((board[0][0] + board[0][1] + board[0][2] == win)
            // row 0
            || (board[1][0] + board[1][1] + board[1][2] == win)
            // row 1
            || (board[2][0] + board[2][1] + board[2][2] == win)
            // row 2
            || (board[0][0] + board[1][0] + board[2][0] == win)
            // column 0
            || (board[0][1] + board[1][1] + board[2][1] == win)
            // column 1
            || (board[0][2] + board[1][2] + board[2][2] == win)
            // column 2
            || (board[0][0] + board[1][1] + board[2][2] == win)
            // diagonal
            || (board[2][0] + board[1][1] + board[0][2] == win));
    // diagonal
}

int getWinner()
{
    if (isWin(X))
        return X;
    else if (isWin(O))
        return O;
    else
        return EMPTY;
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case EMPTY:
                cout << " ";
                break;
            }
            if (j < 2)
                cout << "|";
        }
        if (i < 2)
            cout << "\n-+-+-\n";
    }
}

int main()
{
    clearBoard();
    putMark(0, 0);
    putMark(1, 1);
    // add the marks
    putMark(0, 1);
    putMark(0, 2);
    putMark(2, 0);
    putMark(1, 2);
    putMark(2, 2);
    putMark(2, 1);
    putMark(1, 0);
    printBoard();
    int winner = getWinner();
    if(winner != EMPTY){
        cout << " " << (winner == X ? 'X' : 'O') << " wins " << endl;
    }
    else {
        cout << " Tie " << endl;
    }
    return EXIT_SUCCESS;
}
