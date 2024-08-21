#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

class Game2048
{
private:
    int board[4][4];
    int tempBoard[4][4];
    int score;

    void copyBoard(int src[4][4], int dest[4][4])
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                dest[i][j] = src[i][j];
    }

    bool isEqual(int a[4][4], int b[4][4])
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }

    bool isGameOver()
    {
        // check if any free cell is available
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }

        // if all cell filled -> check if any two adjacent value have similar value
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1])
                {
                    return false;
                }
            }
        }

        return true;
    }

    void addBlock()
    {
        int li, ri;
        srand(time(0));
        while (true)
        {
            li = rand() % 4;
            ri = rand() % 4;
            if (board[li][ri] == 0)
            {
                board[li][ri] = (rand() % 2 + 1) * 2;
                break;
            }
        }
    }

    void displayBoard()
    {
        // Clear terminal
        system("cls"); // Use "clear" on Unix-based systems

        cout << "\n\t\tPress Esc anytime to quit the game";
        cout << "\n\n\n\n";
        cout << "\t\t\t\tScore: " << score << endl;
        for (int i = 0; i < 4; ++i)
        {
            cout << "\t\t\t\t-----------------\n\t\t\t\t";
            for (int j = 0; j < 4; ++j)
            {
                if (board[i][j] == 0)
                    cout << "|   ";
                else
                    cout << "| " << board[i][j] << " ";
            }
            cout << "|\n";
        }
        cout << "\t\t\t\t-----------------\n";
    }

    void moveUp()
    {
        for (int j = 0; j < 4; ++j)
        {
            int li = 0, ri = j;
            for (int i = 1; i < 4; ++i)
            {
                if (board[i][j] != 0)
                {
                    if (board[i - 1][j] == 0 || board[i - 1][j] == board[i][j])
                    {
                        if (board[li][ri] == board[i][j])
                        {
                            score += board[li][ri] * 2;
                            board[li][ri] *= 2;
                            board[i][j] = 0;
                        }
                        else
                        {
                            if (board[li][ri] == 0)
                            {
                                board[li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                            else
                            {
                                board[++li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                    }
                    else
                        li++;
                }
            }
        }
    }

    void moveDown()
    {
        for (int j = 0; j < 4; ++j)
        {
            int li = 3, ri = j;
            for (int i = 2; i >= 0; --i)
            {
                if (board[i][j] != 0)
                {
                    if (board[i + 1][j] == 0 || board[i + 1][j] == board[i][j])
                    {
                        if (board[li][ri] == board[i][j])
                        {
                            score += board[li][ri] * 2;
                            board[li][ri] *= 2;
                            board[i][j] = 0;
                        }
                        else
                        {
                            if (board[li][ri] == 0)
                            {
                                board[li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                            else
                            {
                                board[--li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                    }
                    else
                        li--;
                }
            }
        }
    }

    void moveLeft()
    {
        for (int i = 0; i < 4; ++i)
        {
            int li = i, ri = 0;
            for (int j = 1; j < 4; ++j)
            {
                if (board[i][j] != 0)
                {
                    if (board[i][j - 1] == 0 || board[i][j - 1] == board[i][j])
                    {
                        if (board[li][ri] == board[i][j])
                        {
                            score += board[li][ri] * 2;
                            board[li][ri] *= 2;
                            board[i][j] = 0;
                        }
                        else
                        {
                            if (board[li][ri] == 0)
                            {
                                board[li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                            else
                            {
                                board[li][++ri] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                    }
                    else
                        ri++;
                }
            }
        }
    }

    void moveRight()
    {
        for (int i = 0; i < 4; ++i)
        {
            int li = i, ri = 3;
            for (int j = 2; j >= 0; --j)
            {
                if (board[i][j] != 0)
                {
                    if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j])
                    {
                        if (board[li][ri] == board[i][j])
                        {
                            score += board[li][ri] * 2;
                            board[li][ri] *= 2;
                            board[i][j] = 0;
                        }
                        else
                        {
                            if (board[li][ri] == 0)
                            {
                                board[li][ri] = board[i][j];
                                board[i][j] = 0;
                            }
                            else
                            {
                                board[li][--ri] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                    }
                    else
                        ri--;
                }
            }
        }
    }

public:
    Game2048() : score(0)
    {
        memset(board, 0, sizeof(board));
        srand(time(0));
        int i1 = rand() % 4;
        int i2 = rand() % 4;
        while (true)
        {
            int i3 = rand() % 4;
            int i4 = rand() % 4;
            if (i3 != i1 || i4 != i2)
            {
                board[i1][i2] = 2;
                board[i3][i4] = 4;
                break;
            }
        }
    }

    void play()
    {
        displayBoard();
        while (true)
        {
            copyBoard(board, tempBoard);
            int ch = getch();
            if (ch == 72)
                moveUp();
            else if (ch == 80)
                moveDown();
            else if (ch == 75)
                moveLeft();
            else if (ch == 77)
                moveRight();
            else if (ch == 27)
                break;

            if (!isEqual(tempBoard, board))
                addBlock();

            displayBoard();
            if (isGameOver())
            {
                cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
                getch();
                break;
            }
        }
    }
};

int main()
{
    cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
    getch();
    system("cls"); // Use "clear" on Unix-based systems
    Game2048 game;
    game.play();
    return 0;
}
