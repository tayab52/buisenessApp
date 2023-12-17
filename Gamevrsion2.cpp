#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void printMaze();
void printPlayer();
void printPlayerRight();
void printPlayerLeft();
void printEnemy1();
void printEnemyDown2();
void printEnemyUp2();
void erasePlayer();
void eraseEnemy1();
void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();
void moveEnemy1(string direction);
void moveEnemy2(string direction2);
string changeDirection(string direction1);
string changeDirection2(string direction2);
void printFire();
void printFireLeft();
void printFireRight();
void moveFireRight();
void eraseFireRight();
void eraseFireLeft();
void moveFireLeft();
void moveFire();
void eraseFire();
void enemyFire1();
void enemyFire2();
void moveEnemy1Fire();
void moveEnemy2Fire();
void eraseEnemy1Fire();
void eraseEnemy2Fire();
bool checkenemyFire1();
bool checkenemyFire2();
bool checkFire();
void scorePBoard();
void scoreE1();
void E1board();
void printPboard();
void GameOver();
void Win();
void Loose();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int pX = 10, pY = 20;
int e1X = 1, e1Y = 1;
int e2X = 56, e2Y = 4;
int fX = pX + 3, fY = pY - 1;
int fLX = pX - 1, fLY = pY + 1;
int fRX = pX + 7, fRY = pY + 1;
int EfX = e1X + 3, EfY = e1Y + 3;
int E2fX = e2X - 1, E2fY = e2Y + 1;
int E1score = 5;
int Pscore = 9;

int main()
{

    system("cls");
    printMaze();
    E1board();
    printPboard();
    printEnemy1();
    printEnemyDown2();
    printPlayer();
    string direction1 = "right";
    string direction2 = "down";
    string fireDirection = "up";

    E1score = 5;
    Pscore = 9;

    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
            fireDirection = "left";
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
            fireDirection = "right";
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
            fireDirection = "up";
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
            fireDirection = "up";
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            if (fireDirection == "up")
            {
                fX = pX + 3;
                fY = pY - 1;
                printFire();
            }
            else if (fireDirection == "left")
            {
                fLX = pX - 1;
                fLY = pY + 1;
                printFireLeft();
            }
            else if (fireDirection == "right")
            {
                fRX = pX + 7;
                fRY = pY + 1;
                printFireRight();
            }
        }

        EfX = e1X + 3;
        E2fX = e2X - 1;
        EfY = e1Y + 3;
        E2fY = e2Y + 1;
        scoreE1();
        scorePBoard();
        moveFire();
        moveFireLeft();
        moveFireRight();
        moveEnemy1Fire();
        moveEnemy2Fire();
        moveEnemy1(direction1);
        moveEnemy2(direction2);
        direction1 = changeDirection(direction1);
        direction2 = changeDirection2(direction2);

        if (e1X % 2 == 0)
        {
            enemyFire1();
        }
        if (pX>=45 && direction2 =="down" && E2fY%3==0)
        {
            E2fX = e2X +2;
            E2fY = e2Y +3;
            enemyFire2();
        }

        if (E1score <= 0)
        {
            Win();
            break;
        }
        else if (Pscore <= 0)
        {
            Loose();

            break;
        }
    }

    GameOver();
}

void movePlayerLeft()
{
    if (getCharAtxy(pX - 1, pY) == ' ')
    {
        erasePlayer();
        pX = pX - 1;
        printPlayerLeft();
    }
}

void movePlayerRight()
{
    if (getCharAtxy(pX + 7, pY) == ' ')
    {
        erasePlayer();
        pX = pX + 1;
        printPlayerRight();
    }
}
void movePlayerUp()
{
    if (getCharAtxy(pX, pY - 1) == ' ')
    {
        erasePlayer();
        pY = pY - 1;
        printPlayer();
    }
}
void movePlayerDown()
{
    if (getCharAtxy(pX, pY + 3) == ' ')
    {
        erasePlayer();
        pY = pY + 1;
        printPlayer();
    }
}

void printMaze()
{

    cout << "################################################################" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "###          ########                                #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                            #########         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                    #         #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                                                              #" << endl;
    cout << "################################################################" << endl;
}

