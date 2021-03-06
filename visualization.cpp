#include <Windows.h>
#include <iostream>

//?????? ??????
enum ConsoleColor
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    Lightblue, LightGreen, Lightcyan, LightRed, LightMagenta, Yellow, White
};

//????????? ?????
void setColor(int text, int background = ConsoleColor::Black)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//????????? ????????? ?? ???????????
void setPos(short X, short Y)
{
    HANDLE  hConsole = nullptr;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

//??????? ?????????
void showMessage(std::string message, ConsoleColor color = ConsoleColor::White)
{
    setColor(color, ConsoleColor::Black);

    std::cout << message;

    setColor(ConsoleColor::White, ConsoleColor::Black);
}

////???????? ????????? ? ? ??????????? ?? ????
int convIdtoY(int id)
{
    //0+1
    //6+1
    //12+1
    //18+1

    if (id == 0 || id == 1 || id == 2 || id == 3)
        return 1;
    if (id == 4 || id == 5 || id == 6 || id == 7)
        return 7;
    if (id == 8 || id == 9 || id == 10 || id == 11)
        return 13;
    if (id == 12 || id == 13 || id == 14 || id == 15)
        return 19;
    else
        return 0;
}

////???????? ????????? ? ? ??????????? ?? ????
int convIdtoX(int id)
{
    /// 0 + 30
    //10 + 30
    //20 + 30
    //30 + 30

    if (id == 0 || id == 4 || id == 8 || id == 12)
        return 30;
    else if (id == 1 || id == 5 || id == 9 || id == 13)
        return 40;
    else if (id == 2 || id == 6 || id == 10 || id == 14)
        return 50;
    else if (id == 3 || id == 7 || id == 11 || id == 15)
        return 60;
    else
        return 0;

}

//// ?????? ????? ?? ??????? ????? (1 - 15)
void draw1(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && j == 5)
                std::cout << char(178);
            if (i == 2 && j == 4)
                std::cout << char(178);
            if (i == 3 && j == 3)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw2(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if (i == 2 && j == 5)
                std::cout << char(178);
            else if (i == 3 && j == 4)
                std::cout << char(178);
            else if (i == 4 && j == 3)
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw3(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if ((i == 2 || i == 4) && j == 5)
                std::cout << char(178);
            else if (i == 3 && j == 4)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw4(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && j == 5)
                std::cout << char(178);
            else if ((i > 0 && i < 3) && j == 3)
                std::cout << char(178);
            else if (i == 3 && (j > 2 && j < 5))
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw5(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 3) && j == 3)
                std::cout << char(178);
            else if ((i == 3 || i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if (i == 4 && j == 5)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw6(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 3) && j == 3)
                std::cout << char(178);
            else if ((i == 3 || i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if (i == 4 && (j == 5 || j == 3))
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw7(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && j == 5)
                std::cout << char(178);
            else if (i == 1 && (j > 2 && j < 6))
                std::cout << char(178);


        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw8(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 3) && j == 3)
                std::cout << char(178);
            else if ((i == 3 || i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if (i == 4 && (j == 5 || j == 3))
                std::cout << char(178);
            else if (i == 2 && j == 5)
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw9(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 3) && j == 3)
                std::cout << char(178);
            else if ((i == 3 || i == 1 || i == 5) && (j > 2 && j < 6))
                std::cout << char(178);
            else if (i == 4 && (j == 5))
                std::cout << char(178);
            else if (i == 2 && j == 5)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);

}

void draw10(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4 || j == 6 || j == 8))
                std::cout << char(178);
            else if (i == 2 && j == 3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);
            else if ((i == 1 || i == 5) && j == 7)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw11(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4 || j == 8))
                std::cout << char(178);
            else if (i == 2 && (j == 3 || j == 7))
                std::cout << char(178);
            else if (i == 3 && (j == 2 || j == 6))
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw12(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4))
                std::cout << char(178);
            else if (i == 2 && j == 3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);
            else if ((i == 1 || i == 5) && (j > 5 && j < 9))
                std::cout << char(178);
            else if (i == 2 && j == 8)
                std::cout << char(178);
            else if (i == 3 && j == 7)
                std::cout << char(178);
            else if (i == 4 && j == 6)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw13(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4))
                std::cout << char(178);
            else if (i == 2 && j == 3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);
            else if ((i == 1 || i == 5) && (j > 5 && j < 9))
                std::cout << char(178);
            else if ((i == 2 || i == 4) && j == 8)
                std::cout << char(178);
            else if (i == 3 && j == 7)
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw14(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4))
                std::cout << char(178);
            else if (i == 2 && j == 3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);

            else if ((i > 0 && i < 6) && j == 8)
                std::cout << char(178);
            else if ((i > 0 && i < 3) && j == 6)
                std::cout << char(178);
            else if (i == 3 && (j > 5 && j < 9))
                std::cout << char(178);

        }
        std::cout << '\n';
    }
    setColor(White);
}

