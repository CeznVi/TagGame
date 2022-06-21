#include <Windows.h>
#include <iostream>

//список цветов
enum ConsoleColor
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    Lightblue, LightGreen, Lightcyan, LightRed, LightMagenta, Yellow, White
};

//установка цвета
void setColor(int text, int background = ConsoleColor::Black)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//установка указателя по координатам
void setPos(short X, short Y)
{
    HANDLE  hConsole = nullptr;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

//вывести сообщение
void showMessage(std::string message, ConsoleColor color = ConsoleColor::White)
{
    setColor(color, ConsoleColor::Black);

    std::cout << message;

    setColor(ConsoleColor::White, ConsoleColor::Black);
}

////подгонка координат У в зависимости от айди
int convIdtoY(int id)
{
    if (id == 0 || id == 1 || id == 2 || id == 3)
        return 0;
    if (id == 4 || id == 5 || id == 6 || id == 7)
        return 6;
    if (id == 8 || id == 9 || id == 10 || id == 11)
        return 12;
    if (id == 12 || id == 13 || id == 14 || id == 15)
        return 18;
    else
        return 0;
}

////подгонка координат Х в зависимости от айди
int convIdtoX(int id)
{
    if (id == 0 || id == 4 || id == 8 || id == 12)
        return 0;
    if (id == 1 || id == 5 || id == 9 || id == 13)
        return 10;
    if (id == 2 || id == 6 || id == 10 || id == 14)
        return 20;
    if (id == 3 || id == 7 || id == 11 || id == 15)
        return 30;
    else
        return 0;
}

//// рисуем цифры на рубашке фишек (1 - 15)
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

//// какую цифру выводить
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
    else
        return;
}

//// отрисовка рамки
void drawField(const int& id)
{

    int x = convIdtoX(id);
    int y = convIdtoY(id);

    setColor(Blue);

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

//// отрисовка всего поля
void drawGameField(const int* field, const int& SIZE)
{
    //отрисовка поля
    for (int i{}; i <= SIZE; ++i)
        drawField(i);

    for (int i{}; i <= SIZE; ++i)
        whichNumDraw(i, field[i]);

    setPos(0, 25);
}
