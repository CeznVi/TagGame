//// ������� ������
#include <iostream>
#include <conio.h>

//C����� ��������
enum Move {
    Up = 72,
    Down = 80,
    Left = 75,
    Rigth = 77,
};

////���������� ��������� �������� � ������� ��������
int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;

}

////���������� ����� ��������� ����� ��� ����������
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

//// ������ ��� ����� ����
int whereIs0(const int* field, const int& SIZE)
{
    int nullid{};

    for (int i{}; i < SIZE; ++i)
        if (field[i] == 0)
            return i;

    return 0;
}

///// ��� ������ �������� ����
void showpole(const int* field, const int& SIZE)
{
    for (int i{}; i < SIZE; ++i)
        std::cout << field[i] << ' ';

    std::cout << '\n';
}

////������� ����������� �����
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

////������� ���
void doStep(int* field, const int& SIZE)
{
    int dir;
    std::cout << "Choise direction "; 
    std::cout << char(27) << ' ' << char(26) << ' ' << char(25) << ' ' << char(24) << '\n';
    
    //std::cin >> dir;
    dir = _getch();

    int id0 = whereIs0(field, SIZE);
 
    //�������� � ������ �� ���� ������  
    if (dir == Move::Down && id0 < 4)
        return;
    else if (dir == Move::Up && id0 > 11)
        return;
    else if (dir == Move::Left && (id0 == 3 || id0 == 7 || id0 == 11 || id0 == 15))
        return;
    else if (dir == Move::Rigth && (id0 == 0 || id0 == 4 || id0 == 8 || id0 == 12))
        return;

    //������� ���
    if (dir == Move::Up)
        move(field, SIZE, Move::Up);
    else if (dir == Move::Down)
        move(field, SIZE, Move::Down);
    else if (dir == Move::Left)
        move(field, SIZE, Move::Left);
    else if (dir == Move::Rigth)
        move(field, SIZE, Move::Rigth);
}