void draw15(int id)
{
    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Brown);
    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);
            if ((i > 0 && i < 6) && (j == 4))
                std::cout << char(178);
            else if (i == 2 && j == 3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);
            else if ((i > 0 && i < 3) && j == 6)
                std::cout << char(178);
            else if ((i == 3 || i == 1 || i == 5) && (j > 5 && j < 9))
                std::cout << char(178);
            else if (i == 4 && j == 8)
                std::cout << char(178);
        }
        std::cout << '\n';
    }
    setColor(White);
}

//// ????? ????? ????????
void whichNumDraw(const int& id, const int& num)
{

    if (num == 1)
        draw1(id);
    else if (num == 2)
        draw2(id);
    else if (num == 3)
        draw3(id);
    else if (num == 4)
        draw4(id);
    else if (num == 5)
        draw5(id);
    else if (num == 6)
        draw6(id);
    else if (num == 7)
        draw7(id);
    else if (num == 8)
        draw8(id);
    else if (num == 9)
        draw9(id);
    else if (num == 10)
        draw10(id);
    else if (num == 11)
        draw11(id);
    else if (num == 12)
        draw12(id);
    else if (num == 13)
        draw13(id);
    else if (num == 14)
        draw14(id);
    else if (num == 15)
        draw15(id);

}