// void printPlayer()
// {
//     gotoxy(pX, pY);
//     cout << "   /\\   ";
//     gotoxy(pX, pY + 1);
//     cout << "|||  |||";
//     gotoxy(pX, pY + 2);
//     cout << "  \\/   ";
// }
void printPlayer()
{
    gotoxy(pX, pY);
    cout << "  ## / ";
    gotoxy(pX, pY + 1);
    cout << "O----  ";
    gotoxy(pX, pY + 2);
    cout << "  \\  \\";
}
void printPlayerRight()
{
    gotoxy(pX, pY);
    cout << " O     " << endl;
    gotoxy(pX, pY + 1);
    cout << "/|(]===" << endl;
    gotoxy(pX, pY + 2);
    cout << "/ \\   " << endl;
}
void printPlayerLeft()
{
    gotoxy(pX, pY);
    cout << "     O " << endl;
    gotoxy(pX, pY + 1);
    cout << "===[)|\\" << endl;
    gotoxy(pX, pY + 2);
    cout << "    / \\" << endl;
}
void erasePlayer()
{
    gotoxy(pX, pY);
    cout << "       ";
    gotoxy(pX, pY + 1);
    cout << "       ";
    gotoxy(pX, pY + 2);
    cout << "       ";
}
// void erasePlayer()
// {
//     gotoxy(pX, pY);
//     cout << "          ";
//     gotoxy(pX, pY + 1);
//     cout << "          ";
//     gotoxy(pX, pY + 2);
//     cout << "          ";
// }
void printEnemy1()
{
    gotoxy(e1X, e1Y);
    cout << "  /\\  ";
    gotoxy(e1X, e1Y + 1);
    cout << "||~~||";
    gotoxy(e1X, e1Y + 2);
    cout << "  \\/  ";
}
// void printEnemy2()
// {
//     gotoxy(e2X, e2Y);
//     cout << "  -----";
//     gotoxy(e2X, e2Y + 1);
//     cout << "~~~~~~~";
//     gotoxy(e2X, e2Y + 2);
//     cout << "  -----";
// }
void printEnemyDown2()
{
    gotoxy(e2X, e2Y);
    cout << "=====" << endl;
    gotoxy(e2X, e2Y + 1);
    cout << "\\~~~/" << endl;
    gotoxy(e2X, e2Y + 2);
    cout << " \\~/ " << endl;
}
void printEnemyUp2()
{
    gotoxy(e2X, e2Y);
    cout << " /~\\ " << endl;
    gotoxy(e2X, e2Y + 1);
    cout << "/~~~\\" << endl;
    gotoxy(e2X, e2Y + 2);
    cout << "=====" << endl;
}

// void printEnemy2()
// {
//     gotoxy(e2X, e2Y);
//     cout << "  -----";
//     gotoxy(e2X, e2Y + 1);
//     cout << "~~~~~~~";
//     gotoxy(e2X, e2Y + 2);
//     cout << "  -----";
// }
void eraseEnemy2()
{
    gotoxy(e2X, e2Y);
    cout << "      ";
    gotoxy(e2X, e2Y + 1);
    cout << "      ";
    gotoxy(e2X, e2Y + 2);
    cout << "      ";
}
void eraseEnemy1()
{
    gotoxy(e1X, e1Y);
    cout << "      ";
    gotoxy(e1X, e1Y + 1);
    cout << "      ";
    gotoxy(e1X, e1Y + 2);
    cout << "      ";
}
void moveEnemy1(string direction)
{

    eraseEnemy1();
    if (direction == "right")
    {
        e1X = e1X + 1;
    }

    else if (direction == "left")
    {
        e1X = e1X - 1;
    }
    printEnemy1();
}
void moveEnemy2(string direction2)
{

    eraseEnemy2();
    if (direction2 == "down")
    {
        e2Y = e2Y + 1;
        printEnemyDown2();
    }

    else if (direction2 == "up")
    {
        e2Y = e2Y - 1;
        printEnemyUp2();
    }
}
string changeDirection(string direction1)
{
    if (direction1 == "right" && e1X >= 40)
    {
        direction1 = "left";
    }
    else if (direction1 == "left" && e1X <= 2)
    {
        direction1 = "right";
    }
    return direction1;
}
string changeDirection2(string direction2)
{
    if (direction2 == "down" && e2Y >= 15)
    {
        direction2 = "up";
    }
    else if (direction2 == "up" && e2Y <= 3)
    {
        direction2 = "down";
    }
    return direction2;
}

