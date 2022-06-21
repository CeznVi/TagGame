//// Игровой движок
#include <iostream>
 
 
//Cписок движения
enum Move {
    Up = 1,
    Down = 2,
    Left = 3,
    Rigth = 4,
};

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

    ////Проверка и защита от лома масива  
    if (dir == Move::Down && id0 < 4)
        return;
    else if (dir == Move::Up && id0 > 11)
        return;
    else if (dir == Move::Left && (id0 == 3 || id0 == 7 || id0 == 11 || id0 == 15))
        return;
    else if (dir == Move::Rigth && (id0 == 0 || id0 == 4 || id0 == 8 || id0 == 12))
        return;

    if (dir == Move::Up)
        move(field, SIZE, Move::Up);
    else if (dir == Move::Down)
        move(field, SIZE, Move::Down);
    else if (dir == Move::Left)
        move(field, SIZE, Move::Left);
    if (dir == Move::Rigth)
        move(field, SIZE, Move::Rigth);
}
