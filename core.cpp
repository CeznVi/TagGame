//// Игровой движок
#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>

//// Вызов функций из визуализации.срр
void drawGameField(const int* field, const int& SIZE, const int& movCount, int* lastTurn, int& min, int& sec);
void showbackground();
void drawGameOver();
void drawHiscreen();
void setPos(short X, short Y);
void drawSaveMessage();
void drawleadtable();

//обьявление таблици лидеров
struct Top5
{
    int mov = 1000;
    int min = 600;
    int sec = 59;
};

const int leadSIZE = 5;
Top5 Lead[leadSIZE];

//Cписок движения
enum Move {
    Up = 72,
    Down = 80,
    Left = 75,
    Rigth = 77,
    Space = 32,
    Esc = 27,
    Tab = 9,
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

////функция загрузки сохранения
void loadSave(int* field, const int& SIZE, int& movCount, int& min, int& sec)
{
    FILE* file;
    fopen_s(&file, "saved_game.txt", "r");
    if (!file)
    {
        std::cerr << "Error open file...";
        exit(1);
    }

    fread(field, sizeof(int), SIZE, file);
    fread(&movCount, sizeof(int), 1, file);
    fread(&min, sizeof(int), 1, file);
    fread(&sec, sizeof(int), 1, file);



    fclose(file);
}

////функция сделать сохранения игрового процесса
void saveGame(const int* field, const int& SIZE, int& movCount, int& min, int& sec)
{
    FILE* file;
    fopen_s(&file, "saved_game.txt", "w");
    if (!file) 
    {
            std::cerr << "Error open file...";
            exit(1);
    }

    fwrite(field, sizeof(int), SIZE, file);
    fwrite(&movCount, sizeof(int), 1, file);
    fwrite(&min, sizeof(int), 1, file);
    fwrite(&sec, sizeof(int), 1, file);

    if (fwrite != 0)
        drawSaveMessage();
    else
        std::cout << "Error";

    fclose(file);
}

//// Создать копию поля
void copyField(const int* field, int* copyField, const int& SIZE)
{
    for (int i{}; i < SIZE; ++i)
        copyField[i] = field[i];
}

////функция перемещения фишек
void move(int* field, const int& SIZE, int dir)
{
    int id0 = whereIs0(field, SIZE);

    int* tempArr = new int [SIZE] {};

    copyField(field, tempArr, SIZE);

    ////причина багов*
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

////сделать шаг
void doStep(int* field, const int& SIZE, int& movCount, int* lastTurn, bool& exitGame, int& min, int& sec)
{
    int dir;

    //std::cin >> dir;
    dir = _getch();

    int id0 = whereIs0(field, SIZE);

    //Проверка и защита от лома масива  
    if (dir == Move::Down && id0 < 4)
        return;
    else if (dir == Move::Up && id0 > 11)
        return;
    else if (dir == Move::Left && (id0 == 3 || id0 == 7 || id0 == 11 || id0 == 15))
        return;
    else if (dir == Move::Rigth && (id0 == 0 || id0 == 4 || id0 == 8 || id0 == 12))
        return;

    //сделать ход
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
        saveGame(field, SIZE, movCount, min, sec);
    else if (dir == Move::Esc)
        exitGame = true;


    copyField(field, lastTurn, SIZE);
}

////Проверить выграл игрок или нет
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

////Timer
void gameTimer(int& min, int& sec, bool play, bool exitGame, time_t& zerotime)
{
    if(((!play) && (!exitGame)))
        sec = time(0) - zerotime;

    if (sec == 60)
    {
        min += 1;
        zerotime += 60;
    }

   
}

////функция загрузки TOP5
void loadTop5(Top5* Lead, const int& leadSIZE)
{
    FILE* file;
    fopen_s(&file, "top5.txt", "r");
    if (!file)
    {
        std::cerr << "Error open file...";
        exit(1);
    }

    fread(Lead, sizeof(Top5), leadSIZE, file);
    fclose(file);
}

//// Сохранить ТОП5 в файл
void saveTop5(Top5* Lead, const int& leadSIZE)
{
    FILE* file;
    fopen_s(&file, "top5.txt", "w");
    if (!file)
    {
        std::cerr << "Error open file...";
        exit(1);
    }

    fwrite(Lead, sizeof(Top5), leadSIZE, file);
    fclose(file);
}

//
////////меняем местами значения в масиве
//void swap(int* arr, int left, int right)
//{
//	//// переменная временного буфера
//	int temp{};
//
//	if (left != right)
//	{
//		temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//	}
//}
//
////////условие сортировки от меньшего к большему
//bool isLeftLargeRight(int left, int right)
//{
//	return left > right;
//}
//
//////условие сортировки от большего к меньшему
//bool isLeftSmallRight(int left, int right)
//{
//	return left < right;
//}
//
///////// функция сортировки масива пузырьковым методом.
//void sorting(Top5* Lead, const int& leadSIZE, bool(*fn)(int,int))
//{
//	bool isFinish = false;
//	
//	////цикл сравнения елементов масива
//	do
//	{
//		isFinish = false;
//
//		for (int i{ 1 }; i < leadSIZE; i++)
//		{
//			if (fn(arr[i - 1], arr[i]))
//			{
//				swap(arr, i - 1, i);
//				isFinish = true;
//			}
//		}
//
//
//	} while (isFinish != false);
//}
//








////Функция записи в таблицу лидеров
void writeLeadtable(int& min, int& sec, int& movCount, Top5* Lead, const int& leadSIZE)
{
    loadTop5(Lead, leadSIZE);


    for (int i{}; i < leadSIZE; ++i)
    {
        if (((Lead[i].min > min) && (Lead[i].sec > sec)) && (Lead[i].mov > movCount))
        {
            Lead[i].min = min;
            Lead[i].sec = sec;
            Lead[i].mov = movCount;
            saveTop5(Lead, leadSIZE);
            break;
        }
        
    }
}

////Функция показа таблицы лидеров
void showlederboard()
{
    loadTop5(Lead, leadSIZE);
    drawleadtable();
    for (int i{}; i < leadSIZE; ++i)
    {
        setPos(44, 4 + i);
        std::cout << Lead[i].min << "\t\t" << Lead[i].sec << "\t" << Lead[i].mov;
    }
    setPos(40, 0);
    system("pause");
}

////Ф-ция игры (цикл)
void game(bool& load)
{
    const int SIZE = 16;
    ////переменные таймера
    int min{}, sec{};
    time_t zerotime = time(0);
    //// генерация рандомного поля
    //int* field = genereteField(SIZE);
    
    ///// Для дебага
    int* field = new int[SIZE] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0,15};

    //// победная комбинация
    const int* wcom = new int[SIZE] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    ////счетчик ходов
    int movCount{};

    ////хранение игрового поля до хода (для выполнения локальной отрисовки игр. поля) 
    int* lastTurn = new int[SIZE] {};

    bool play = false;
    bool exitGame = false;

    if (load == true)
    {
        loadSave(field, SIZE, movCount, min, sec);
        zerotime -= sec;
    }
    showbackground();
    
    drawGameField(field, SIZE, movCount, lastTurn, min, sec);

    while ((!play) && (!exitGame))
    {
        gameTimer(min, sec, play, exitGame, zerotime);
        doStep(field, SIZE, movCount, lastTurn, exitGame, min, sec);
        drawGameField(field, SIZE, movCount, lastTurn, min, sec);
        play = isWin(field, wcom, SIZE);
    }

    drawGameOver();
    setPos(29, 29);

        if(isWin(field, wcom, SIZE))
            writeLeadtable(min, sec, movCount, Lead, leadSIZE);

    system("pause");
    }

//навигация в майн меню
void menuNav(bool& isgamerun)
{
    int idStep;
    bool load = false;
    idStep = _getch();
    
    if (idStep == Move::Esc)
        isgamerun = false;
    else if (idStep == Move::Space)
    {
        load = true;
        game(load);
    }   
    else if (idStep == Move::Tab)
        showlederboard();
    else
        game(load);

}

//функция игры
void tagGame()
{
    bool isgamerun = true;
    while (isgamerun)
    {
        drawHiscreen();
        menuNav(isgamerun);
    } 
}