// void moveEnemy3()
// {
//     while (true)
//     {
//         eX = 10;
//         printEnemy1();
//         Sleep(300);
//         eraseEnemy1();
//         eX = eX + 1;
//         if (eX == 80)
//         {
//             eX = 41;
//         }
//     }
// }
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)

{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
                                                                                            : ' ';
}
void printFire()
{
    if (getCharAtxy(fX, fY) == ' ')
    {
        gotoxy(fX, fY);
        cout << "^";
    }
}
void eraseFire()
{
    gotoxy(fX, fY);
    cout << " ";
}
void printFireLeft()
{
    if (getCharAtxy(fLX, fLY) == ' ')
    {
        gotoxy(fLX, fLY);
        cout << "<";
    }
}
void eraseFireLeft()
{

    gotoxy(fLX, fLY);
    cout << " ";
}
void eraseFireRight()
{

    gotoxy(fRX, fRY);
    cout << " ";
}
void printFireRight()
{
    if (getCharAtxy(fRX, fRY) == ' ')
    {
        gotoxy(fRX, fRY);
        cout << ">";
    }
}

void moveFire()
{
    for (int x = 0; x < 60; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            if (getCharAtxy(x, y) == '^')
            {
                fX = x;
                fY = y;
                eraseFire();
                if (checkFire())
                {

                    fY = fY - 1;
                    printFire();
                }
                else
                {
                    continue;
                }
            }
        }
    }
}
bool checkFire()

