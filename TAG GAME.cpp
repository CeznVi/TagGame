#include <iostream>
#include <Windows.h>

// продумать ходилку
// продумать изменение екрана путем его не полного, а лок обновления
// сделать проверку на выграш
// таблица аччивок на ТОП5 с сохранением на диске
// Запрос имени пользователя для топ 5
// сохранение игры при выходе спрашивать
// загрузка игры при старте спрашивать
// запилить заставку на старте 
//// распихать все по файлам чтобы небыло в одном все функции
////


enum Move {
    Up = 1,
    Down = 2,
    Left = 3,
    Rigth = 4,
};

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

//установка позиции 
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

////запихнуть в отедльный файл рисовалки
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
            if ((i>0 && i<6) && j == 5)
                std::cout << char(178);
            if (i == 2 && j == 4)
                std::cout << char(178);
            if (i == 3 && j == 3)
                std::cout << char(178);
        }
        std::cout <<  '\n';
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
            else if((i == 3 || i == 1 || i == 5) && (j > 2 && j < 6))
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
            else if (i==2 && j==3)
                std::cout << char(178);
            else if (i == 3 && j == 2)
                std::cout << char(178);
            else if ((i==1 || i==5) && j==7)
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
            else if((i == 1 || i == 5) && (j > 5 && j < 9))
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

//// что разрисовывать
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
            else if(j==0 || j==10)
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

//// Игровой движок
////
// 
// 
////Генерирует случайные значения в заданом дипазоне
int randInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
    
}

////возвращает масив рандомных чисел без повторений
int* genereteField(const int& SIZE)
{
    int* field = new int [SIZE] {};

    //srand(time(NULL));
    //rand();

    bool flag = false;
    int temp{};

    for (int i{}; i < SIZE - 1; )
    {
        flag = false;
        temp = randInt(0, 15);
       
        for (int j{}; j < SIZE; ++j)
        {
            if (field[j] == temp)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            field[i] = temp;
            i++;
        }
    }
   
    return field;
}

//// узнать где фишка нуля
int whereIs0(const int* field, const int& SIZE)
{
    int nullid{};

    for (int i{}; i < SIZE; ++i)
        if (field[i] == 0)
            return i;
    
    return 0;
}

///// для тестов показать поле
void showpole(const int* field, const int& SIZE)
{
    for (int i{}; i < SIZE; ++i)
        std::cout << field[i] << ' ';

    std::cout << '\n';
}

////функция перемещения фишек
void move(int* field, const int& SIZE, int dir)
{
    int id0 = whereIs0(field, SIZE);

    //////proverka  
    //if (dir == Move::Down && id0 < 4)
    //    return;
    //else if (dir == Move::Up && id0 > 11)
    //    return;
    //else if (dir == Move::Left && (id0 == 3 || id0 == 7 || id0 == 11 || id0 == 15))
    //    return;
    //else if (dir == Move::Rigth && (id0 == 0 || id0 == 4 || id0 == 8 || id0 == 12))
    //    return;
    
    int* tempArr = new int [SIZE] {};

    for (int i{}; i < SIZE; ++i)
        tempArr[i] = field[i];

    delete[] field;

    field = new int[SIZE];
    
    if (dir == Move::Down)
    {
        for (int i{}; i < SIZE; ++i)
        {
            if (i == id0)
                field[i] = tempArr[i - 4];
            else if (i == id0 - 4)
                field[i] = 0;
            else
                field[i] = tempArr[i];
        }
    }
    else if (dir == Move::Up)
    {
        for (int i{}; i < SIZE; ++i)
        {
            if (i == id0)
                field[i] = tempArr[i + 4];
            else if (i == id0 + 4)
                field[i] = 0;
            else
                field[i] = tempArr[i];
        }
    }
    else if (dir == Move::Left)
    {
        for (int i{}; i < SIZE; ++i)
        {
            if (i == id0)
                field[i] = tempArr[i + 1];
            else if (i == id0 + 1)
                field[i] = 0;
            else
                field[i] = tempArr[i];
        }
    }
    else if (dir == Move::Rigth)
    {
        for (int i{}; i < SIZE; ++i)
        {
            if (i == id0)
                field[i] = tempArr[i - 1];
            else if (i == id0 - 1)
                field[i] = 0;
            else
                field[i] = tempArr[i];
        }
    }

    delete[] tempArr;
    
}

////сделать шаг
void doStep(int* field, const int& SIZE)
{
    int dir;
    std::cout << "Enter direction\n";
    std::cin >> dir;

    int id0 = whereIs0(field, SIZE);

    ////proverka  
    if (dir == Move::Down && id0 < 4)
        return;
    else if (dir == Move::Up && id0 > 11)
        return;
    else if (dir == Move::Left && (id0 == 3 || id0 == 7 || id0 == 11 || id0 == 15))
        return;
    else if (dir == Move::Rigth && (id0 == 0 || id0 == 4 || id0 == 8 || id0 == 12))
        return;



    if(dir == Move::Up)
        move(field, SIZE, Move::Up);
    else if (dir == Move::Down)
        move(field, SIZE, Move::Down);
    else if (dir == Move::Left)
        move(field, SIZE, Move::Left);
    if (dir == Move::Rigth)
        move(field, SIZE, Move::Rigth);


}

////игра
void game(int* field, const int& SIZE)
{
    while (true)
    {
        
        drawGameField(field, SIZE);
        
        doStep(field, SIZE);
        system("cls");
        
        drawGameField(field, SIZE);
    }

}

int main()
{
    const int SIZE = 16;

    ////тест
   // int* field = new int[SIZE]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    

    //// рабочий вариант
    int* field = genereteField(SIZE);

    game(field, SIZE);

    //drawGameField(field, SIZE);
    //showpole(field, SIZE);
    //system("pause");
    //system("cls");
    

    //move(field, SIZE, Move::Down);
    //drawGameField(field, SIZE);
    //showpole(field, SIZE);


    //move(field, SIZE, Move::Up);
    //system("pause");
    //system("cls");
    //drawGameField(field, SIZE);
    //showpole(field, SIZE);

    //move(field, SIZE, Move::Left);
    //system("pause");
    //system("cls");
    //drawGameField(field, SIZE);
    //showpole(field, SIZE);

    //move(field, SIZE, Move::Rigth);
    //system("pause");
    //system("cls");
    //drawGameField(field, SIZE);
    //showpole(field, SIZE);

	return 0;
}