//// ????????? ?????
void drawField(const int& id)
{

    int x = convIdtoX(id);
    int y = convIdtoY(id);

    //setColor(Blue);
    setColor(White);

    for (int i{}; i < 7; ++i)
    {
        for (int j{}; j < 11; ++j)
        {
            setPos(x + j, y + i);

            if (i == 0 || i == 6)
                std::cout << char(178);
            else if (j == 0 || j == 10)
                std::cout << char(178);
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }

    setColor(White);
}

////????????? ???????? ?????
void showMovCount(const int& movCount)
{
    setPos(75, 7);
    showMessage("Count move ", Blue);
        std::cout << movCount << '\n';
}

////?????????? ?????? ??????????
void showGameKey()
{
    setPos(75, 8);
    showMessage("Game key:\n", Red);
    setPos(75, 9);
    showMessage("Use arrow keys to move tiles\n", Blue);
    setPos(75, 10);
    showMessage("Use ESC for exit without saving\n", Blue);
    setPos(75, 11);
    showMessage("Use SPACE for save\n", Blue);
}

////?????????? ???????
void showTitle()
{
    setPos(46, 0);
    showMessage("15 GAME", Brown);
}

////????????? ???????
void showTimer(int min, int sec)
{
    setPos(75, 6);
    showMessage("Timer: ", Blue);
    std::cout << min;
    showMessage(" min ", Blue);
    std::cout << sec;
    showMessage(" sec", Blue);
}

void showbackground()
{
    setPos(0, 0);
    setColor(Blue);
    for(int i{}; i < 60; ++i)
        std::cout << std::string(120, char(178));

    setColor(White);
}

//// ????????? ????? ????
void drawGameField(const int* field,const int& SIZE, const int& movCount, int* lastTurn, int& min, int& sec)
{
    showTitle();
    showMovCount(movCount);
    showTimer(min, sec);
    showGameKey();

    for (int i{}; i < SIZE; ++i)
    {
        if (movCount == 0)
        {
            drawField(i);
            whichNumDraw(i, field[i]);
        }
        else if ((movCount > 0) || (lastTurn[i] != field[i]))
        {
            drawField(i);
            whichNumDraw(i, field[i]);
        }
        else
            drawField(i);
    }


    setPos(0, 26);
}

///????????? ??????? (??? ?????? ???? ? ?????)
void drawRectangle(int& x, int& y)
{
    for (int i{}; i < 13; ++i)
    {
        for (int j{}; j < 41; ++j)
        {
            setPos(x + j, y + i);
            setColor(Brown);
            if (i == 0 || i == 12)
                std::cout << char(178);
            else if (i >= 0 && j == 0)
                std::cout << char(178);
            else if (i >= 0 && j == 40)
                std::cout << char(178);
            else
            {
                setColor(Green);
                std::cout << char(178);
            }
                
            
        }
        std::cout << '\n';
    }
    setColor(White);
}

////?????????? ???????? ????? ????
void drawGameOver()
{
    int x = convIdtoX(4);
    int y = convIdtoY(4);
    drawRectangle(x, y);
    setColor(Red);

    for (int i{}; i < 13; ++i)
    {
        for (int j{}; j < 41; ++j)
        {
            setPos(x + j, y + i);
            //G
            if((i == 1 || i==5) && (j>8 && j < 14))
                std::cout << char(178);
            else if(j==9 && (i>1 && i<6))
                std::cout << char(178);
            else if (i == 3 && (j > 11 && j < 14))
                std::cout << char(178);
            else if (i == 4 && j==13)
                std::cout << char(178);
            //A
            else if (i == 1 && j == 17)
                std::cout << char(178);
            else if (i == 2 && (j == 16 || j == 18))
                std::cout << char(178);
            else if ((i > 2 && i < 6) && (j == 15 || j == 19))
                std::cout << char(178);
            else if (i == 4 && (j > 15 && j < 19))
                std::cout << char(178);
            //M
            else if ((i > 0 && i < 6) && (j == 21 || j == 25))
                std::cout << char(178);
            else if (i ==2 && (j == 22 || j == 24))
                std::cout << char(178);
            else if (i == 3 && j == 23)
                std::cout << char(178);
            //E
            else if ((i > 0 && i < 6) && j == 27)
                std::cout << char(178);
            else if (( i == 1 || i == 3 || i ==5) && (j>27 && j<31))
                std::cout << char(178);
            //O
            else if ((i == 7 || i == 11) && (j > 8 && j < 13))
                std::cout << char(178);
            else if ((i > 6 && i < 12) && (j==9 || j == 12 ))
                std::cout << char(178);
            //V
            else if((i>6 && i <10) && (j ==14 || j==18))
                std::cout << char(178);
            else if(i==10 && (j==15 || j==17))
                std::cout << char(178);
            else if(i==11 && j == 16)
                std::cout << char(178);
            //E
            else if ((i > 6 && i < 12) && j == 20)
                std::cout << char(178);
            else if ((i == 7 || i == 9 || i == 11) && (j > 19 && j < 24))
                std::cout << char(178);
            //R
            else if ((i > 6 && i < 12) && (j == 26))
                std::cout << char(178);
            else if ((i==7 || i==9) && (j>26 && j<30))
                std::cout << char(178);
            else if ((j==29) && (i == 8 || i == 11))
                std::cout << char(178);
            else if ((i == 10) && j == 28)
                std::cout << char(178);
        }
        std::cout << '\n';
    }

    setColor(Blue);
    setPos(75, 8);
    std::cout << std::string(30, char(178));
    setPos(75, 9);
    std::cout << std::string(30, char(178));
    setPos(75, 10);
    std::cout << std::string(31, char(178));
    setPos(75, 11);
    std::cout << std::string(31, char(178));


    setColor(White);
    setPos(0, 26);
}

void drawWelcome()
{
    int x = convIdtoX(4);
    int y = convIdtoY(4);
    drawRectangle(x, y);
    setColor(Red);

    for (int i{}; i < 13; ++i)
    {
        for (int j{}; j < 41; ++j)
        {
            setPos(x + j, y + i);
            //G
            if ((i == 1 || i == 5) && (j > 8 && j < 14))
                std::cout << char(178);
            else if (j == 9 && (i > 1 && i < 6))
                std::cout << char(178);
            else if (i == 3 && (j > 11 && j < 14))
                std::cout << char(178);
            else if (i == 4 && j == 13)
                std::cout << char(178);
            //A
            else if (i == 1 && j == 17)
                std::cout << char(178);
            else if (i == 2 && (j == 16 || j == 18))
                std::cout << char(178);
            else if ((i > 2 && i < 6) && (j == 15 || j == 19))
                std::cout << char(178);
            else if (i == 4 && (j > 15 && j < 19))
                std::cout << char(178);
            //M
            else if ((i > 0 && i < 6) && (j == 21 || j == 25))
                std::cout << char(178);
            else if (i == 2 && (j == 22 || j == 24))
                std::cout << char(178);
            else if (i == 3 && j == 23)
                std::cout << char(178);
            //E
            else if ((i > 0 && i < 6) && j == 27)
                std::cout << char(178);
            else if ((i == 1 || i == 3 || i == 5) && (j > 27 && j < 31))
                std::cout << char(178);
            //15
            if ((i > 6 && i < 12) && (j == 18))
                std::cout << char(178);
            else if (i == 8 && j == 17)
                std::cout << char(178);
            else if (i == 9 && j == 16)
                std::cout << char(178);
            else if ((i > 6 && i < 10) && j == 20)
                std::cout << char(178);
            else if ((i == 7 || i == 9 || i == 11) && (j > 19 && j < 23))
                std::cout << char(178);
            else if (i == 10 && j == 22)
                std::cout << char(178);

        }
        std::cout << '\n';
    }

     setColor(White);
    setPos(0, 26);
}

void drawHiscreen()
{
    showbackground();
    drawWelcome();

    setPos(75, 8);
    showMessage("Game key:\n", Red);
    setPos(75, 9);
    showMessage("Use any key for start new game\n", Brown);
    setPos(75, 10);
    showMessage("Use SPACE for load last saving game\n", Brown);
    setPos(75, 11);
    showMessage("Use TAB for view leaderbords\n", Brown);
    setPos(75, 12);
    showMessage("Use ESC for exit\n", Brown);

    setPos(31, 35);
    showMessage("Game autor: Velychko Viktor from SBU111", Yellow);


}

void drawSaveMessage()
{ 
    int x = convIdtoX(4);
    int y = convIdtoY(4);
    drawRectangle(x, y);
    setColor(Red);

    for (int i{}; i < 13; ++i)
    {
        for (int j{}; j < 41; ++j)
        {
            setPos(x + j, y + i);
            //G
            if ((i == 1 || i == 5) && (j > 8 && j < 14))
                std::cout << char(178);
            else if (j == 9 && (i > 1 && i < 6))
                std::cout << char(178);
            else if (i == 3 && (j > 11 && j < 14))
                std::cout << char(178);
            else if (i == 4 && j == 13)
                std::cout << char(178);
            //A
            else if (i == 1 && j == 17)
                std::cout << char(178);
            else if (i == 2 && (j == 16 || j == 18))
                std::cout << char(178);
            else if ((i > 2 && i < 6) && (j == 15 || j == 19))
                std::cout << char(178);
            else if (i == 4 && (j > 15 && j < 19))
                std::cout << char(178);
            //M
            else if ((i > 0 && i < 6) && (j == 21 || j == 25))
                std::cout << char(178);
            else if (i == 2 && (j == 22 || j == 24))
                std::cout << char(178);
            else if (i == 3 && j == 23)
                std::cout << char(178);
            //E
            else if ((i > 0 && i < 6) && j == 27)
                std::cout << char(178);
            else if ((i == 1 || i == 3 || i == 5) && (j > 27 && j < 31))
                std::cout << char(178);
            //S
            else if ((i == 7 || i == 11 || i == 9) && (j > 8 && j < 13))
                std::cout << char(178);
            else if ((i > 6 && i < 10) && (j == 9))
                std::cout << char(178);
            else if ((i > 8 && i < 12) && (j == 12))
                std::cout << char(178);
            //A
            else if (i == 7 && j == 16)
                std::cout << char(178);
            else if (i == 8 && (j == 15 || j == 17))
                std::cout << char(178);
            else if ((i > 8 && i < 12) && (j == 14 || j == 18))
                std::cout << char(178);
            else if (i == 10 && (j > 14 && j < 18))
                std::cout << char(178);        
            //V
            else if ((i > 6 && i < 10) && (j == 20 || j == 24))
                std::cout << char(178);
            else if (i == 10 && (j == 21 || j == 23))
                std::cout << char(178);
            else if (i == 11 && j == 22)
                std::cout << char(178);
            //E
            else if ((i > 6 && i < 12) && j == 26)
                std::cout << char(178);
            else if ((i == 7 || i == 9 || i == 11) && (j > 26 && j < 30))
                std::cout << char(178);

        }
        std::cout << '\n';
    }

    Sleep(500);
    setColor(White);
    setPos(0, 26);
}

void drawleadtable()
{
    setPos(0, 0);
    showbackground();
    int x = convIdtoX(1);
    int y = convIdtoY(1);
    drawRectangle(x, y);
    setColor(White);
    setPos(53, 2);
    showMessage("Hight score table\n", Brown);
    setPos(41, 3);
    showMessage("\Minutes\tSecund\tMove count\n", Brown);

    
}