{
    if (getCharAtxy(fX, fY - 1) == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkenemyFire1()

{
    if (getCharAtxy(EfX, EfY + 1) == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkenemyFire2()

{
    if ((getCharAtxy(E2fX, E2fY + 1) == ' ')|| (getCharAtxy(E2fX, E2fY + 2) == ' '))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkFireLeft()

{
    if (getCharAtxy(fLX - 1, fLY) == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkFireRight()

{
    if (getCharAtxy(fRX + 1, fRY) == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enemyFire1()
{
    gotoxy(EfX, EfY);
    cout << "*";
}
void eraseEnemy1Fire()
{
    gotoxy(EfX, EfY);
    cout << " ";
}
void enemyFire2()
{
    gotoxy(E2fX, E2fY);
    cout << "!";
}
void eraseEnemy2Fire()
{
    gotoxy(E2fX, E2fY);
    cout << " ";
}
void moveEnemy1Fire()
{

    for (int x = 0; x < 60; x++)
    {
        for (int y = 24; y > 0; y--)
        {
            if (getCharAtxy(x, y) == '*')
            {
                EfX = x;
                EfY = y;
                eraseEnemy1Fire();
                if (checkenemyFire1())
                {

                    EfY = EfY + 1;
                    enemyFire1();
                }
                else
                {
                    continue;
                }
            }
        }
        if (!checkenemyFire1())
        {
            break;
        }
    }
}
void moveEnemy2Fire()
{

    for (int x = 50; x < 60; x++)
    {
        for (int y = 24; y > 0; y--)
        {
            if (getCharAtxy(x, y) == '!')
            {
                E2fX = x;
                E2fY = y;
                eraseEnemy2Fire();
                if (checkenemyFire2())
                {

                    E2fY = E2fY + 2;
                    enemyFire2();
                }
                else
                {
                    continue;
                }
            }
        }
        if (!checkenemyFire2())
        {
            break;
        }
    }
}
void moveFireLeft()
{

    for (int x = 0; x < 60; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            if (getCharAtxy(x, y) == '<')
            {
                fLX = x;
                fLY = y;
                eraseFireLeft();
                if (checkFireLeft())
                {

                    fLX = fLX - 1;
                    printFireLeft();
                }
                else
                {
                    continue;
                }
            }
        }
    }
}
void moveFireRight()
{

    for (int x = 63; x > 0; x--)
    {
        for (int y = 25; y > 0; y--)
        {
            if (getCharAtxy(x, y) == '>')
            {
                fRX = x;
                fRY = y;
                eraseFireRight();
                if (checkFireRight())
                {

                    fRX = fRX + 1;
                    printFireRight();
                }
                else
                {
                    continue;
                }
            }
        }
    }
}
void scoreE1()
{
    if (getCharAtxy(e1X, e1Y + 3) == '^' || getCharAtxy(e1X + 1, e1Y + 3) == '^' || getCharAtxy(e1X + 2, e1Y + 4) == '^' || getCharAtxy(e1X + 3, e1Y + 4) == '^' || getCharAtxy(e1X + 4, e1Y + 4) == '^' || getCharAtxy(e1X + 5, e1Y + 3) == '^' || getCharAtxy(e1X + 6, e1Y + 3) == '^')
    {
        E1score = E1score - 1;
    }
    gotoxy(67, 3);
    SetConsoleTextAttribute(h, 9);
    cout << E1score;
    SetConsoleTextAttribute(h, 7);
}
void scorePBoard()
{
    if (getCharAtxy(pX, pY - 1) == '*' || getCharAtxy(pX + 1, pY - 1) == '*' || getCharAtxy(pX + 2, pY-1) == '*' || getCharAtxy(pX + 3, pY - 1) == '*' || getCharAtxy(pX + 4, pY - 1) == '*' || getCharAtxy(pX + 5, pY - 1) == '*' || getCharAtxy(pX + 6, pY - 1) == '*')
    {
        Pscore = Pscore - 1;
    }
    else if (getCharAtxy(pX, pY ) == '!' || getCharAtxy(pX + 1, pY) == '!' || getCharAtxy(pX + 2, pY) == '!' || getCharAtxy(pX + 3, pY ) == '!' || getCharAtxy(pX + 4, pY ) == '!' || getCharAtxy(pX + 5, pY ) == '!' || getCharAtxy(pX + 6, pY) == '!')
    {
        Pscore = Pscore - 1;
    }
    else if (getCharAtxy(pX, pY - 1) == '!' || getCharAtxy(pX + 1, pY - 1) == '!' || getCharAtxy(pX + 2, pY-1) == '!' || getCharAtxy(pX + 3, pY - 1) == '!' || getCharAtxy(pX + 4, pY - 1) == '!' || getCharAtxy(pX + 5, pY - 1) == '!' || getCharAtxy(pX + 6, pY - 1) == '!')
    {
        Pscore = Pscore - 1;
    }
    gotoxy(67, 21);
    SetConsoleTextAttribute(h, 9);
    cout << Pscore;
    SetConsoleTextAttribute(h, 7);
}
void E1board()
{
    gotoxy(66, 2);
    cout << "@@@@@@@@@" << endl;
    gotoxy(66, 3);
    cout << "@       @" << endl;
    gotoxy(66, 4);
    cout << "@@@@@@@@@" << endl;
}
void printPboard()
{
    gotoxy(66, 20);
    cout << "@@@@@@@@@" << endl;
    gotoxy(66, 21);
    cout << "@       @" << endl;
    gotoxy(66, 22);
    cout << "@@@@@@@@@" << endl;
}
void GameOver()
{
    gotoxy(25, 12);
    SetConsoleTextAttribute(h, 4);
    cout << "G A M E  O V E R..";
    SetConsoleTextAttribute(h, 7);
}
void Win()
{
    gotoxy(25, 11);
    SetConsoleTextAttribute(h, 6);
    cout << "G A M E  W I N..";
    SetConsoleTextAttribute(h, 7);
}
void Loose()
{
    gotoxy(25, 11);
    SetConsoleTextAttribute(h, 4);
    cout << "G A M E  L O O S E..";
    SetConsoleTextAttribute(h, 7);
}
