//// ������� ������
#include <iostream>
#include <conio.h>
#include <fstream>


//// ����� ������� �� ������������.���
void drawGameField(const int* field, const int& SIZE, const int& movCount, int* lastTurn);
void showbackground();
void drawGameOver();
void drawHiscreen();
void setPos(short X, short Y);

//C����� ��������
enum Move {
    Up = 72,
    Down = 80,
    Left = 75,
    Rigth = 77,
    Space = 32,
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

////������� �������� ����������
void loadSave()
{

}

////������� ������� ���������� �������� ��������
void saveGame(const int* field, const int& SIZE)
{
    std::ofstream fout;

    fout.open("saved_game.txt");
    if (!fout)
    {
        std::cerr << "Error open file...";
        exit(1);
    }

    for (int i{}; i < SIZE; ++i)
        fout << field[i] << ' ';

    fout.close();
}

//// ������� ����� ����
void copyField(const int* field, int* copyField, const int& SIZE)
{
    for (int i{}; i < SIZE; ++i)
        copyField[i] = field[i];
}

////������� ����������� �����
void move(int* field, const int& SIZE, int dir)
{
    int id0 = whereIs0(field, SIZE);

    int* tempArr = new int [SIZE] {};

    copyField(field, tempArr, SIZE);

    ////������� �����*
    //delete[] field;
    //field = new int[SIZE];

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
void doStep(int* field, const int& SIZE, int& movCount, int* lastTurn, bool& play)
{
    int dir;

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
    {
        move(field, SIZE, Move::Up);
        movCount++;
    }
    else if (dir == Move::Down)
    {
        move(field, SIZE, Move::Down);
        movCount++;
    }
    else if (dir == Move::Left)
    {
        move(field, SIZE, Move::Left);
        movCount++;
    }
    else if (dir == Move::Rigth)
    {
        move(field, SIZE, Move::Rigth);
        movCount++;
    }
    else if (dir == Move::Space)
    {
        saveGame(field, SIZE);
        play = true;
    }


    copyField(field, lastTurn, SIZE);
}

////��������� ������ ����� ��� ���
bool isWin(const int* field, const int* wcom,const int& SIZE)
{
    int count{};

    for (int i{}; i < SIZE; ++i)
        if (field[i] == wcom[i])
            count++;

    if (count == SIZE)
        return true;
    else
        return false;
}

////�-��� ���� (����)
void game()
{
    const int SIZE = 16;

    //// ��������� ���������� ����
    //int* field = genereteField(SIZE);
    
    //////����
    int* field = new int[SIZE] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15};

    //// �������� ����������
    const int* wcom = new int[SIZE] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    ////������� �����
    int movCount{};

    ////�������� �������� ���� �� ���� (��� ���������� ��������� ��������� ���. ����) 
    int* lastTurn = new int[SIZE] {};

    bool play = false;
    showbackground();

    drawGameField(field, SIZE, movCount, lastTurn);

    while (!play)
    {
        doStep(field, SIZE, movCount, lastTurn, play);
        drawGameField(field, SIZE, movCount, lastTurn);
        play = isWin(field, wcom, SIZE);
    }

    drawGameOver();
    setPos(29, 29);
    system("pause");
    }

////������� ������ � ������� �������

////������� ������ ������� �������
void showlederboard()
{

}

//��������� � ���� ����
void menuNav(bool& isgamerun)
{
    int idStep;
    idStep = _getch();
    
    //std::cout << idStep << '\n';
    ///L load - 108 || 76
    ///t leaderboard 116 || 84
    ///e exit (altf4) 101 || 69
    /// s save 115 || 83

    if (idStep == 27)
        isgamerun = false;
    else if (idStep == Move::Space)
        loadSave();
    else if (idStep == 116 || idStep == 84)
        showlederboard();
    else
        game();



}

//������� ����
void tagGame()
{
    bool isgamerun = true;

    while (isgamerun)
    {
        drawHiscreen();
        menuNav(isgamerun);
    } 
}